/*
 * MainWindow.cpp
 *
 *  Created on: Dec 1, 2008
 *      Author: Vincent
 */

#include "mainwindow.h"
#include <QtGui>
#include "labelcommentdialog.h"
#include "silodelegate.h"

//---------- public ----------//

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), findWidget(this) {
	setupUi(this);
	temporaryDuration = 3000;
	memset(isMulti, 0, ID_MAX * sizeof(bool));
	if (columnNames.size() != ID_MAX) {
		populateColumnNames();
	}
	if (unitNames.size() != UNIT_MAX) {
		populateUnitNames();
	}
	filter = new SiloFilter(this);

	linkEditors();

	setupShortcuts();
	setupConnections();
	setupEventFilters();
	setupAppearance();
	setupStatusBar();
	tableView->setItemDelegate(new SiloDelegate(tableView));

	filter->setSourceModel(&model);
	actionEnableSorting->setChecked(true);
	newFile();
}

void MainWindow::appendFilter(SiloFilter *filter) {
	filter->setSourceModel(&model);
	if (filters.size() > 0) {
		filters.last()->setSourceModel(filter);
	} else {
		this->filter->setSourceModel(filter);
	}
	filters.append(filter);
	undoFindButton->setEnabled(filter->rowCount() != model.rowCount());
	updateRowCount();
}

void MainWindow::clearFilters() {
	if (filters.size() > 0) {
		filter->setSourceModel(&model);
		for (int i = filters.size() - 1; i >= 0; --i) {
			delete filters[i];
		}
		filters.clear();
	}
	filter->setFilterType(FILTER_INVALID);
	filter->setFilterWildcard(QString());
	undoFindButton->setEnabled(false);
	updateRowCount();
}

//---------- protected ----------//

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent *keyEvent = (QKeyEvent *) event;
		if (watched == findEdit) {
			if (keyEvent->key() == Qt::Key_Escape) {
				if (findEdit->text().isEmpty()) {
					closeFindButton->click();
				} else {
					findEdit->clear();
				}
				return true;
			}
		} else if (watched == findDateTimeEdit | watched == findSizeSpin) {
			if (keyEvent->key() == Qt::Key_Return) {
				findButton->click();
				return true;
			}
		} else if (watched == tableView) {
			if (keyEvent->key() == Qt::Key_Delete) {
				del();
				return true;
			}
		}
	}
	return QMainWindow::eventFilter(watched, event);
}

//---------- private slots ----------//

void MainWindow::newFile() {
	clearModel();
	connectModel();
	updateRowCount();
}

bool MainWindow::save() {
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Data"),
			lastOpenedPath, tr("Silo Database (*.silodb)"));
	if (!fileName.isEmpty()) {
		lastOpenedPath = fileName;
		bool succ = saveFile(fileName);
		if (succ) {
			showTemporary(tr("Saving completed"));
		}
		return succ;
	}
	return false;
}

bool MainWindow::load() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Data"),
			lastOpenedPath, tr("Silo Database (*.silodb)"));
	if (!fileName.isEmpty()) {
		lastOpenedPath = fileName;
		disconnectModel();
		bool succ = false;
		if (fileName.endsWith(tr(".silodb"), Qt::CaseInsensitive)) {
			succ = loadSiloDatabase(fileName);
		} else {
			showError(tr("This type is currently not supported."));
		}
		connectModel();
		if (succ) {
			showTemporary(tr("Loading completed"));
		}
		updateRowCount();
		return succ;
	}
	return false;
}

void MainWindow::add() {
	QString dirName = QFileDialog::getExistingDirectory(this, tr("Add Entry"),
			lastOpenedPath);
	if (!dirName.isEmpty()) {
		lastOpenedPath = dirName;
		LabelCommentDialog d(this);
		d.exec();
		disconnectModel();
		addDir(dirName, dirName, d.getLabel(), d.getComment());
		connectModel();
	}
	showTemporary(tr("Entry added"));
	updateRowCount();
}

void MainWindow::del() {
	QList<int> rows;
	rowsSelectedSorted(rows);
	// Deleting starts backward to avoid invalid index
	if (rows.size() > 0) {
		for (int i = rows.size() - 1; i >= 0; --i) {
			filter->removeRow(rows[i]);
		}
	}
	updateRowCount();
}

