/*
 * silodelegate.h
 *
 *  Created on: Dec 10, 2008
 *      Author: Vincent
 */

#ifndef SILODELEGATE_H_
#define SILODELEGATE_H_

#include <QStyledItemDelegate>

class SiloDelegate: public QStyledItemDelegate {
Q_OBJECT
public:
	SiloDelegate(QObject *parent = 0);
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
			const QModelIndex &index) const;
	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
			const QModelIndex &index) const;
	void updateEditorGeometry(QWidget *editor,
			const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif /* SILODELEGATE_H_ */
