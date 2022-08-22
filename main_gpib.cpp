#include "sldo65.h"
#include "gpib.h"


#include <QApplication>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gpib w;

    w.show();


return a.exec();
}