void MainWindow::resizeColumns() {
	tableView->resizeColumnsToContents();
}

void MainWindow::resizeRows() {
	tableView->resizeRowsToContents();
}

void MainWindow::onFindTextChanged(const QString &text) {
	clearFindButton->setEnabled(!text.isEmpty());
}

void MainWindow::find() {
	int stackIndex = findStack->currentIndex();
	int index = findIdCombo->currentIndex();
	if (index == ID_MAX) {
		filter->setFilterKeyColumn(-1);
	} else {
		filter->setFilterKeyColumn(index);
	}
	if (stackIndex == FIND_TEXT) {
		QString findPattern = findEdit->text();
		if (!QRegExp(findPattern, Qt::CaseInsensitive, QRegExp::Wildcard).isValid()) {
			showTemporary(tr("The find wildcard is invalid"));
		} else {
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			filter->setFilterWildcard(findPattern);
		}
	} else if (stackIndex == FIND_DATE) {
		filter->setFilterDateTime(findDateTimeEdit->dateTime(), FilterType(
				findDateTypeCombo->currentIndex()));
		filter->setFilterWildcard(QString());
	} else if (stackIndex == FIND_SIZE) {
		filter->setFilterSize(getBytes(findSizeSpin->value(), UnitType(
				findUnitCombo->currentIndex())), FilterType(
				findSizeTypeCombo->currentIndex()));
		filter->setFilterWildcard(QString());
	}
	undoFindButton->setEnabled(filter->rowCount() != model.rowCount());
	updateRowCount();
}

void MainWindow::onSelectionChanged() {
	if (editGroup->isVisible()) {
		editGroup->setTitle(tr("%1 %2 selected").arg(selectionCount()).arg(
				selectionCount() > 1 ? tr("items") : tr("item")));
		updateEditors();
	}
}

void MainWindow::onLabelEdited() {
	updateModelFromEditor(ID_LABEL);
}

void MainWindow::onCommentEdited() {
	updateModelFromEditor(ID_COMMENT);
}

void MainWindow::onUndoFind() {
	clearFilters();
}

void MainWindow::enableSorting(bool enabled) {
	tableView->setSortingEnabled(enabled);
}

void MainWindow::onFindViewShown(bool shown) {
	if (shown) {
		findEdit->setFocus();
		findEdit->selectAll();
	}
}

void MainWindow::about() {
	QMessageBox::about(this, tr("About CD Silo"), tr("CD Silo 0.2"
		"\nA simple tool to have your disc data in hand."
		"\n"
		"\nWriten by Vincent."
		"\nIcons are from Oxygen and Qt."
		"\n"
		"\nThis program is provided \"AS IS\" with NO WARRANTY."
		"\nIf you find bugs, please contact me."));
}

void MainWindow::onFindTypeChanged(int index) {
	switch (index) {
	case ID_DATE:
		findStack->setCurrentIndex(FIND_DATE);
		break;
	case ID_SIZE:
		findStack->setCurrentIndex(FIND_SIZE);
		break;
	default:
		findStack->setCurrentIndex(FIND_TEXT);
		break;
	}
}

void MainWindow::onFindUnitChanged(int unit) {
	if (unit == UNIT_B) {
		findSizeSpin->setDecimals(0);
	} else {
		findSizeSpin->setDecimals(sizePrecision);
	}
}

void MainWindow::onAdvancedFind() {
	findWidget.show();
}

//---------- private ----------//

bool MainWindow::saveFile(const QString &fileName) {
	QFile file(fileName);
	if (file.open(QFile::WriteOnly)) {
		QDataStream stream(&file);
		stream.setVersion(dataStreamVersion);
		stream << dbHeader << dbVersion;
		int rows = model.rowCount();
		int columns = model.columnCount();
		stream << rows << columns;
		progress.setLabelText(tr("Saving \"%1\"").arg(fileName));
		progress.setMaximum(rows);
		progress.setModal(true);
		int row = 0;
		while (row < rows) {
			if (progress.wasCanceled()) {
				file.remove();
				return false;
			}
			for (int col = 0; col < columns; ++col) {
				stream << *(model.item(row, col));
			}
			progress.setValue(++row);
			qApp->processEvents();
		}
		return true;
	} else {
		showError(tr("Could not open file for writing: \"%1\".\n"
			"Error message: %2").arg(fileName).arg(file.errorString()));
	}
	return false;
}

