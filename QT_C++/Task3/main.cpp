#include "sdiprogram_lybarskiy_zimin.h"
#include <QApplication>
#include <QTimer>
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
    QSplashScreen splash(QPixmap("E:/QT/Proj/lb.jpg"));
    SDIProgram_Lybarskiy_Zimin w;
   // w.show();
    splash.show();
    LoadModules(&splash);
    splash.finish(&w);
     w.show();
    return a.exec();
}
