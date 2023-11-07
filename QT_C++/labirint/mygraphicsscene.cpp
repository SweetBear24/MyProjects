#include "mygraphicsscene.h"
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QPropertyAnimation>
#include <QtGlobal>
#include <Qt>
#include <QtMath>
#include <QMessageBox>
MyGraphicsScene::MyGraphicsScene(QObject *parent) : QGraphicsScene(parent)
{
    QGraphicsRectItem *rect1 = new QGraphicsRectItem(0, 0, 50, 50); // Прямоугольник 1 (50x50)
    rect1->setPos(100, 100); // Установите позицию элемента
    rect1->setBrush(QBrush(Qt::red)); // Установите красный цвет
    rect1->setData(0, "Cube");
    QGraphicsRectItem *rect2 = new QGraphicsRectItem(0, 0, 50, 50); // Прямоугольник 2 (50x50)
    rect2->setPos(200, 200); // Установите позицию элемента
    rect2->setBrush(QBrush(Qt::green)); // Установите зеленый цвет
    rect2->setData(0, "Cube");
    QGraphicsRectItem *rect3 = new QGraphicsRectItem(0, 0, 50, 50); // Прямоугольник 3 (50x50)
    rect3->setPos(250, 250); // Установите позицию элемента
    rect3->setBrush(QBrush(Qt::blue)); // Установите синий цвет
    rect3->setData(0, "Cube");
    // Добавьте элементы на сцену
    this->addItem(rect1);
    this->addItem(rect2);
    this->addItem(rect3);

    QPixmap humanPixmap("E:/QT/Proj/labirint/human.png"); // Загружаем изображение человека (замените на ваш путь)
    QGraphicsPixmapItem *human = addPixmap(humanPixmap); // Добавляем изображение человека на сцену
    human->setPos(300, 300); // Устанавливаем начальную позицию человека
    human->setScale(0.05); // Установите масштаб (0.1 будет десятой частью размера, вы можете настроить его по вашему усмотрению)
    human->setData(0, "Human");

    // Создаем QGraphicsPixmapItem для телефона
    QPixmap phonePixmap("E:/QT/Proj/labirint/phone.png"); // Загружаем изображение телефона (замените на ваш путь)
    QGraphicsPixmapItem *phone = addPixmap(phonePixmap); // Добавляем изображение на сцену
    phone->setPos(150, 150); // Устанавливаем позицию элемента
    phone->setScale(0.05); // Установите масштаб (0.5 будет половиной размера, вы можете настроить его по вашему усмотрению)
    phoneItem = phone; //
    this->setFocus();

    walls[0] = addRect(QRectF(0,0,10,500),QPen(Qt::black), QBrush(QColor(220, 20, 60)));
    walls[1] = addRect(QRectF(800,0,10,500), QPen(Qt::black), QBrush(QColor(220, 20, 60)));
    walls[2] = addRect(QRectF(0,0,800,10), QPen(Qt::black), QBrush(QColor(220, 20, 60)));
    walls[3] = addRect(QRectF(0, 500, 800, 10), QPen(Qt::black), QBrush(QColor(220, 20, 60)));


    for(int i=0; i<4; i++)
        walls[i]->setData(0,"Wall");

    dx = 1;
    dy = 1;
    speed = 1;

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveMouse()));
    timer->start(10);
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Обработчик события нажатия кнопки мыши
    QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
    if (item != nullptr) {
        // Если прямоугольник был выбран, то установите его как перемещаемый
        selectedRect = dynamic_cast<QGraphicsRectItem *>(item);
    }

    QGraphicsScene::mousePressEvent(event);
}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // Обработчик события отпускания кнопки мыши
    if (selectedRect != nullptr) {
        selectedRect = nullptr; // Отмените выбор прямоугольника
    }

    QGraphicsScene::mouseReleaseEvent(event);
}