bool MainWindow::loadSiloDatabase(const QString &fileName) {
	QFile file(fileName);
	if (file.open(QFile::ReadOnly)) {
		QDataStream stream(&file);
		stream.setVersion(dataStreamVersion);
		qint16 head, ver;
		stream >> head >> ver;
		if (head != dbHeader) {
			showError(tr("This is not a Silo database."
				"\nIt's probably corrupted, or "
				"simply not created by CD Silo."));
			return false;
		}
		if (ver == dbVersion) {
			int rows, columns;
			stream >> rows >> columns;
			if (columns != ID_MAX) {
				showError(tr("This is not a Silo database."
					"\nIt's probably corrupted, or "
					"simply not created by CD Silo."));
				return false;
			}
			model.setRowCount(rows);
			model.setColumnCount(columns);
			QStandardItem *item;
			progress.setLabelText(tr("Loading \"%1\"").arg(fileName));
			progress.setMaximum(rows);
			progress.setModal(true);
			int row = 0;
			while (row < rows) {
				if (progress.wasCanceled()) {
					return false;
				}
				for (int col = 0; col < columns; ++col) {
					item = new QStandardItem();
					stream >> *item;
					model.setItem(row, col, item);
				}
				progress.setValue(++row);
				qApp->processEvents();
			}
			return true;
		} else {
			showError(tr("The version is not supported by now."));
		}
	} else {
		showError(tr("Could not open file for reading: \"%1\".\n"
			"Error message: %2").arg(fileName).arg(file.errorString()));
	}
	return false;
}

void MainWindow::addDir(const QString &dirName, const QString &root,
		const QString &label, const QString &comment) {
	static int itemCount = 0;
	static int processed = 0;
	static int canceled = false;
	if (dirName == root) {
		itemCount = 0;
		processed = 0;
		canceled = false;
		progress.setModal(true);
	}
	QFileInfoList list = QDir(dirName).entryInfoList(QDir::NoDotAndDotDot
			| QDir::Hidden | QDir::System | QDir::AllEntries, QDir::DirsLast);
	int rows = list.size();
	itemCount += rows;
	QVariant itemData;
	QString fileName;
	QList<QStandardItem *> record;
	for (int i = 0; i < ID_MAX; ++i) {
		record.append(0);
	}
	progress.setMaximum(itemCount);
	progress.setLabelText(tr("Scanning \"%1\"").arg(dirName));
	for (int i = 0; i < rows; ++i) {
		if (progress.wasCanceled()) {
			canceled = true;
			break;
		}
		fileName = list[i].fileName();
		if (list[i].isDir() && !list[i].isSymLink()) {
			addDir(list[i].filePath(), root, label, comment);
			if (canceled) {
				break;
			}
		} else {
			for (int col = ID_MIN; col < ID_MAX; ++col) {
				switch (col) {
				case ID_PATH:
					itemData = list[i].path().mid(root.size()).append("/");
					break;
				case ID_NAME:
					itemData = fileName;
					break;
				case ID_LABEL:
					itemData = label;
					break;
				case ID_SIZE:
					itemData = list[i].size();
					break;
				case ID_DATE:
					itemData = list[i].lastModified();
					break;
				case ID_COMMENT:
					itemData = comment;
					break;
				case ID_TYPE:
					itemData = list[i].suffix();
					break;
				}
				record[col] = new QStandardItem();
				record[col]->setData(itemData, Qt::DisplayRole);
			}
			model.appendRow(record);
		}
		progress.setValue(++processed);
		qApp->processEvents();
	}
}

void MainWindow::showError(const QString &message) {
	QMessageBox::critical(this, tr("Error"), message);
}

void MainWindow::connectModel() {
	tableView->setModel(filter);
	connect(tableView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this,
			SLOT(onSelectionChanged()));
}

void MainWindow::disconnectModel() {
	tableView->setModel(0);
}

void MainWindow::clearModel() {
	model.clear();
	model.setColumnCount(ID_MAX);
	populateModelHeaders(&model);
	updateRowCount();
}

void MainWindow::showTemporary(const QString &message) {
	statusBar()->showMessage(message, temporaryDuration);
}

