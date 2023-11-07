#include "mainwindow.h"
#include "startdialog_lubarskiy_zimin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Lubarskiy_Zimin startDialog;
    startDialog.show();
    return a.exec();
}
