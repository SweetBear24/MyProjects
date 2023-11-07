#include "lybarskiyzimin.h"
#include "ui_lybarskiyzimin.h"

#include <QFileDialog>
#include <QTextDocumentWriter>

LybarskiyZimin::LybarskiyZimin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LybarskiyZimin)
{
    ui->setupUi(this);
    connect(ui->btnBox, SIGNAL(clicked()), this, SLOT(on_btnBox_clicked()));
}

LybarskiyZimin::~LybarskiyZimin()
{
    delete ui;
}
void LybarskiyZimin::recieveData(QString str){
    this->show();
    QStringList lst = str.split("*");
    ui->textEdit->setText(lst.at(0) + "\n\nв " + lst.at(1));
    QImage image(lst.at(1));
    ui->label->setPixmap(QPixmap::fromImage(image));
}
void LybarskiyZimin::on_btnBox_clicked(QAbstractButton *button)
{
    if (button->text() == "Reset"){
        ui->textEdit->clear();
        ui->label->clear();
    }
    else if(button->text() == "Save"){
        QString filename = QFileDialog::getSaveFileName(nullptr, "Сохранить файл", QDir::currentPath(), "*.txt");
        QTextDocumentWriter writer;
        writer.setFileName(filename);
        writer.write(ui->textEdit->document());
    }
    else if(button->text() == "Open"){
        QString filename = QFileDialog::getOpenFileName(nullptr, "Открыть файл", QDir::currentPath(), "*.txt");
        QFile file(filename);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
            ui->textEdit->setPlainText(file.readAll());
        QStringList inf = ui->textEdit->toPlainText().split("\n");
        QImage image(inf.at(6));
        ui->label->setPixmap(QPixmap::fromImage(image));
    }
}
