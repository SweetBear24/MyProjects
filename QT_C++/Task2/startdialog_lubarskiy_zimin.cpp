#include "startdialog_lubarskiy_zimin.h"

StartDialog_Lubarskiy_Zimin::StartDialog_Lubarskiy_Zimin(QWidget* pwgt):QPushButton("Нажми", pwgt)
{
    connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
}
StartDialog_Lubarskiy_Zimin::StartDialog_Lubarskiy_Zimin():StartDialog_Lubarskiy_Zimin(0)
{

}
void StartDialog_Lubarskiy_Zimin::slotButtonClicked()
{
    InputDialog_Lubarskiy_Zimin* pInputDialog = new InputDialog_Lubarskiy_Zimin;
    if (pInputDialog->exec()== QDialog::Accepted){
        QMessageBox::information(0, "Ваша информация: ", "Имя: " + pInputDialog->firstName() + "\nФамилия: " + pInputDialog->lastName());
    }
    delete pInputDialog;
}
