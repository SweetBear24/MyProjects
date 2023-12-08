#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include "imageitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageLabel = new QLabel(this);
    imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    ui->scrollArea->setWidget(imageLabel);

    settings = new QSettings("E:/QT/Proj/ComicsPro3/settings.ini", QSettings::IniFormat, this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                       "Выбрать изображение", "",
                        "Изображения (*.bmp  *.jpg *.png)");
    QPixmap pix(fileName);
    imageLabel->setPixmap(pix);
    imageLabel->setFixedSize(pix.width(),pix.height());
    setImagesList(fileName);

}

void MainWindow::on_action_3_triggered()
{
    this->close();
}

void MainWindow::setImagesList(QString filename)
{
    ui->listWidget->clear();
    QFileInfo info(filename);
    QDir dir(info.absolutePath());
    QStringList filter;
    filter << "*.jpg" << "*.png" << "*.bmp";
    QFileInfoList list =  dir.entryInfoList(filter);
    for (int i=0;i<list.count();i++) {
         QFileInfo f = list.at(i);
         QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
         ImageItem *imgitem = new ImageItem;
         QPixmap pix(f.filePath());
         int w = pix.width();
         int h = pix.height();
         double filesize = f.size()/1024.0;
         QString resStr = QString::number(w) + "x" + QString::number(h)+ " ";
         resStr += QString::number(filesize) + " Kb";
         imgitem->setData(pix.scaledToWidth(80,Qt::SmoothTransformation),f.fileName(),resStr, f.filePath());
         item->setSizeHint(imgitem->sizeHint());
         ui->listWidget->setItemWidget(item,imgitem);


        /*
        qDebug() << list.at(i).filePath();
        QFileInfo f = list.at(i);
        QIcon icon;
        icon.addFile(f.filePath());
        QListWidgetItem *item = new QListWidgetItem(icon, f.fileName());
        ui->listWidget->addItem(item);
        if(f.filePath() == filename){
            item->setSelected(true);
        }
        */
    }
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ImageItem *imageitem = qobject_cast <ImageItem*>(ui->listWidget->itemWidget(item));
    QPixmap pix(imageitem->getPath());
    imageLabel->setPixmap(pix);
    imageLabel->setFixedSize(pix.width(),pix.height());
}

void MainWindow::on_action_4_triggered()
{
    int newWidht = int(imageLabel->width()*1.25);
    int newHeight = int(imageLabel->height()*1.25);
    imageLabel->setFixedSize(newWidht,newHeight);
}

void MainWindow::on_action_5_triggered()
{
    int newWidht = int(imageLabel->width()*0.75);
    int newHeight = int(imageLabel->height()*0.75);
    imageLabel->setFixedSize(newWidht,newHeight);
}

void MainWindow::on_action_7_triggered()
{

}

void MainWindow::saveSettings()
{
    settings->setValue("geometry", geometry());
}

void MainWindow::loadSettings()
{
    setGeometry(settings->value("geometry", QRect(0,0,872,658)).toRect());
}
