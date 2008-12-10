/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Dec 10 17:27:16 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionEditView;
    QAction *actionFindView;
    QAction *actionAdd;
    QAction *actionDelete;
    QAction *actionResizeView;
    QAction *actionEnableSorting;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *findWidget;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *closeFindButton;
    QLabel *label_8;
    QComboBox *findIdCombo;
    QStackedWidget *findStack;
    QWidget *textPage;
    QHBoxLayout *horizontalLayout;
    QToolButton *clearFindButton;
    QLineEdit *findEdit;
    QWidget *timePage;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *findDateTypeCombo;
    QDateTimeEdit *findDateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QWidget *sizePage;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *findSizeTypeCombo;
    QDoubleSpinBox *findSizeSpin;
    QComboBox *findUnitCombo;
    QToolButton *findButton;
    QToolButton *undoFindButton;
    QTableView *tableView;
    QGroupBox *editGroup;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *fileNameEdit;
    QLabel *label_9;
    QLineEdit *fileTypeEdit;
    QLabel *label_2;
    QLineEdit *filePathEdit;
    QLabel *fileSizeLabel;
    QLineEdit *fileSizeEdit;
    QLabel *label_6;
    QLineEdit *fileDateEdit;
    QLabel *label_4;
    QLineEdit *fileLabelEdit;
    QLabel *label_5;
    QLineEdit *fileCommentEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(686, 620);
    actionNew = new QAction(MainWindow);
    actionNew->setObjectName(QString::fromUtf8("actionNew"));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/images/filenew.png")), QIcon::Normal, QIcon::Off);
    actionNew->setIcon(icon);
    actionOpen = new QAction(MainWindow);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/fileopen.png")), QIcon::Normal, QIcon::Off);
    actionOpen->setIcon(icon1);
    actionSave = new QAction(MainWindow);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/filesave.png")), QIcon::Normal, QIcon::Off);
    actionSave->setIcon(icon2);
    actionExit = new QAction(MainWindow);
    actionExit->setObjectName(QString::fromUtf8("actionExit"));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/images/application_exit.png")), QIcon::Normal, QIcon::Off);
    actionExit->setIcon(icon3);
    actionEditView = new QAction(MainWindow);
    actionEditView->setObjectName(QString::fromUtf8("actionEditView"));
    actionEditView->setCheckable(true);
    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/images/edit.png")), QIcon::Normal, QIcon::Off);
    actionEditView->setIcon(icon4);
    actionFindView = new QAction(MainWindow);
    actionFindView->setObjectName(QString::fromUtf8("actionFindView"));
    actionFindView->setCheckable(true);
    QIcon icon5;
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/images/find.png")), QIcon::Normal, QIcon::Off);
    actionFindView->setIcon(icon5);
    actionAdd = new QAction(MainWindow);
    actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
    QIcon icon6;
    icon6.addPixmap(QPixmap(QString::fromUtf8(":/images/edit_add.png")), QIcon::Normal, QIcon::Off);
    actionAdd->setIcon(icon6);
    actionDelete = new QAction(MainWindow);
    actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
    QIcon icon7;
    icon7.addPixmap(QPixmap(QString::fromUtf8(":/images/editdelete.png")), QIcon::Normal, QIcon::Off);
    actionDelete->setIcon(icon7);
    actionResizeView = new QAction(MainWindow);
    actionResizeView->setObjectName(QString::fromUtf8("actionResizeView"));
    QIcon icon8;
    icon8.addPixmap(QPixmap(QString::fromUtf8(":/images/table.png")), QIcon::Normal, QIcon::Off);
    actionResizeView->setIcon(icon8);
    actionEnableSorting = new QAction(MainWindow);
    actionEnableSorting->setObjectName(QString::fromUtf8("actionEnableSorting"));
    actionEnableSorting->setCheckable(true);
    QIcon icon9;
    icon9.addPixmap(QPixmap(QString::fromUtf8(":/images/next.png")), QIcon::Normal, QIcon::Off);
    actionEnableSorting->setIcon(icon9);
    actionAbout = new QAction(MainWindow);
    actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
    QIcon icon10;
    icon10.addPixmap(QPixmap(QString::fromUtf8(":/images/help_about.png")), QIcon::Normal, QIcon::Off);
    actionAbout->setIcon(icon10);
    actionAboutQt = new QAction(MainWindow);
    actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
    QIcon icon11;
    icon11.addPixmap(QPixmap(QString::fromUtf8(":/images/qt-cube.png")), QIcon::Normal, QIcon::Off);
    actionAboutQt->setIcon(icon11);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    findWidget = new QWidget(centralwidget);
    findWidget->setObjectName(QString::fromUtf8("findWidget"));
    horizontalLayout_3 = new QHBoxLayout(findWidget);
    horizontalLayout_3->setSpacing(1);
    horizontalLayout_3->setMargin(0);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    closeFindButton = new QToolButton(findWidget);
    closeFindButton->setObjectName(QString::fromUtf8("closeFindButton"));
    QIcon icon12;
    icon12.addPixmap(QPixmap(QString::fromUtf8(":/images/dialog_close.png")), QIcon::Normal, QIcon::Off);
    closeFindButton->setIcon(icon12);
    closeFindButton->setAutoRaise(true);

    horizontalLayout_3->addWidget(closeFindButton);

    label_8 = new QLabel(findWidget);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    horizontalLayout_3->addWidget(label_8);

    findIdCombo = new QComboBox(findWidget);
    findIdCombo->setObjectName(QString::fromUtf8("findIdCombo"));

    horizontalLayout_3->addWidget(findIdCombo);

    findStack = new QStackedWidget(findWidget);
    findStack->setObjectName(QString::fromUtf8("findStack"));
    textPage = new QWidget();
    textPage->setObjectName(QString::fromUtf8("textPage"));
    horizontalLayout = new QHBoxLayout(textPage);
    horizontalLayout->setSpacing(1);
    horizontalLayout->setMargin(0);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    clearFindButton = new QToolButton(textPage);
    clearFindButton->setObjectName(QString::fromUtf8("clearFindButton"));
    QIcon icon13;
    icon13.addPixmap(QPixmap(QString::fromUtf8(":/images/locationbar_erase.png")), QIcon::Normal, QIcon::Off);
    clearFindButton->setIcon(icon13);
    clearFindButton->setAutoRaise(true);

    horizontalLayout->addWidget(clearFindButton);

    findEdit = new QLineEdit(textPage);
    findEdit->setObjectName(QString::fromUtf8("findEdit"));

    horizontalLayout->addWidget(findEdit);

    findStack->addWidget(textPage);
    timePage = new QWidget();
    timePage->setObjectName(QString::fromUtf8("timePage"));
    horizontalLayout_2 = new QHBoxLayout(timePage);
    horizontalLayout_2->setSpacing(1);
    horizontalLayout_2->setMargin(0);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    findDateTypeCombo = new QComboBox(timePage);
    findDateTypeCombo->setObjectName(QString::fromUtf8("findDateTypeCombo"));

    horizontalLayout_2->addWidget(findDateTypeCombo);

    findDateTimeEdit = new QDateTimeEdit(timePage);
    findDateTimeEdit->setObjectName(QString::fromUtf8("findDateTimeEdit"));
    findDateTimeEdit->setCalendarPopup(true);

    horizontalLayout_2->addWidget(findDateTimeEdit);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer);

    findStack->addWidget(timePage);
    sizePage = new QWidget();
    sizePage->setObjectName(QString::fromUtf8("sizePage"));
    horizontalLayout_4 = new QHBoxLayout(sizePage);
    horizontalLayout_4->setSpacing(1);
    horizontalLayout_4->setMargin(0);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    findSizeTypeCombo = new QComboBox(sizePage);
    findSizeTypeCombo->setObjectName(QString::fromUtf8("findSizeTypeCombo"));

    horizontalLayout_4->addWidget(findSizeTypeCombo);

    findSizeSpin = new QDoubleSpinBox(sizePage);
    findSizeSpin->setObjectName(QString::fromUtf8("findSizeSpin"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(findSizeSpin->sizePolicy().hasHeightForWidth());
    findSizeSpin->setSizePolicy(sizePolicy);
    findSizeSpin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    findSizeSpin->setMaximum(1e+09);

    horizontalLayout_4->addWidget(findSizeSpin);

    findUnitCombo = new QComboBox(sizePage);
    findUnitCombo->setObjectName(QString::fromUtf8("findUnitCombo"));

    horizontalLayout_4->addWidget(findUnitCombo);

    findStack->addWidget(sizePage);

    horizontalLayout_3->addWidget(findStack);

    findButton = new QToolButton(findWidget);
    findButton->setObjectName(QString::fromUtf8("findButton"));
    findButton->setIcon(icon5);
    findButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    horizontalLayout_3->addWidget(findButton);

    undoFindButton = new QToolButton(findWidget);
    undoFindButton->setObjectName(QString::fromUtf8("undoFindButton"));
    undoFindButton->setEnabled(false);
    QIcon icon14;
    icon14.addPixmap(QPixmap(QString::fromUtf8(":/images/undo.png")), QIcon::Normal, QIcon::Off);
    undoFindButton->setIcon(icon14);
    undoFindButton->setAutoRaise(true);

    horizontalLayout_3->addWidget(undoFindButton);


    verticalLayout->addWidget(findWidget);

    tableView = new QTableView(centralwidget);
    tableView->setObjectName(QString::fromUtf8("tableView"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(1);
    sizePolicy1.setVerticalStretch(1);
    sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
    tableView->setSizePolicy(sizePolicy1);
    tableView->setAlternatingRowColors(true);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

    verticalLayout->addWidget(tableView);

    editGroup = new QGroupBox(centralwidget);
    editGroup->setObjectName(QString::fromUtf8("editGroup"));
    formLayout = new QFormLayout(editGroup);
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    label = new QLabel(editGroup);
    label->setObjectName(QString::fromUtf8("label"));

    formLayout->setWidget(0, QFormLayout::LabelRole, label);

    fileNameEdit = new QLineEdit(editGroup);
    fileNameEdit->setObjectName(QString::fromUtf8("fileNameEdit"));
    QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(2);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(fileNameEdit->sizePolicy().hasHeightForWidth());
    fileNameEdit->setSizePolicy(sizePolicy2);
    fileNameEdit->setFrame(false);
    fileNameEdit->setReadOnly(true);

    formLayout->setWidget(0, QFormLayout::FieldRole, fileNameEdit);

    label_9 = new QLabel(editGroup);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    formLayout->setWidget(1, QFormLayout::LabelRole, label_9);

    fileTypeEdit = new QLineEdit(editGroup);
    fileTypeEdit->setObjectName(QString::fromUtf8("fileTypeEdit"));
    QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy3.setHorizontalStretch(1);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(fileTypeEdit->sizePolicy().hasHeightForWidth());
    fileTypeEdit->setSizePolicy(sizePolicy3);
    fileTypeEdit->setFrame(false);
    fileTypeEdit->setReadOnly(true);

    formLayout->setWidget(1, QFormLayout::FieldRole, fileTypeEdit);

    label_2 = new QLabel(editGroup);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

    filePathEdit = new QLineEdit(editGroup);
    filePathEdit->setObjectName(QString::fromUtf8("filePathEdit"));
    filePathEdit->setFrame(false);
    filePathEdit->setReadOnly(true);

    formLayout->setWidget(2, QFormLayout::FieldRole, filePathEdit);

    fileSizeLabel = new QLabel(editGroup);
    fileSizeLabel->setObjectName(QString::fromUtf8("fileSizeLabel"));

    formLayout->setWidget(3, QFormLayout::LabelRole, fileSizeLabel);

    fileSizeEdit = new QLineEdit(editGroup);
    fileSizeEdit->setObjectName(QString::fromUtf8("fileSizeEdit"));
    fileSizeEdit->setFrame(false);
    fileSizeEdit->setReadOnly(true);

    formLayout->setWidget(3, QFormLayout::FieldRole, fileSizeEdit);

    label_6 = new QLabel(editGroup);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

    fileDateEdit = new QLineEdit(editGroup);
    fileDateEdit->setObjectName(QString::fromUtf8("fileDateEdit"));
    fileDateEdit->setFrame(false);
    fileDateEdit->setReadOnly(true);

    formLayout->setWidget(4, QFormLayout::FieldRole, fileDateEdit);

    label_4 = new QLabel(editGroup);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

    fileLabelEdit = new QLineEdit(editGroup);
    fileLabelEdit->setObjectName(QString::fromUtf8("fileLabelEdit"));

    formLayout->setWidget(5, QFormLayout::FieldRole, fileLabelEdit);

    label_5 = new QLabel(editGroup);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

    fileCommentEdit = new QLineEdit(editGroup);
    fileCommentEdit->setObjectName(QString::fromUtf8("fileCommentEdit"));

    formLayout->setWidget(6, QFormLayout::FieldRole, fileCommentEdit);


    verticalLayout->addWidget(editGroup);

    MainWindow->setCentralWidget(centralwidget);
    tableView->raise();
    findWidget->raise();
    editGroup->raise();
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 686, 19));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuView = new QMenu(menubar);
    menuView->setObjectName(QString::fromUtf8("menuView"));
    menuEdit = new QMenu(menubar);
    menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

#ifndef QT_NO_SHORTCUT
    label->setBuddy(fileNameEdit);
    label_9->setBuddy(fileTypeEdit);
    label_2->setBuddy(filePathEdit);
    fileSizeLabel->setBuddy(fileSizeEdit);
    label_6->setBuddy(fileDateEdit);
    label_4->setBuddy(fileLabelEdit);
    label_5->setBuddy(fileCommentEdit);
#endif // QT_NO_SHORTCUT

    QWidget::setTabOrder(tableView, fileNameEdit);
    QWidget::setTabOrder(fileNameEdit, fileTypeEdit);
    QWidget::setTabOrder(fileTypeEdit, filePathEdit);
    QWidget::setTabOrder(filePathEdit, fileSizeEdit);
    QWidget::setTabOrder(fileSizeEdit, fileDateEdit);
    QWidget::setTabOrder(fileDateEdit, fileLabelEdit);
    QWidget::setTabOrder(fileLabelEdit, fileCommentEdit);
    QWidget::setTabOrder(fileCommentEdit, closeFindButton);
    QWidget::setTabOrder(closeFindButton, clearFindButton);
    QWidget::setTabOrder(clearFindButton, findIdCombo);
    QWidget::setTabOrder(findIdCombo, findEdit);
    QWidget::setTabOrder(findEdit, findDateTypeCombo);
    QWidget::setTabOrder(findDateTypeCombo, findDateTimeEdit);
    QWidget::setTabOrder(findDateTimeEdit, findSizeSpin);
    QWidget::setTabOrder(findSizeSpin, findUnitCombo);
    QWidget::setTabOrder(findUnitCombo, findButton);
    QWidget::setTabOrder(findButton, undoFindButton);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuEdit->menuAction());
    menubar->addAction(menuView->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menuFile->addAction(actionNew);
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionSave);
    menuFile->addSeparator();
    menuFile->addAction(actionExit);
    menuView->addAction(actionEditView);
    menuView->addAction(actionFindView);
    menuView->addSeparator();
    menuView->addAction(actionResizeView);
    menuEdit->addAction(actionAdd);
    menuEdit->addAction(actionDelete);
    menuEdit->addSeparator();
    menuEdit->addAction(actionEnableSorting);
    menuHelp->addAction(actionAbout);
    menuHelp->addAction(actionAboutQt);

    retranslateUi(MainWindow);
    QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
    QObject::connect(actionEditView, SIGNAL(toggled(bool)), editGroup, SLOT(setVisible(bool)));
    QObject::connect(actionFindView, SIGNAL(toggled(bool)), findWidget, SLOT(setVisible(bool)));
    QObject::connect(closeFindButton, SIGNAL(clicked()), actionFindView, SLOT(toggle()));
    QObject::connect(clearFindButton, SIGNAL(clicked()), findEdit, SLOT(clear()));
    QObject::connect(findEdit, SIGNAL(returnPressed()), findButton, SLOT(click()));

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CD Silo", 0, QApplication::UnicodeUTF8));
    actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionNew->setStatusTip(QApplication::translate("MainWindow", "Create a new data set", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionOpen->setText(QApplication::translate("MainWindow", "Open...", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionOpen->setStatusTip(QApplication::translate("MainWindow", "Continue a previous data set", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionSave->setStatusTip(QApplication::translate("MainWindow", "Save current data set", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionExit->setStatusTip(QApplication::translate("MainWindow", "Exit this program", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionEditView->setText(QApplication::translate("MainWindow", "Edit View", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionEditView->setStatusTip(QApplication::translate("MainWindow", "Show Edit View to modify data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionFindView->setText(QApplication::translate("MainWindow", "Find View", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionFindView->setStatusTip(QApplication::translate("MainWindow", "Show Find View to find specific data with wildcard format", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionAdd->setText(QApplication::translate("MainWindow", "Add entry", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionAdd->setStatusTip(QApplication::translate("MainWindow", "Add an entry to current data set", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionDelete->setStatusTip(QApplication::translate("MainWindow", "Delete selected records", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionResizeView->setText(QApplication::translate("MainWindow", "Auto resize cells", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionResizeView->setStatusTip(QApplication::translate("MainWindow", "Set cell sizes to fit their contents", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionEnableSorting->setText(QApplication::translate("MainWindow", "Enable sorting", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    actionEnableSorting->setStatusTip(QApplication::translate("MainWindow", "Enable in-table sorting", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
    closeFindButton->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("MainWindow", "Find in ", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    clearFindButton->setStatusTip(QApplication::translate("MainWindow", "Clear find text", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    clearFindButton->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
    findButton->setText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    undoFindButton->setStatusTip(QApplication::translate("MainWindow", "Back to original data set", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    undoFindButton->setText(QApplication::translate("MainWindow", "Revert", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "&Name:", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("MainWindow", "&Type:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "&Path:", 0, QApplication::UnicodeUTF8));
    fileSizeLabel->setText(QApplication::translate("MainWindow", "&Size:", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("MainWindow", "Last &Modified:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "&Label:", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainWindow", "&Comment:", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
    menuView->setTitle(QApplication::translate("MainWindow", "&View", 0, QApplication::UnicodeUTF8));
    menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
    menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
