#include "testboard.h"
#include "ui_testboard.h"
#include <QDebug>
#include <QMessageBox>

TestBoard::TestBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestBoard)
{
    ui->setupUi(this);

    //QPixmap pix(":/res/RD53A.png");
    //ui->label_pic->setScaledContents(true);
    //ui->label_pic->setPixmap(pix);

    //qDebug() << "Ich war mal hier";
}

TestBoard::~TestBoard()
{
    delete ui;
}

void TestBoard::on_actionExit_triggered()
{
    this->close();
}

void TestBoard::on_show_board_clicked()
{
    if (ui->cb_rd53a->isChecked())
    {
    QPixmap rd53a(":/res/RD53A.png");
    ui->label_pic->setScaledContents(true);
    ui->label_pic->setPixmap(rd53a);
    }
    else if(ui->cb_rd53b_a->isChecked())
    {
        QPixmap rd53b_a(":/res/RD53B_A.png");
        ui->label_pic->setScaledContents(true);
        ui->label_pic->setPixmap(rd53b_a);
    }
    else if(ui->cb_rd53b_b->isChecked())
    {
        QPixmap rd53b_b(":/res/RD53B_B.png");
        ui->label_pic->setScaledContents(true);
        ui->label_pic->setPixmap(rd53b_b);
    }
    else if(ui->cb_rd53b_c->isChecked())
    {
        QPixmap rd53b_c(":/res/RD53B_C.png");
        ui->label_pic->setScaledContents(true);
        ui->label_pic->setPixmap(rd53b_c);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Bitte Testchip auswählen!");
        msgBox.exec();
    }
}

void TestBoard::on_cb_rd53a_clicked()
{
    if (ui->cb_rd53a->isChecked())
    {
       ui->cb_rd53b_a->setChecked(0);
       ui->cb_rd53b_b->setChecked(0);
       ui->cb_rd53b_c->setChecked(0);

    }
}

void TestBoard::on_cb_rd53b_a_clicked()
{
    if (ui->cb_rd53b_a->isChecked())
    {
       ui->cb_rd53a->setChecked(0);
       ui->cb_rd53b_b->setChecked(0);
       ui->cb_rd53b_c->setChecked(0);

    }
}

void TestBoard::on_cb_rd53b_b_clicked()
{
    if (ui->cb_rd53b_b->isChecked())
    {
       ui->cb_rd53b_a->setChecked(0);
       ui->cb_rd53a->setChecked(0);
       ui->cb_rd53b_c->setChecked(0);

    }
}

void TestBoard::on_cb_rd53b_c_clicked()
{
    if (ui->cb_rd53b_c->isChecked())
    {
       ui->cb_rd53a->setChecked(0);
       ui->cb_rd53b_b->setChecked(0);
       ui->cb_rd53b_a->setChecked(0);

    }
}

void TestBoard::on_cb_linereg_vol_clicked()
{
    if (ui->cb_linereg_vol->isChecked())
    {
       ui->cb_linereg_curr->setChecked(0);
       ui->cb_start_ramp->setChecked(0);
       ui->cb_loadreg->setChecked(0);
    }

}

void TestBoard::on_cb_linereg_curr_clicked()
{
    if (ui->cb_linereg_curr->isChecked())
    {
       ui->cb_linereg_vol->setChecked(0);
       ui->cb_start_ramp->setChecked(0);
       ui->cb_loadreg->setChecked(0);
    }
}

void TestBoard::on_cb_start_ramp_clicked()
{
    if (ui->cb_start_ramp->isChecked())
    {
       ui->cb_linereg_vol->setChecked(0);
       ui->cb_linereg_curr->setChecked(0);
       ui->cb_loadreg->setChecked(0);
    }
}


void TestBoard::on_cb_loadreg_clicked()
{
    if (ui->cb_loadreg->isChecked())
    {
       ui->cb_linereg_vol->setChecked(0);
       ui->cb_linereg_curr->setChecked(0);
       ui->cb_start_ramp->setChecked(0);
    }
}
