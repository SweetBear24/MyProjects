#ifndef SDIPROGRAM_LYBARSKIY_ZIMIN_H
#define SDIPROGRAM_LYBARSKIY_ZIMIN_H

#include <QMainWindow>
#include <docwindow_lybarskiy_zimin.h>
#include <QtWidgets>
#include <sdiprogram_lybarskiy_zimin.h>

namespace Ui {
class SDIProgram_Lybarskiy_Zimin;
}

class SDIProgram_Lybarskiy_Zimin : public QMainWindow
{
    Q_OBJECT

public:

   SDIProgram_Lybarskiy_Zimin(QWidget *pwgt = 0);
   ~SDIProgram_Lybarskiy_Zimin();

private:
    Ui::SDIProgram_Lybarskiy_Zimin *ui;

public slots:
    void slotAbout();
    void slotChangeWindowTitle(const QString&);
};

#endif // SDIPROGRAM_LYBARSKIY_ZIMIN_H
