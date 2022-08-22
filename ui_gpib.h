/********************************************************************************
** Form generated from reading UI file 'gpib.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPIB_H
#define UI_GPIB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_gpib
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionTestchips;
    QWidget *centralWidget;
    QLineEdit *startLE;
    QLineEdit *endLE;
    QLineEdit *stepLE;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *n;
    QLabel *label_6;
    QwtPlot *plot;
    QCheckBox *cb_k2460;
    QCheckBox *cb_k2400;
    QLabel *label_9;
    QLineEdit *Notiz_LE;
    QLabel *label_10;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_4;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *channel_names_le_16;
    QLineEdit *channel_names_le_18;
    QLineEdit *channel_names_le_20;
    QLineEdit *channel_names_le_22;
    QLineEdit *channel_names_le_17;
    QLineEdit *channel_names_le_19;
    QLineEdit *channel_names_le_21;
    QLabel *label_23;
    QLineEdit *ramp_delay_le;
    QLineEdit *ramp_start_le;
    QLineEdit *ramp_step_le;
    QLineEdit *ramp_end_le;
    QCheckBox *cb_ramp_current;
    QCheckBox *cb_ramp_voltage;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *start_button;
    QFrame *line_3;
    QLabel *label_29;
    QFrame *line_5;
    QLabel *label_30;
    QCheckBox *cb_linereg_vol;
    QCheckBox *cb_linereg_curr;
    QCheckBox *cb_loadreg;
    QCheckBox *cb_start_ramp;
    QCheckBox *cb_test_mult;
    QLineEdit *outkeith;
    QLineEdit *outkeith2;
    QLineEdit *outkeith3;
    QLineEdit *outkeith4;
    QLineEdit *outkeith5;
    QLineEdit *outkeith6;
    QLineEdit *outkeith7;
    QLineEdit *keith1_color;
    QLineEdit *keith1_color_2;
    QLineEdit *keith1_color_3;
    QLineEdit *keith1_color_4;
    QLineEdit *keith1_color_5;
    QLineEdit *keith1_color_6;
    QLineEdit *keith1_color_7;
    QLineEdit *vrangeLE;
    QLabel *label_5;
    QCheckBox *cb_stop_ramp;
    QLabel *label_7;
    QLineEdit *crangeLE;
    QLabel *label_8;
    QLineEdit *limitLE;
    QFrame *line_6;
    QLabel *label_32;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *gpib)
    {
        if (gpib->objectName().isEmpty())
            gpib->setObjectName(QStringLiteral("gpib"));
        gpib->setEnabled(true);
        gpib->resize(1278, 1116);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/commodore.ico"), QSize(), QIcon::Normal, QIcon::Off);
        gpib->setWindowIcon(icon);
        gpib->setToolTipDuration(-1);
        gpib->setIconSize(QSize(32, 32));
        actionOpen = new QAction(gpib);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionExit = new QAction(gpib);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/close-button-icon-8.jpg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionAbout = new QAction(gpib);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionTestchips = new QAction(gpib);
        actionTestchips->setObjectName(QStringLiteral("actionTestchips"));
        centralWidget = new QWidget(gpib);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startLE = new QLineEdit(centralWidget);
        startLE->setObjectName(QStringLiteral("startLE"));
        startLE->setEnabled(true);
        startLE->setGeometry(QRect(590, 50, 113, 27));
        startLE->setAlignment(Qt::AlignCenter);
        endLE = new QLineEdit(centralWidget);
        endLE->setObjectName(QStringLiteral("endLE"));
        endLE->setGeometry(QRect(590, 100, 113, 27));
        endLE->setAlignment(Qt::AlignCenter);
        stepLE = new QLineEdit(centralWidget);
        stepLE->setObjectName(QStringLiteral("stepLE"));
        stepLE->setGeometry(QRect(590, 150, 113, 27));
        stepLE->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(590, 30, 101, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(590, 80, 63, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(590, 130, 81, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 220, 41, 17));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(8);
        label_4->setFont(font);
        n = new QLineEdit(centralWidget);
        n->setObjectName(QStringLiteral("n"));
        n->setGeometry(QRect(40, 330, 1221, 27));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 310, 131, 17));
        plot = new QwtPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setEnabled(true);
        plot->setGeometry(QRect(30, 470, 1211, 541));
        plot->setLineWidth(3);
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        plot->setCanvasBackground(brush);
        cb_k2460 = new QCheckBox(centralWidget);
        cb_k2460->setObjectName(QStringLiteral("cb_k2460"));
        cb_k2460->setGeometry(QRect(770, 60, 151, 22));
        cb_k2460->setChecked(true);
        cb_k2400 = new QCheckBox(centralWidget);
        cb_k2400->setObjectName(QStringLiteral("cb_k2400"));
        cb_k2400->setGeometry(QRect(770, 40, 151, 22));
        cb_k2400->setChecked(false);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(770, 20, 161, 17));
        Notiz_LE = new QLineEdit(centralWidget);
        Notiz_LE->setObjectName(QStringLiteral("Notiz_LE"));
        Notiz_LE->setGeometry(QRect(40, 390, 1221, 31));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 370, 121, 17));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 430, 1281, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(950, 0, 20, 201));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(-450, 190, 1741, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(140, 220, 91, 21));
        label_16->setFont(font);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(330, 220, 91, 20));
        label_17->setFont(font);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(520, 220, 91, 20));
        label_18->setFont(font);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(880, 220, 91, 20));
        label_20->setFont(font);
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(700, 220, 91, 20));
        label_21->setFont(font);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(1060, 220, 91, 21));
        label_22->setFont(font);
        channel_names_le_16 = new QLineEdit(centralWidget);
        channel_names_le_16->setObjectName(QStringLiteral("channel_names_le_16"));
        channel_names_le_16->setGeometry(QRect(50, 220, 61, 20));
        QFont font1;
        font1.setPointSize(7);
        channel_names_le_16->setFont(font1);
        channel_names_le_16->setAlignment(Qt::AlignCenter);
        channel_names_le_18 = new QLineEdit(centralWidget);
        channel_names_le_18->setObjectName(QStringLiteral("channel_names_le_18"));
        channel_names_le_18->setGeometry(QRect(420, 220, 71, 20));
        channel_names_le_18->setFont(font1);
        channel_names_le_18->setAlignment(Qt::AlignCenter);
        channel_names_le_20 = new QLineEdit(centralWidget);
        channel_names_le_20->setObjectName(QStringLiteral("channel_names_le_20"));
        channel_names_le_20->setGeometry(QRect(790, 220, 61, 20));
        channel_names_le_20->setFont(font1);
        channel_names_le_20->setAlignment(Qt::AlignCenter);
        channel_names_le_22 = new QLineEdit(centralWidget);
        channel_names_le_22->setObjectName(QStringLiteral("channel_names_le_22"));
        channel_names_le_22->setGeometry(QRect(1150, 220, 61, 20));
        channel_names_le_22->setFont(font1);
        channel_names_le_22->setAlignment(Qt::AlignCenter);
        channel_names_le_17 = new QLineEdit(centralWidget);
        channel_names_le_17->setObjectName(QStringLiteral("channel_names_le_17"));
        channel_names_le_17->setGeometry(QRect(230, 220, 71, 20));
        channel_names_le_17->setFont(font1);
        channel_names_le_17->setAlignment(Qt::AlignCenter);
        channel_names_le_19 = new QLineEdit(centralWidget);
        channel_names_le_19->setObjectName(QStringLiteral("channel_names_le_19"));
        channel_names_le_19->setGeometry(QRect(610, 220, 71, 20));
        channel_names_le_19->setFont(font1);
        channel_names_le_19->setAlignment(Qt::AlignCenter);
        channel_names_le_21 = new QLineEdit(centralWidget);
        channel_names_le_21->setObjectName(QStringLiteral("channel_names_le_21"));
        channel_names_le_21->setGeometry(QRect(970, 220, 61, 20));
        channel_names_le_21->setFont(font1);
        channel_names_le_21->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setEnabled(false);
        label_23->setGeometry(QRect(970, 10, 131, 17));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_23->setFont(font2);
        ramp_delay_le = new QLineEdit(centralWidget);
        ramp_delay_le->setObjectName(QStringLiteral("ramp_delay_le"));
        ramp_delay_le->setEnabled(false);
        ramp_delay_le->setGeometry(QRect(990, 100, 113, 27));
        ramp_delay_le->setAlignment(Qt::AlignCenter);
        ramp_start_le = new QLineEdit(centralWidget);
        ramp_start_le->setObjectName(QStringLiteral("ramp_start_le"));
        ramp_start_le->setEnabled(false);
        ramp_start_le->setGeometry(QRect(990, 150, 113, 27));
        ramp_start_le->setAlignment(Qt::AlignCenter);
        ramp_step_le = new QLineEdit(centralWidget);
        ramp_step_le->setObjectName(QStringLiteral("ramp_step_le"));
        ramp_step_le->setEnabled(false);
        ramp_step_le->setGeometry(QRect(1130, 100, 113, 27));
        ramp_step_le->setAlignment(Qt::AlignCenter);
        ramp_end_le = new QLineEdit(centralWidget);
        ramp_end_le->setObjectName(QStringLiteral("ramp_end_le"));
        ramp_end_le->setEnabled(false);
        ramp_end_le->setGeometry(QRect(1130, 150, 113, 27));
        ramp_end_le->setAlignment(Qt::AlignCenter);
        cb_ramp_current = new QCheckBox(centralWidget);
        cb_ramp_current->setObjectName(QStringLiteral("cb_ramp_current"));
        cb_ramp_current->setEnabled(false);
        cb_ramp_current->setGeometry(QRect(990, 50, 151, 22));
        cb_ramp_current->setChecked(true);
        cb_ramp_voltage = new QCheckBox(centralWidget);
        cb_ramp_voltage->setObjectName(QStringLiteral("cb_ramp_voltage"));
        cb_ramp_voltage->setEnabled(false);
        cb_ramp_voltage->setGeometry(QRect(1120, 50, 151, 22));
        cb_ramp_voltage->setChecked(false);
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setEnabled(false);
        label_24->setGeometry(QRect(990, 80, 131, 17));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setEnabled(false);
        label_25->setGeometry(QRect(1130, 130, 131, 17));
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setEnabled(false);
        label_26->setGeometry(QRect(990, 130, 131, 17));
        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setEnabled(false);
        label_27->setGeometry(QRect(1130, 80, 131, 17));
        label_28 = new QLabel(centralWidget);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setEnabled(false);
        label_28->setGeometry(QRect(1190, 10, 131, 17));
        start_button = new QPushButton(centralWidget);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setEnabled(true);
        start_button->setGeometry(QRect(280, 90, 91, 27));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 280, 1281, 31));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(590, 10, 131, 17));
        label_29->setFont(font2);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(390, 0, 20, 201));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(30, 10, 131, 17));
        label_30->setFont(font2);
        cb_linereg_vol = new QCheckBox(centralWidget);
        cb_linereg_vol->setObjectName(QStringLiteral("cb_linereg_vol"));
        cb_linereg_vol->setGeometry(QRect(30, 40, 181, 22));
        cb_linereg_vol->setChecked(false);
        cb_linereg_curr = new QCheckBox(centralWidget);
        cb_linereg_curr->setObjectName(QStringLiteral("cb_linereg_curr"));
        cb_linereg_curr->setGeometry(QRect(30, 70, 181, 22));
        cb_linereg_curr->setChecked(true);
        cb_loadreg = new QCheckBox(centralWidget);
        cb_loadreg->setObjectName(QStringLiteral("cb_loadreg"));
        cb_loadreg->setGeometry(QRect(30, 100, 151, 22));
        cb_loadreg->setChecked(false);
        cb_start_ramp = new QCheckBox(centralWidget);
        cb_start_ramp->setObjectName(QStringLiteral("cb_start_ramp"));
        cb_start_ramp->setGeometry(QRect(30, 130, 151, 22));
        cb_start_ramp->setChecked(false);
        cb_test_mult = new QCheckBox(centralWidget);
        cb_test_mult->setObjectName(QStringLiteral("cb_test_mult"));
        cb_test_mult->setGeometry(QRect(30, 160, 151, 22));
        cb_test_mult->setChecked(false);
        outkeith = new QLineEdit(centralWidget);
        outkeith->setObjectName(QStringLiteral("outkeith"));
        outkeith->setGeometry(QRect(60, 250, 101, 27));
        outkeith2 = new QLineEdit(centralWidget);
        outkeith2->setObjectName(QStringLiteral("outkeith2"));
        outkeith2->setGeometry(QRect(230, 250, 101, 27));
        outkeith3 = new QLineEdit(centralWidget);
        outkeith3->setObjectName(QStringLiteral("outkeith3"));
        outkeith3->setGeometry(QRect(410, 250, 101, 27));
        outkeith4 = new QLineEdit(centralWidget);
        outkeith4->setObjectName(QStringLiteral("outkeith4"));
        outkeith4->setGeometry(QRect(590, 250, 101, 27));
        outkeith5 = new QLineEdit(centralWidget);
        outkeith5->setObjectName(QStringLiteral("outkeith5"));
        outkeith5->setGeometry(QRect(760, 250, 101, 27));
        outkeith6 = new QLineEdit(centralWidget);
        outkeith6->setObjectName(QStringLiteral("outkeith6"));
        outkeith6->setGeometry(QRect(920, 250, 101, 27));
        outkeith7 = new QLineEdit(centralWidget);
        outkeith7->setObjectName(QStringLiteral("outkeith7"));
        outkeith7->setGeometry(QRect(1100, 250, 101, 27));
        keith1_color = new QLineEdit(centralWidget);
        keith1_color->setObjectName(QStringLiteral("keith1_color"));
        keith1_color->setGeometry(QRect(20, 250, 31, 27));
        QPalette palette;
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(235, 235, 237, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush3(QColor(245, 245, 246, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(117, 117, 118, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(157, 157, 158, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush6(QColor(0, 0, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        keith1_color->setPalette(palette);
        keith1_color_2 = new QLineEdit(centralWidget);
        keith1_color_2->setObjectName(QStringLiteral("keith1_color_2"));
        keith1_color_2->setGeometry(QRect(190, 250, 31, 27));
        QPalette palette1;
        QBrush brush8(QColor(255, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        keith1_color_2->setPalette(palette1);
        keith1_color_3 = new QLineEdit(centralWidget);
        keith1_color_3->setObjectName(QStringLiteral("keith1_color_3"));
        keith1_color_3->setGeometry(QRect(370, 250, 31, 27));
        QPalette palette2;
        QBrush brush9(QColor(0, 255, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        keith1_color_3->setPalette(palette2);
        keith1_color_4 = new QLineEdit(centralWidget);
        keith1_color_4->setObjectName(QStringLiteral("keith1_color_4"));
        keith1_color_4->setGeometry(QRect(550, 250, 31, 27));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        keith1_color_4->setPalette(palette3);
        keith1_color_5 = new QLineEdit(centralWidget);
        keith1_color_5->setObjectName(QStringLiteral("keith1_color_5"));
        keith1_color_5->setGeometry(QRect(720, 250, 31, 27));
        QPalette palette4;
        QBrush brush10(QColor(128, 128, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        keith1_color_5->setPalette(palette4);
        keith1_color_6 = new QLineEdit(centralWidget);
        keith1_color_6->setObjectName(QStringLiteral("keith1_color_6"));
        keith1_color_6->setGeometry(QRect(880, 250, 31, 27));
        QPalette palette5;
        QBrush brush11(QColor(128, 0, 128, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        keith1_color_6->setPalette(palette5);
        keith1_color_7 = new QLineEdit(centralWidget);
        keith1_color_7->setObjectName(QStringLiteral("keith1_color_7"));
        keith1_color_7->setGeometry(QRect(1060, 250, 31, 27));
        QPalette palette6;
        QBrush brush12(QColor(0, 128, 128, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush12);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        keith1_color_7->setPalette(palette6);
        vrangeLE = new QLineEdit(centralWidget);
        vrangeLE->setObjectName(QStringLiteral("vrangeLE"));
        vrangeLE->setGeometry(QRect(420, 100, 113, 27));
        vrangeLE->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(420, 80, 151, 17));
        cb_stop_ramp = new QCheckBox(centralWidget);
        cb_stop_ramp->setObjectName(QStringLiteral("cb_stop_ramp"));
        cb_stop_ramp->setGeometry(QRect(140, 130, 151, 22));
        cb_stop_ramp->setChecked(false);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(420, 130, 151, 17));
        crangeLE = new QLineEdit(centralWidget);
        crangeLE->setObjectName(QStringLiteral("crangeLE"));
        crangeLE->setGeometry(QRect(420, 150, 113, 27));
        crangeLE->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(420, 30, 151, 17));
        limitLE = new QLineEdit(centralWidget);
        limitLE->setObjectName(QStringLiteral("limitLE"));
        limitLE->setGeometry(QRect(420, 50, 113, 27));
        limitLE->setAlignment(Qt::AlignCenter);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(560, 0, 20, 201));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_32 = new QLabel(centralWidget);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(420, 10, 141, 17));
        label_32->setFont(font2);
        gpib->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(gpib);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        gpib->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(gpib);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        gpib->setStatusBar(statusBar);
        menuBar = new QMenuBar(gpib);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1278, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        gpib->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionTestchips);

        retranslateUi(gpib);

        QMetaObject::connectSlotsByName(gpib);
    } // setupUi

    void retranslateUi(QMainWindow *gpib)
    {
        gpib->setWindowTitle(QApplication::translate("gpib", "Shuldo-Test 1.1a Fachhochschule Dortmund AG Karagounis", 0));
#ifndef QT_NO_TOOLTIP
        gpib->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("gpib", "Open", 0));
        actionExit->setText(QApplication::translate("gpib", "Exit", 0));
        actionAbout->setText(QApplication::translate("gpib", "About", 0));
        actionTestchips->setText(QApplication::translate("gpib", "Testchips", 0));
        startLE->setText(QApplication::translate("gpib", "0", 0));
        endLE->setText(QApplication::translate("gpib", "1", 0));
        stepLE->setText(QApplication::translate("gpib", "0.1", 0));
        label->setText(QApplication::translate("gpib", "start value", 0));
        label_2->setText(QApplication::translate("gpib", "end value", 0));
        label_3->setText(QApplication::translate("gpib", "step size", 0));
        label_4->setText(QApplication::translate("gpib", "<html><head/><body><p>ID=16:</p></body></html>", 0));
        n->setText(QApplication::translate("gpib", "/home/zorn_local/logs/Test/test.log", 0));
        label_6->setText(QApplication::translate("gpib", "Log file path:", 0));
#ifndef QT_NO_TOOLTIP
        cb_k2460->setToolTip(QApplication::translate("gpib", "<html><head/><body><p>Keithley 2460 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_k2460->setText(QApplication::translate("gpib", "Keithley 2460 (30)", 0));
#ifndef QT_NO_TOOLTIP
        cb_k2400->setToolTip(QApplication::translate("gpib", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_k2400->setText(QApplication::translate("gpib", "Keithley 2400 (12)", 0));
        label_9->setText(QApplication::translate("gpib", "Which SMU for sweep?", 0));
        Notiz_LE->setText(QApplication::translate("gpib", "Messung 1: SLDO;internal references;Vbgset=(10000);IrefSet=(1110);VrefSet=(1001);Rvref=150kOhm;Vref=600mV;Rofs=125kOhm;Vofshalf=500mV;Rext=600Ohm", 0));
        label_10->setText(QApplication::translate("gpib", "Note:", 0));
        label_16->setText(QApplication::translate("gpib", "SrNr:04408214", 0));
        label_17->setText(QApplication::translate("gpib", "SrNr:04407708", 0));
        label_18->setText(QApplication::translate("gpib", "SrNr:04408210", 0));
        label_20->setText(QApplication::translate("gpib", "SrNr:04408757", 0));
        label_21->setText(QApplication::translate("gpib", "SrNr:04409223", 0));
        label_22->setText(QApplication::translate("gpib", "SrNr:04408823", 0));
        channel_names_le_16->setText(QApplication::translate("gpib", "Vofshalf", 0));
        channel_names_le_18->setText(QApplication::translate("gpib", "Vout_Sense", 0));
        channel_names_le_20->setText(QApplication::translate("gpib", "Iout_Sense", 0));
        channel_names_le_22->setText(QApplication::translate("gpib", "Vprereg", 0));
        channel_names_le_17->setText(QApplication::translate("gpib", "Vref", 0));
        channel_names_le_19->setText(QApplication::translate("gpib", "Iin_Sense", 0));
        channel_names_le_21->setText(QApplication::translate("gpib", "Vrefpre", 0));
        label_23->setText(QApplication::translate("gpib", "settings ramp:", 0));
        ramp_delay_le->setText(QApplication::translate("gpib", "0.002", 0));
        ramp_start_le->setText(QApplication::translate("gpib", "0", 0));
        ramp_step_le->setText(QApplication::translate("gpib", "100", 0));
        ramp_end_le->setText(QApplication::translate("gpib", "2", 0));
#ifndef QT_NO_TOOLTIP
        cb_ramp_current->setToolTip(QApplication::translate("gpib", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_ramp_current->setText(QApplication::translate("gpib", "Current", 0));
#ifndef QT_NO_TOOLTIP
        cb_ramp_voltage->setToolTip(QApplication::translate("gpib", "<html><head/><body><p>Keithley 2400 wird verwendet</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cb_ramp_voltage->setText(QApplication::translate("gpib", "Voltage", 0));
        label_24->setText(QApplication::translate("gpib", "delay (s)", 0));
        label_25->setText(QApplication::translate("gpib", "end value", 0));
        label_26->setText(QApplication::translate("gpib", "start value", 0));
        label_27->setText(QApplication::translate("gpib", "steps", 0));
        label_28->setText(QApplication::translate("gpib", "(only 2460)", 0));
#ifndef QT_NO_TOOLTIP
        start_button->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        start_button->setText(QApplication::translate("gpib", "start test", 0));
        label_29->setText(QApplication::translate("gpib", "settings sweep:", 0));
        label_30->setText(QApplication::translate("gpib", "test selection:", 0));
#ifndef QT_NO_TOOLTIP
        cb_linereg_vol->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cb_linereg_vol->setText(QApplication::translate("gpib", "Line Regulation voltage", 0));
#ifndef QT_NO_TOOLTIP
        cb_linereg_curr->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cb_linereg_curr->setText(QApplication::translate("gpib", "Line Regulation current", 0));
#ifndef QT_NO_TOOLTIP
        cb_loadreg->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cb_loadreg->setText(QApplication::translate("gpib", "Load Regulation", 0));
#ifndef QT_NO_TOOLTIP
        cb_start_ramp->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cb_start_ramp->setText(QApplication::translate("gpib", "start ramp", 0));
#ifndef QT_NO_TOOLTIP
        cb_test_mult->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cb_test_mult->setText(QApplication::translate("gpib", "test multimeter", 0));
        outkeith->setText(QString());
        outkeith2->setText(QString());
        outkeith3->setText(QString());
        outkeith4->setText(QString());
        outkeith5->setText(QString());
        outkeith6->setText(QString());
        outkeith7->setText(QString());
        keith1_color->setText(QString());
        keith1_color_2->setText(QString());
        keith1_color_3->setText(QString());
        keith1_color_4->setText(QString());
        keith1_color_5->setText(QString());
        keith1_color_6->setText(QString());
        keith1_color_7->setText(QString());
        vrangeLE->setText(QApplication::translate("gpib", "2", 0));
        label_5->setText(QApplication::translate("gpib", "voltage range", 0));
#ifndef QT_NO_TOOLTIP
        cb_stop_ramp->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cb_stop_ramp->setText(QApplication::translate("gpib", "stop ramp", 0));
        label_7->setText(QApplication::translate("gpib", "current range", 0));
        crangeLE->setText(QApplication::translate("gpib", "2", 0));
        label_8->setText(QApplication::translate("gpib", "limit voltage/current", 0));
        limitLE->setText(QApplication::translate("gpib", "1", 0));
        label_32->setText(QApplication::translate("gpib", "limits and ranges:", 0));
        menuFile->setTitle(QApplication::translate("gpib", "File", 0));
        menuHelp->setTitle(QApplication::translate("gpib", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class gpib: public Ui_gpib {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPIB_H
