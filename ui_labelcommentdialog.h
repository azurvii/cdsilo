/********************************************************************************
** Form generated from reading ui file 'labelcommentdialog.ui'
**
** Created: Wed Dec 10 13:26:33 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LABELCOMMENTDIALOG_H
#define UI_LABELCOMMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LabelCommentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *labelEdit;
    QLabel *label_2;
    QLineEdit *commentEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *LabelCommentDialog)
    {
    if (LabelCommentDialog->objectName().isEmpty())
        LabelCommentDialog->setObjectName(QString::fromUtf8("LabelCommentDialog"));
    LabelCommentDialog->resize(264, 100);
    verticalLayout = new QVBoxLayout(LabelCommentDialog);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
    formLayout = new QFormLayout();
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    label = new QLabel(LabelCommentDialog);
    label->setObjectName(QString::fromUtf8("label"));

    formLayout->setWidget(0, QFormLayout::LabelRole, label);

    labelEdit = new QLineEdit(LabelCommentDialog);
    labelEdit->setObjectName(QString::fromUtf8("labelEdit"));

    formLayout->setWidget(0, QFormLayout::FieldRole, labelEdit);

    label_2 = new QLabel(LabelCommentDialog);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

    commentEdit = new QLineEdit(LabelCommentDialog);
    commentEdit->setObjectName(QString::fromUtf8("commentEdit"));

    formLayout->setWidget(1, QFormLayout::FieldRole, commentEdit);


    verticalLayout->addLayout(formLayout);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_3 = new QLabel(LabelCommentDialog);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    horizontalLayout->addWidget(label_3);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    pushButton = new QPushButton(LabelCommentDialog);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setDefault(true);

    horizontalLayout->addWidget(pushButton);


    verticalLayout->addLayout(horizontalLayout);


#ifndef QT_NO_SHORTCUT
    label->setBuddy(labelEdit);
    label_2->setBuddy(commentEdit);
#endif // QT_NO_SHORTCUT


    retranslateUi(LabelCommentDialog);
    QObject::connect(pushButton, SIGNAL(clicked()), LabelCommentDialog, SLOT(accept()));

    QMetaObject::connectSlotsByName(LabelCommentDialog);
    } // setupUi

    void retranslateUi(QDialog *LabelCommentDialog)
    {
    label->setText(QApplication::translate("LabelCommentDialog", "&Label the disc:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("LabelCommentDialog", "&Comment on items:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("LabelCommentDialog", "Leave blank if you wish.", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("LabelCommentDialog", "OK", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(LabelCommentDialog);
    } // retranslateUi

};

namespace Ui {
    class LabelCommentDialog: public Ui_LabelCommentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELCOMMENTDIALOG_H
