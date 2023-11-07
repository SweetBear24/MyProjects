#include "inputdialog_lubarskiy_zimin.h"
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QPushButton>

InputDialog_Lubarskiy_Zimin::InputDialog_Lubarskiy_Zimin(QWidget* pwgt): QDialog(pwgt)
{
    m_ptxtFirstName = new QLineEdit;
    m_ptxtLastName = new QLineEdit;

    QLabel* plblFirstName = new QLabel("&Имя");
    QLabel* plblLastName = new QLabel("&Фамилия");

    plblFirstName->setBuddy(m_ptxtFirstName);
    plblLastName->setBuddy(m_ptxtLastName);

    QPushButton* pcmdOk = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");

    connect(pcmdOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblFirstName, 0, 0);
    ptopLayout->addWidget(plblLastName, 1, 0);
    ptopLayout->addWidget(m_ptxtFirstName, 0, 1);
    ptopLayout->addWidget(m_ptxtLastName, 1, 1);
    ptopLayout->addWidget(pcmdOk, 2, 0);
    ptopLayout->addWidget(pcmdCancel, 2, 1);
    setLayout(ptopLayout);
}
InputDialog_Lubarskiy_Zimin::InputDialog_Lubarskiy_Zimin():InputDialog_Lubarskiy_Zimin(0)
{

}

QString InputDialog_Lubarskiy_Zimin::firstName() const
{
    return m_ptxtFirstName->text();
}

QString InputDialog_Lubarskiy_Zimin::lastName() const
{
    return m_ptxtLastName->text();
}
