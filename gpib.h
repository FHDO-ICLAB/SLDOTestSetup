
/* KARL MACHA/ Bachelorthesis/ Sommersemester 2017/ Fachhochschule Dortmund
 * Hier wird ein Header für die grafische Oberfläche in gpib.ui codiert. Die Functionen für die Einzelnen Elemente werden hier aufgelistet
*/



#ifndef GPIB_H
#define GPIB_H


#include <QMainWindow>
#include <sldo65.h>
#include "qwt_plot.h"
#include "qwt_plot_curve.h"
#include "QTextEdit"
#include "QFile"
#include <QWidget>
#include "testboard.h"



namespace Ui {
class gpib;
}

class gpib : public QMainWindow
{
    Q_OBJECT

public:

explicit gpib(QWidget *parent = 0);
    ~gpib();
    sldo65 *z;




private slots:

    void on_cb_k2400_clicked();

    void on_cb_k2460_clicked();

    void on_cb_ramp_current_clicked();

    void on_cb_ramp_voltage_clicked();

    void on_cb_linereg_vol_clicked();

    void on_cb_linereg_curr_clicked();

    void on_cb_start_ramp_clicked();

    void on_cb_test_mult_clicked();

    void on_cb_loadreg_clicked();

    void on_start_button_clicked();

    void on_actionAbout_triggered();
    void on_actionExit_triggered();
    void on_actionOpen_triggered();

    void on_actionTestchips_triggered();

    void on_cb_stop_ramp_clicked();

private:
    Ui::gpib *ui;
    TestBoard *testboard;
};

#endif // GPIB_H


