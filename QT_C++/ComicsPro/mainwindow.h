#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QListWidget>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();
    void on_action_3_triggered();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_action_4_triggered();
    void on_action_5_triggered();
    void on_action_7_triggered();
    void saveSettings();
    void loadSettings();

private:
    Ui::MainWindow *ui;

    QLabel * imageLabel;
    void setImagesList(QString filename);
    QSettings *settings;
};

#endif // MAINWINDOW_H
