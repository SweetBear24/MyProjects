#include "mygraphicsscene.h"
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyGraphicsScene *scene = new MyGraphicsScene;

    QGraphicsView view(scene);
    view.show();

    int result = app.exec();

    // Не забудьте освободить память после использования сцены
    delete scene;

    return result;
}
