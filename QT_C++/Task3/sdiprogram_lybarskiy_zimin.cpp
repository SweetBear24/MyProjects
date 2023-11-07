#include "sdiprogram_lybarskiy_zimin.h"
#include "ui_sdiprogram_lybarskiy_zimin.h"

SDIProgram_Lybarskiy_Zimin::SDIProgram_Lybarskiy_Zimin(QWidget *parent) : QMainWindow(parent){

    QMenu* pmnuFile = new QMenu("&File");
    QMenu* pmnuHelp = new QMenu("&Help");

    DocWindow_Lybarskiy_Zimin* pdoc = new DocWindow_Lybarskiy_Zimin;

    pmnuFile->addAction("&Open...",
                       pdoc,
                       SLOT(slotLoad()),
                       QKeySequence("CTRL+O")
                       );
    pmnuFile->addAction("&Save",
                       pdoc,
                       SLOT(slotSave()),
                       QKeySequence("CTRL+S")
                       );
    pmnuFile->addAction("&Save As...",
                       pdoc,
                       SLOT(slotSaveAs()),
                       QKeySequence("CTRL+Shift+S")
                       );

    pmnuFile->addAction("&Color",
                        pdoc,
                        SLOT(Color()),
                        QKeySequence("CTRL+Shift+S")
                        );

    pmnuFile->addSeparator();
    pmnuFile->addAction("&Quit",
                       qApp,
                       SLOT(quit()),
                       QKeySequence("CTRL+Q")
                       );
    pmnuHelp->addAction("&Help",
                        this,
                        SLOT(slotAbout()),
                        QKeySequence(Qt::Key_F1)
                        );

    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuHelp);

    setCentralWidget(pdoc);

    connect(pdoc,
            SIGNAL(changeWindowTitle(const QString&)),
            SLOT(slotChangeWindowTitle(const QString&))
            );
    statusBar()->showMessage("Ready",2000);
}
void SDIProgram_Lybarskiy_Zimin :: slotAbout(){
    QMessageBox::about(this, "About", "Zimin_Lybarskiy/IP-117");
}

void SDIProgram_Lybarskiy_Zimin :: slotChangeWindowTitle(const QString& str){
    setWindowTitle(str);
}
void DocWindow_Lybarskiy_Zimin :: Color(){
    QColor color = QColorDialog::getColor(Qt::red,this);
    setTextColor(color);
}
SDIProgram_Lybarskiy_Zimin::~SDIProgram_Lybarskiy_Zimin()
{
    delete ui;
}