void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Обработчик перемещения мыши
    if (selectedRect != nullptr) {
        // Если прямоугольник выбран, переместите его в соответствии с движением мыши
        QPointF newPos = event->scenePos();
        selectedRect->setPos(newPos);
    }

    QGraphicsScene::mouseMoveEvent(event);
}
//void MyGraphicsScene::keyPressEvent(QKeyEvent *event)
//{
//    if (phoneItem != nullptr) {
//        // Если "телефон" выбран, обработайте события клавиш для его перемещения
//        qDebug() << "Key pressed:" << event->key();
//        QPointF newPos = phoneItem->pos();
//        switch (event->key()) {
//            case Qt::Key_W:
//                newPos.setY(newPos.y() - 10); // Двигаем вверх
//                break;
//            case Qt::Key_S:
//                newPos.setY(newPos.y() + 10); // Двигаем вниз
//                break;
//            case Qt::Key_A:
//                newPos.setX(newPos.x() - 10); // Двигаем влево
//                break;
//            case Qt::Key_D:
//                newPos.setX(newPos.x() + 10); // Двигаем вправо
//                break;
//            default:
//                break;
//        }
//        phoneItem->setPos(newPos);
//    }

//    QGraphicsScene::keyPressEvent(event);
//}
void MyGraphicsScene::MoveMouse(){
    QTransform transform = phoneItem->transform();
    transform.translate(dx,dy);
    phoneItem->setTransform(transform);
    QGraphicsItem* barrier = itemCollidesWith(phoneItem);
    transform=phoneItem->transform();
    if(barrier){
        if(barrier->data(0)=="Wall" || barrier->data(0)=="Cube"){
            dx = -dx;
            dy = -dy;
        }
    }
    if (barrier) {
        if(barrier->data(0)=="Human"){
            dx = -dx;
            dy = -dy;
            // Если есть столкновение, вы победили!
            QMessageBox::information(nullptr, "Победа", "Ты победил!");
            // Можете также завершить приложение или выполнить другие действия
        }

    }
}

/*void MyGraphicsScene::MoveMouse(){
    int randomDirection = qrand() % 4;

    // Устанавливаем текущее направление движения
        double targetDx = 0;
        double targetDy = 0;

        switch (randomDirection) {
            case 0: // Движение вверх
                targetDy = -5;
                break;
            case 1: // Движение вниз
                targetDy = 5;
                break;
            case 2: // Движение влево
                targetDx = -5;
                break;
            case 3: // Движение вправо
                targetDx = 5;
                break;
        }

        // Плавное изменение направления
        double stepSize = 0.5;
        dx = qBound(-5.0, dx + stepSize * (targetDx - dx), 5.0);
        dy = qBound(-5.0, dy + stepSize * (targetDy - dy), 5.0);

        // Перемещаем объект
        QPointF newPos = phoneItem->pos() + QPointF(dx, dy);
        phoneItem->setPos(newPos);

        // Проверка на столкновение с другими объектами
        QGraphicsItem* barrier = itemCollidesWith(phoneItem);
        if (barrier) {
            if (barrier->data(0) == "Wall" || barrier->data(0) == "Cube") {
                // При столкновении меняем направление
                dx = -dx;
                dy = -dy;
            }
        }
}*/
/*void MyGraphicsScene::moveObject(QGraphicsItem* item) {
    int dx = qrand() % 10 - 5; // Генерируем случайное число от -5 до 5 для изменения X-координаты
    int dy = qrand() % 10 - 5; // Генерируем случайное число от -5 до 5 для изменения Y-координаты

    QPointF newPos = item->pos() + QPointF(dx, dy);

    // Проверка на столкновение с другими объектами
    QGraphicsItem* collisionItem = itemCollidesWith(item);
    if (collisionItem != nullptr) {
        // Обработка столкновения, если необходимо
        if (collisionItem->data(0) == "Wall" || collisionItem->data(0) == "Cube") {
            dx = -dx;
            dy = -dy;
        }
    }

    item->setPos(newPos);
}*/
//void MyGraphicsScene::moveObject(QGraphicsItem* item) {
//    int dx = qrand() % 10 - 5; // Генерируем случайное число от -5 до 5 для изменения X-координаты
//    int dy = qrand() % 10 - 5; // Генерируем случайное число от -5 до 5 для изменения Y-координаты
//    QPointF newPos = item->pos() + QPointF(dx, dy);
//    item->setPos(newPos);

//    // Проверка на столкновение с другими объектами
//    QGraphicsItem* collisionItem = itemCollidesWith(item);
//    if (collisionItem != nullptr) {
//        // Обработка столкновения, если необходимо
//    }
//}
QGraphicsItem* MyGraphicsScene::itemCollidesWith(QGraphicsItem* item){
        QList<QGraphicsItem*> collisions = collidingItems(item);
        foreach (QGraphicsItem* it, collisions){
            if(it == item)
                continue;
            return it;
        }
        return nullptr;
}
