/*
 * findwidget.h
 *
 *  Created on: Dec 11, 2008
 *      Author: Vincent
 */

#ifndef FINDWIDGET_H_
#define FINDWIDGET_H_

#include "ui_findwidget.h"
#include <QDialog>
class MainWindow;

class FindWidget: public QDialog, private Ui::FindWidget {
Q_OBJECT
public:
	FindWidget(MainWindow *parent = 0);

private:
	static void populateSizeCombo(QComboBox *combo);
	static void populateDateCombo(QComboBox *combo);

private slots:
	void onDateFilterChanged(int index);
	void onSizeFilterChanged(int index);
	void onSizeUnitChanged(int unit);
	void onSizeToUnitChanged(int unit);
	void onFind();
	void onClear();

private:
	void setupAppearance();
	void setupConnections();
};

#endif /* FINDWIDGET_H_ */
