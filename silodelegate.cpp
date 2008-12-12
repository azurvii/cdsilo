/*
 * silodelegate.cpp
 *
 *  Created on: Dec 10, 2008
 *      Author: Vincent
 */

#include "silodelegate.h"
#include "common.h"
#include <QLineEdit>
using namespace Silo;

SiloDelegate::SiloDelegate(QObject *parent) :
	QStyledItemDelegate(parent) {
}

QWidget *SiloDelegate::createEditor(QWidget *parent,
		const QStyleOptionViewItem &, const QModelIndex &index) const {
	switch (index.column()) {
	case ID_LABEL:
	case ID_COMMENT:
		return new QLineEdit(parent);
	default:
		return 0;
	}
}

void SiloDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
	switch (index.column()) {
	case ID_LABEL:
	case ID_COMMENT:
		((QLineEdit *) editor)->setText(index.data(Qt::DisplayRole).toString());
		return;
	}
}
void SiloDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const {
	switch (index.column()) {
	case ID_LABEL:
	case ID_COMMENT:
		model->setData(index, ((QLineEdit*) editor)->text(), Qt::DisplayRole);
		return;
	}
}

void SiloDelegate::updateEditorGeometry(QWidget *editor,
		const QStyleOptionViewItem &option, const QModelIndex &index) const {
	editor->setGeometry(option.rect);
}