void MainWindow::rowsSelected(QList<int> &modelRows) {
	rowsFromSelection(modelRows, tableView->selectionModel());
}

void MainWindow::rowsSelectedSorted(QList<int> &modelRows) {
	rowsFromSelectionSorted(modelRows, tableView->selectionModel());
}

void MainWindow::updateEditors() {
	QList<int> rows;
	rowsSelected(rows);
	int count = rows.size();
	QDateTime minDateTime, maxDateTime;
	QString contents[ID_MAX];
	if (count > 0) {
		int firstRow = rows.first();
		qint64 sizeSum = 0;
		for (int col = ID_MIN; col < ID_MAX; ++col) {
			isMulti[col] = false;
			if (col == ID_SIZE) {
				sizeSum
						+= filter->index(firstRow, col).data(Qt::DisplayRole).toLongLong();
				contents[col] = stringFromSize(sizeSum);
				continue;
			} else if (col == ID_DATE) {
				minDateTime = maxDateTime = filter->index(firstRow, col).data(
						Qt::DisplayRole).toDateTime();
				contents[col] = minDateTime.toString(dateTimeFormat);
				continue;
			}
			contents[col]
					= filter->index(firstRow, col).data(Qt::DisplayRole).toString();
		}
		QDateTime recordDateTime;
		if (count == 1) {
			fileSizeLabel->setText(tr("&Size:"));
		} else {
			editors[ID_SIZE]->setText(tr("Calculating"));
			fileSizeLabel->setText(tr("Total &Size:"));
			for (int i = 1; i < count; ++i) {
				for (int col = ID_MIN; col < ID_MAX; ++col) {
					if (col == ID_SIZE) {
						sizeSum += filter->index(rows[i], col).data(
								Qt::DisplayRole).toLongLong();
						continue;
					} else if (col == ID_DATE) {
						recordDateTime = filter->index(rows[i], col).data(
								Qt::DisplayRole).toDateTime();
						if (recordDateTime > maxDateTime) {
							maxDateTime = recordDateTime;
						} else if (recordDateTime < minDateTime) {
							minDateTime = recordDateTime;
						}
						continue;
					}
					if (isMulti[col]) {
						continue;
					}
					if (filter->index(rows[i], col).data(Qt::DisplayRole).toString()
							!= contents[col]) {
						isMulti[col] = true;
						contents[col] = multivalueString;
					}
				}
			}
			contents[ID_SIZE] = stringFromSize(sizeSum);
			contents[ID_DATE]
					= maxDateTime == minDateTime ? maxDateTime.toString(
							dateTimeFormat) : tr("From %1 to %2").arg(
							minDateTime.toString(dateTimeFormat)).arg(
							maxDateTime.toString(dateTimeFormat));
		}
	} else {
		for (int i = ID_MIN; i < ID_MAX; ++i) {
			isMulti[i] = false;
		}
	}
	for (int i = ID_MIN; i < ID_MAX; ++i) {
		editors[i]->setText(contents[i]);
	}
}

void MainWindow::linkEditors() {
	editors[ID_NAME] = fileNameEdit;
	editors[ID_TYPE] = fileTypeEdit;
	editors[ID_DATE] = fileDateEdit;
	editors[ID_PATH] = filePathEdit;
	editors[ID_SIZE] = fileSizeEdit;
	editors[ID_LABEL] = fileLabelEdit;
	editors[ID_COMMENT] = fileCommentEdit;
}

void MainWindow::updateModelFromEditor(ColumnType editorId) {
	QString content = editors[editorId]->text();
	if (isMulti[editorId] && content == multivalueString) {
		return;
	}
	QList<int> rows;
	rowsSelected(rows);
	int size = rows.size();
	if (size > 0) {
		for (int i = size - 1; i >= 0; --i) {
			filter->setData(filter->index(rows[i], editorId),
					editors[editorId]->text(), Qt::DisplayRole);
		}
	}
}

void MainWindow::updateRowCount() {
	int shownRows = filter->rowCount();
	int modelRows = model.rowCount();
	rowCountLabel.setText(tr("%1 %2").arg(
			shownRows == modelRows ? QString::number(shownRows)
					: tr("%1/%2").arg(shownRows).arg(modelRows)).arg(shownRows
			> 1 ? tr("rows") : tr("row")));
}

