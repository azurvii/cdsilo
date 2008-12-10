/*
 * silodelegate.cpp
 *
 *  Created on: Dec 10, 2008
 *      Author: Vincent
 */

#include "silodelegate.h"
#include "mainwindow.h"

SiloDelegate::SiloDelegate(QObject *parent) :
	QStyledItemDelegate(parent) {
}

QWidget *SiloDelegate::createEditor(QWidget *parent,
		const QStyleOptionViewItem &, const QModelIndex &index) const {
	switch (index.column()) {
	case MainWindow::ID_LABEL:
	case MainWindow::ID_COMMENT:
		return new QLineEdit(parent);
		//	case MainWindow::ID_NAME:
		//	case MainWindow::ID_PATH:
		//	case MainWindow::ID_SIZE:
		//	case MainWindow::ID_DATE:
		//	case MainWindow::ID_TYPE:
	default:
		return 0;
	}
}

void SiloDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
	switch (index.column()) {
	case MainWindow::ID_LABEL:
	case MainWindow::ID_COMMENT:
		((QLineEdit *) editor)->setText(index.data(Qt::DisplayRole).toString());
		return;
		//	case MainWindow::ID_NAME:
		//	case MainWindow::ID_PATH:
		//	case MainWindow::ID_SIZE:
		//	case MainWindow::ID_DATE:
		//	case MainWindow::ID_TYPE:
		//	default:
		//		return;
	}
}
void SiloDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const {
	switch (index.column()) {
	case MainWindow::ID_LABEL:
	case MainWindow::ID_COMMENT:
		model->setData(index, ((QLineEdit*) editor)->text(), Qt::DisplayRole);
		return;
		//	case MainWindow::ID_NAME:
		//	case MainWindow::ID_PATH:
		//	case MainWindow::ID_SIZE:
		//	case MainWindow::ID_DATE:
		//	case MainWindow::ID_TYPE:
		//	default:
		//		return;
	}
}

void SiloDelegate::updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const {
	editor->setGeometry(option.rect);
}
