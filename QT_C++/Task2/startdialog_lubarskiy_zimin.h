#ifndef STARTDIALOG_LUBARSKIY_ZIMIN_H
#define STARTDIALOG_LUBARSKIY_ZIMIN_H

#include "QWidget"
#include "QPushButton"
#include "QMessageBox"
#include "inputdialog_lubarskiy_zimin.h"


class StartDialog_Lubarskiy_Zimin: public QPushButton
{
    Q_OBJECT
public:
    StartDialog_Lubarskiy_Zimin(QWidget* pwgt);
    StartDialog_Lubarskiy_Zimin();

public slots:
    void slotButtonClicked();
};

#endif // STARTDIALOG_LUBARSKIY_ZIMIN_H
