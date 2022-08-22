/********************************************************************************
** Form generated from reading UI file 'testboard.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTBOARD_H
#define UI_TESTBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestBoard
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QLabel *label_pic;
    QCheckBox *cb_rd53a;
    QPushButton *show_board;
    QCheckBox *cb_rd53b_a;
    QCheckBox *cb_rd53b_b;
    QCheckBox *cb_rd53b_c;
    QCheckBox *cb_linereg_vol;
    QCheckBox *cb_loadreg;
    QCheckBox *cb_linereg_curr;
    QCheckBox *cb_start_ramp;
    QLabel *label_29;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestBoard)
    {
        if (TestBoard->objectName().isEmpty())
            TestBoard->setObjectName(QStringLiteral("TestBoard"));
        TestBoard->resize(788, 600);
        actionExit = new QAction(TestBoard);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/close-button-icon-8.jpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralwidget = new QWidget(TestBoard);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setGeometry(QRect(190, 140, 400, 400));
        cb_rd53a = new QCheckBox(centralwidget);
        cb_rd53a->setObjectName(QStringLiteral("cb_rd53a"));
        cb_rd53a->setGeometry(QRect(10, 20, 181, 22));
        cb_rd53a->setChecked(false);
        show_board = new QPushButton(centralwidget);
        show_board->setObjectName(QStringLiteral("show_board"));
        show_board->setEnabled(true);
        show_board->setGeometry(QRect(210, 50, 91, 27));
        cb_rd53b_a = new QCheckBox(centralwidget);
        cb_rd53b_a->setObjectName(QStringLiteral("cb_rd53b_a"));
        cb_rd53b_a->setGeometry(QRect(10, 40, 181, 22));
        cb_rd53b_a->setChecked(false);
        cb_rd53b_b = new QCheckBox(centralwidget);
        cb_rd53b_b->setObjectName(QStringLiteral("cb_rd53b_b"));
        cb_rd53b_b->setGeometry(QRect(10, 60, 181, 22));
        cb_rd53b_b->setChecked(true);
        cb_rd53b_c = new QCheckBox(centralwidget);
        cb_rd53b_c->setObjectName(QStringLiteral("cb_rd53b_c"));
        cb_rd53b_c->setGeometry(QRect(10, 80, 181, 22));
        cb_rd53b_c->setChecked(false);
        cb_linereg_vol = new QCheckBox(centralwidget);
        cb_linereg_vol->setObjectName(QStringLiteral("cb_linereg_vol"));
        cb_linereg_vol->setGeometry(QRect(360, 30, 181, 22));
        cb_linereg_vol->setChecked(true);
        cb_loadreg = new QCheckBox(centralwidget);
        cb_loadreg->setObjectName(QStringLiteral("cb_loadreg"));
        cb_loadreg->setGeometry(QRect(360, 70, 151, 22));
        cb_loadreg->setChecked(false);
        cb_linereg_curr = new QCheckBox(centralwidget);
        cb_linereg_curr->setObjectName(QStringLiteral("cb_linereg_curr"));
        cb_linereg_curr->setGeometry(QRect(360, 50, 181, 22));
        cb_linereg_curr->setChecked(false);
        cb_start_ramp = new QCheckBox(centralwidget);
        cb_start_ramp->setObjectName(QStringLiteral("cb_start_ramp"));
        cb_start_ramp->setGeometry(QRect(360, 90, 151, 22));
        cb_start_ramp->setChecked(false);
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(360, 10, 261, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_29->setFont(font);
        TestBoard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestBoard);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 788, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        TestBoard->setMenuBar(menubar);
        statusbar = new QStatusBar(TestBoard);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestBoard->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(TestBoard);

        QMetaObject::connectSlotsByName(TestBoard);
    } // setupUi

    void retranslateUi(QMainWindow *TestBoard)
    {
        TestBoard->setWindowTitle(QApplication::translate("TestBoard", "Help Testboards", 0));
        actionExit->setText(QApplication::translate("TestBoard", "Exit", 0));
        label_pic->setText(QString());
#ifndef QT_NO_TOOLTIP
        cb_rd53a->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_rd53a->setText(QApplication::translate("TestBoard", "RD53A", 0));
#ifndef QT_NO_TOOLTIP
        show_board->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Beendet das Programm</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        show_board->setText(QApplication::translate("TestBoard", "show board", 0));
#ifndef QT_NO_TOOLTIP
        cb_rd53b_a->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_rd53b_a->setText(QApplication::translate("TestBoard", "RD53B_TestchipA", 0));
#ifndef QT_NO_TOOLTIP
        cb_rd53b_b->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_rd53b_b->setText(QApplication::translate("TestBoard", "RD53B_TestchipB", 0));
#ifndef QT_NO_TOOLTIP
        cb_rd53b_c->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_rd53b_c->setText(QApplication::translate("TestBoard", "RD53B_TestchipC", 0));
#ifndef QT_NO_TOOLTIP
        cb_linereg_vol->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_linereg_vol->setText(QApplication::translate("TestBoard", "Line Regulation Voltage", 0));
#ifndef QT_NO_TOOLTIP
        cb_loadreg->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_loadreg->setText(QApplication::translate("TestBoard", "Load Regulation", 0));
#ifndef QT_NO_TOOLTIP
        cb_linereg_curr->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_linereg_curr->setText(QApplication::translate("TestBoard", "Line Regulation Current", 0));
#ifndef QT_NO_TOOLTIP
        cb_start_ramp->setToolTip(QApplication::translate("TestBoard", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_start_ramp->setText(QApplication::translate("TestBoard", "Start Ramp", 0));
        label_29->setText(QApplication::translate("TestBoard", "show board configuration for:", 0));
        menuFile->setTitle(QApplication::translate("TestBoard", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class TestBoard: public Ui_TestBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTBOARD_H
