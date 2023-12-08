// mygraphicsscene.h
#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MyGraphicsScene(QObject *parent = nullptr);
    QGraphicsItem* itemCollidesWith(QGraphicsItem* item);
    // Метод для добавления трех прямоугольников на сцену
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  //  void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsRectItem *selectedRect;
    QGraphicsRectItem* walls[4];
    QGraphicsPixmapItem *phoneItem;
    QGraphicsPixmapItem *humanItem;
    int speed;
    double dx, dy;
    QTimer* timer;
public slots:
   void MoveMouse();
  // void moveObject(QGraphicsItem *item);

};

#endif // MYGRAPHICSSCENE_H
