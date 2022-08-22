#ifndef TESTBOARD_H
#define TESTBOARD_H

#include <QMainWindow>

namespace Ui {
class TestBoard;
}

class TestBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestBoard(QWidget *parent = 0);
    ~TestBoard();

private:
    Ui::TestBoard *ui;

private slots:
    void on_actionExit_triggered();

    void on_show_board_clicked();
    void on_cb_rd53a_clicked();
    void on_cb_rd53b_a_clicked();
    void on_cb_rd53b_b_clicked();
    void on_cb_rd53b_c_clicked();
    void on_cb_linereg_vol_clicked();
    void on_cb_linereg_curr_clicked();
    void on_cb_loadreg_clicked();
    void on_cb_start_ramp_clicked();
};

#endif // TESTBOARD_H
