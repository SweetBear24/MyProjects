#ifndef DOCWINDOW_LYBARSKIY_ZIMIN_H
#define DOCWINDOW_LYBARSKIY_ZIMIN_H

#include<QTextEdit>
#include<QFileDialog>
#include <QTextStream>

class DocWindow_Lybarskiy_Zimin : public QTextEdit{
    Q_OBJECT
private:
    QString m_strFileName;

public:
    DocWindow_Lybarskiy_Zimin(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void Color();
};

#endif // DOCWINDOW_LYBARSKIY_ZIMIN_H
