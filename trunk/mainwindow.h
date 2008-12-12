/*
 * MainWindow.h
 *
 *  Created on: Dec 1, 2008
 *      Author: Vincent
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include "silofilter.h"
#include <QProgressDialog>
#include "findwidget.h"
#include <QList>

class MainWindow: public QMainWindow, private Ui::MainWindow {
Q_OBJECT
public:
	enum ColumnType {
		ID_LABEL = 0,
		ID_NAME = 1,
		ID_PATH = 2,
		ID_TYPE = 3,
		ID_SIZE = 4,
		ID_DATE = 5,
		ID_COMMENT = 6,
		ID_MAX = 7,
		ID_MIN = 0
	};
	enum FindPage {
		FIND_TEXT = 0, FIND_DATE = 1, FIND_SIZE = 2
	};
	enum UnitType {
		UNIT_B = 0,
		UNIT_KB = 1,
		UNIT_MB = 2,
		UNIT_GB = 3,
		UNIT_TB = 4,
		UNIT_PB = 5,
		UNIT_MAX = 6,
		UNIT_MIN = 0
	};

public:
	MainWindow(QWidget *parent = 0);
	void appendFilter(SiloFilter *filter);
	void clearFilters();

public:
	static QString getUnitName(UnitType unitId) {
		return unitNames[unitId];
	}
	static void populateUnitCombo(QComboBox *combo);
	static qint64 getBytes(double displayValue, UnitType unit);
	static QString stringFromSize(qint64 size, int precision = sizeDecimal);
	static void populateDateFilterCombo(QComboBox *combo);
	static void populateSizeFilterCombo(QComboBox *combo);
	static int sizePrecision() {
		return sizeDecimal;
	}

protected:
	bool eventFilter(QObject *watched, QEvent *event);

private slots:
	void newFile();
	bool save();
	bool load();
	void add();
	void del();
	void resizeColumns();
	void resizeRows();
	void onFindTextChanged(const QString &text);
	void find();
	void onSelectionChanged();
	void onLabelEdited();
	void onCommentEdited();
	void onUndoFind();
	void enableSorting(bool enabled);
	void onFindViewShown(bool shown);
	void about();
	void onFindTypeChanged(int index);
	void onFindUnitChanged(int unit);
	void onAdvancedFind();

private:
	bool saveFile(const QString &fileName);
	bool loadSiloDatabase(const QString &fileName);
	//	bool loadCSV(const QString &fileName);
	void addDir(const QString &dirName, const QString &root,
			const QString &label = QString(), const QString &comment =
					QString());
	void showError(const QString &message);
	void connectModel();
	void disconnectModel();
	void clearModel();
	void showTemporary(const QString &message);
	void rowsSelected(QList<int> &rows);
	void rowsSelectedSorted(QList<int> &rows);
	void updateEditors();
	void linkEditors();
	void updateModelFromEditor(ColumnType editorId);
	void updateRowCount();
	void setupShortcuts();
	void setupStatusBar();
	void setupConnections();
	void setupEventFilters();
	void setupAppearance();
	int selectionCount() {
		return tableView->selectionModel()->selectedRows().size();
	}

private:
	static void rowsFromSelection(QList<int> &rows,
			const QItemSelectionModel *selectionModel);
	static void rowsFromSelectionSorted(QList<int> &rows,
			const QItemSelectionModel *selectionModel);
	static void populateColumnCombo(QComboBox *combo);
	static void populateColumnNames();
	static void populateUnitNames();
	static void populateModelHeaders(QAbstractItemModel *model);

private:
	QStandardItemModel model;
	SiloFilter *filter;
	QList<SiloFilter *> filters;
	int temporaryDuration;
	QLineEdit *( editors[ID_MAX]);
	QString lastOpenedPath;
	QProgressDialog progress;
	QLabel rowCountLabel;
	bool isMulti[ID_MAX];
	FindWidget findWidget;

private:
	static const qint16 dbVersion;
	static const qint16 dbHeader;
	static const int dataStreamVersion;
	static const QString dateTimeFormat;
	static QHash<int, QString> columnNames;
	static QHash<int, QString> unitNames;
	static const QString multivalueString;
	static const int sizeDecimal;
};

#endif /* MAINWINDOW_H_ */
