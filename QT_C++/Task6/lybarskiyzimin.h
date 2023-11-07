#ifndef LYBARSKIYZIMIN_H
#define LYBARSKIYZIMIN_H

#include <QAbstractButton>
#include <QWidget>

namespace Ui {
class LybarskiyZimin;
}

class LybarskiyZimin : public QWidget
{
    Q_OBJECT

public:
    explicit LybarskiyZimin(QWidget *parent = 0);
    ~LybarskiyZimin();

private:
    Ui::LybarskiyZimin *ui;
public slots:
    void recieveData(QString str);
private slots:
    void on_btnBox_clicked(QAbstractButton *button);
};

#endif // LYBARSKIYZIMIN_H
