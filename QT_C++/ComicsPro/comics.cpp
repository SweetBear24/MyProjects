#include "comics.h"
#include "mainwindow.h"
#include "ui_comics.h"

comics::comics(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::comics)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/QT/Proj/ComicsPro3/ComicsPro.db");
    if(db.open()){
        ui->statusBar->showMessage("Вы успешно подключились к базе данных " + db.databaseName());

        model = new QSqlTableModel(this, db);
        model->setTable("COMICS");
        model->select();

        model->setHeaderData(1,Qt::Horizontal, "Номер", Qt::DisplayRole);
        model->setHeaderData(2,Qt::Horizontal, "Название", Qt::DisplayRole);
        model->setHeaderData(3,Qt::Horizontal, "Год Издания", Qt::DisplayRole);

        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSortingEnabled(true);
    }
    else{
         ui->statusBar->showMessage("При подключении к базе данных произошла ошибка:" + db.lastError().databaseText());
    }
}

comics::~comics()
{
    db.close();
    delete ui;
}


void comics::on_pushButton_clicked()
{
    MainWindow *secondMainWindow = new MainWindow(this);
    secondMainWindow->show();
}

void comics::on_btnAdd_clicked()
{
    model->insertRow(model->rowCount());
}

void comics::on_btnRemove_clicked()
{
    model->removeRow(currentRow);
    model->select();
}

void comics::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}

void comics::on_btnRefresh_clicked()
{
    model->select();
    ui->tableView->selectRow(currentRow);
}
