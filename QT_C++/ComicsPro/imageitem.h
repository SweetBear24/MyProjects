#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

class ImageItem : public QWidget
{
    Q_OBJECT
public:
    explicit ImageItem(QWidget *parent = nullptr);
    void setData(QPixmap pix, QString titleText, QString infoText, QString path);
    QString getPath();

signals:

private:
    QLabel *img;
    QLabel *title;
    QLabel *info;
    QString path;
};

#endif // IMAGEITEM_H
