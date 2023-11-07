#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <lybarskiyzimin.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LybarskiyZimin *myform;

signals:
    void sendData(QString str);
private slots:
    void btnReadyClicked();
    void btnUploadPhotoClicked();
};

#endif // MAINWINDOW_H
