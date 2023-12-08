#ifndef COMICS_H
#define COMICS_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>

namespace Ui {
class comics;
}

class comics : public QMainWindow
{
    Q_OBJECT

public:
    explicit comics(QWidget *parent = 0);
    ~comics();
private slots:
    void on_pushButton_clicked();
    void on_btnAdd_clicked();
    void on_btnRemove_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_btnRefresh_clicked();

private:
    Ui::comics *ui;

    QSqlDatabase db;
    QSqlTableModel *model;
    int currentRow;
};

#endif // COMICS_H
