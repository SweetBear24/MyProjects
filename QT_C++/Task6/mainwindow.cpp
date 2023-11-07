#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myform = new LybarskiyZimin;
    connect(ui->btnUploadPhoto, SIGNAL(clicked()), this, SLOT(btnUploadPhotoClicked()));
    connect(ui->btnReady, SIGNAL(clicked()), this, SLOT(btnReadyClicked()));
    connect(this, SIGNAL(sendData(QString)), myform, SLOT(recieveData(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::btnUploadPhotoClicked(){
    QString filename = QFileDialog::getOpenFileName(nullptr, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
    QImage image(filename);
    ui->photo->setPixmap(QPixmap::fromImage(image));
    ui->link->setText(filename);
}

void MainWindow::btnReadyClicked()
{
    if(ui->lineName->text() == "" || ui->linePost->text() == "" || ui->lineEmail->text() == "")
        {
            QMessageBox msgBox;
            msgBox.setText("Все поля должны быть заполнены!");
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
        }
        else {
            QString st = "ФИО: " + ui->lineName->text() +
                    "\nДолжность: " + ui->linePost->text() +
                    "\nДата рождения: " + ui->dateOfBirth->text()+
                    "\nEmail: " + ui->lineEmail->text()+
                    "\nФирма: " + ui->lineCompany->text()+
                    "\nДолжность: " + ui->linePost->text();
            if (ui->radioButtonMan->isChecked())
                st += "\nПол: Мужской";
            else
                st += "\nПол: Женский";
            st += "*" + ui->link->text();

            emit sendData(st);
    }
}
