/*
 * labelcommentdialog.h
 *
 *  Created on: Dec 8, 2008
 *      Author: Vincent
 */

#ifndef LABELCOMMENTDIALOG_H_
#define LABELCOMMENTDIALOG_H_

#include "ui_labelcommentdialog.h"

class LabelCommentDialog: public QDialog, private Ui::LabelCommentDialog {
Q_OBJECT
public:
	LabelCommentDialog(QWidget *parent = 0);
	QString getLabel() {
		return labelEdit->text();
	}
	QString getComment() {
		return commentEdit->text();
	}
};

#endif /* LABELCOMMENTDIALOG_H_ */
