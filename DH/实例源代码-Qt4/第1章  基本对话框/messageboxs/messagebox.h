#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>

class QLabel;

class MessageBox : public QDialog
{
    Q_OBJECT
public:
    MessageBox(QWidget *parent=0);

public slots:
    void slotQuestion();
    void slotInformation();
    void slotWarning();
    void slotCritical();
    void slotAbout();
    void slotAboutQt();
    void slotCustom();
    
private:
    QLabel *label;//ֻ�б����еĺ�������ʹ�ã���粻�������������˽�г�Ա
};

#endif  // MESSAGEBOX_H
