#include <QtCore/QCoreApplication>
#include <qapplication.h>
#include "TInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TInterface* fc{};
    
    AdditionalInterface AddInt(fc);
    AddInt.show();

    return a.exec();
}
