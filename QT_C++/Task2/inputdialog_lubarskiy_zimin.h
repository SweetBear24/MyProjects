#ifndef INPUTDIALOG_LUBARSKIY_ZIMIN_H
#define INPUTDIALOG_LUBARSKIY_ZIMIN_H

#include <QDialog>
#include <QLineEdit>

class QLineEdit;

class InputDialog_Lubarskiy_Zimin: public QDialog
{
    Q_OBJECT
private:
    QLineEdit * m_ptxtFirstName;
    QLineEdit * m_ptxtLastName;
public:
    InputDialog_Lubarskiy_Zimin(QWidget* pwgt);
    InputDialog_Lubarskiy_Zimin();

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_LUBARSKIY_ZIMIN_H
