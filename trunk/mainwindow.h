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
#include "common.h"
using namespace Silo;

class MainWindow: public QMainWindow, private Ui::MainWindow {
Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	void appendFilter(SiloFilter *filter);
	void clearFilters();

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
	void onLanguageChanged();

private:
	bool saveFile(const QString &fileName);
	bool loadSiloDatabase(const QString &fileName);
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
	QActionGroup *languages;
};

#endif /* MAINWINDOW_H_ */