void MainWindow::setupShortcuts() {
	actionExit->setShortcut(tr("Ctrl+Q"));
	actionEnableSorting->setShortcut(tr("Ctrl+T"));
	actionEditView->setShortcut(tr("Ctrl+E"));
	actionNew->setShortcut(QKeySequence::New);
	actionOpen->setShortcut(QKeySequence::Open);
	actionSave->setShortcut(QKeySequence::Save);
	actionFind->setShortcut(QKeySequence::Find);
}

void MainWindow::setupStatusBar() {
	QCheckBox *editCheck = new QCheckBox(this);
	editCheck->setText(tr("Editor View"));
	statusBar()->addPermanentWidget(&rowCountLabel);
	statusBar()->addPermanentWidget(editCheck);
	connect(editCheck, SIGNAL(toggled(bool)), actionEditView, SLOT(setChecked(bool)));
	connect(actionEditView, SIGNAL(toggled(bool)), editCheck, SLOT(setChecked(bool)));
}

void MainWindow::setupConnections() {
	connect(actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
	connect(actionOpen, SIGNAL(triggered()), this, SLOT(load()));
	connect(actionSave, SIGNAL(triggered()), this, SLOT(save()));
	connect(actionAdd, SIGNAL(triggered()), this, SLOT(add()));
	connect(actionDelete, SIGNAL(triggered()), this, SLOT(del()));
	connect(actionResizeColumns, SIGNAL(triggered()), this, SLOT(resizeColumns()));
	connect(actionResizeRows, SIGNAL(triggered()), this, SLOT(resizeRows()));
	connect(findButton, SIGNAL(clicked()), this, SLOT(find()));
	connect(findEdit, SIGNAL(textChanged(const QString &)), this, SLOT(onFindTextChanged(const QString &)));
	connect(fileLabelEdit, SIGNAL(editingFinished()), this, SLOT(onLabelEdited()));
	connect(fileCommentEdit, SIGNAL(editingFinished()), this, SLOT(onCommentEdited()));
	connect(undoFindButton, SIGNAL(clicked()), this, SLOT(onUndoFind()));
	connect(actionEnableSorting, SIGNAL(toggled(bool)), this, SLOT(enableSorting(bool)));
	connect(actionFind, SIGNAL(toggled(bool)), this, SLOT(onFindViewShown(bool)));
	connect(actionEditView, SIGNAL(toggled(bool)), this, SLOT(onSelectionChanged()));
	connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));
	connect(actionAboutQt, SIGNAL(triggered()),qApp, SLOT(aboutQt()));
	connect(findIdCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(onFindTypeChanged(int)));
	connect(findUnitCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(onFindUnitChanged(int)));
	connect(actionAdvancedFind, SIGNAL(triggered()), this, SLOT(onAdvancedFind()));
}

void MainWindow::setupEventFilters() {
	findEdit->installEventFilter(this);
	tableView->installEventFilter(this);
	findDateTimeEdit->installEventFilter(this);
	findSizeSpin->installEventFilter(this);
}

void MainWindow::setupAppearance() {
	populateColumnCombo(findIdCombo);
	populateUnitCombo(findUnitCombo);
	findIdCombo->insertItem(ID_MAX, tr("All"));
	findIdCombo->setCurrentIndex(ID_MAX);
	tableView->verticalHeader()->hide();
	editGroup->setVisible(actionEditView->isChecked());
	enableSorting(actionEnableSorting->isChecked());
	findBar->setVisible(actionFind->isChecked());
	clearFindButton->setEnabled(!findEdit->text().isEmpty());
	populateDateFilterCombo(findDateTypeCombo);
	populateSizeFilterCombo(findSizeTypeCombo);
	progress.setWindowTitle(tr("CD Silo"));
	findDateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

//---------- private static ----------//

void MainWindow::rowsFromSelection(QList<int> &modelRows,
		const QItemSelectionModel *selectionModel) {
	QModelIndexList indexes = selectionModel->selectedRows();
	modelRows.clear();
	for (int i = indexes.size() - 1; i >= 0; --i) {
		modelRows.append(indexes[i].row());
	}
}

void MainWindow::rowsFromSelectionSorted(QList<int> &modelRows,
		const QItemSelectionModel *selectionModel) {
	rowsFromSelection(modelRows, selectionModel);
	qSort(modelRows);
}
