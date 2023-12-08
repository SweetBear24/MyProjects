#include "comics.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QTime>
void LoadModules(QSplashScreen* psplash){
    QTime time;
    time.start();
    for(int i=0; i<100 ; ){
        if(time.elapsed() > 40){
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: " + QString::number(i)+"%", Qt::AlignCenter | Qt::AlignBottom, Qt::cyan);
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("SettingsComicsPro");
    QApplication::setApplicationName("ComicsPro");

    QSplashScreen splash(QPixmap("E:/QT/Proj/ComicsPro3/screensaver.jpg"));
    comics w;
    splash.show();
    LoadModules(&splash);
    splash.finish(&w);
    w.show();

    return a.exec();
}
