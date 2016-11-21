#ifndef DRAWER_H
#define DRAWER_H

#include <QtGui>
#include <QToolBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QToolButton>


class Drawer : public QToolBox
{
    Q_OBJECT
public:
    Drawer( QWidget *parent=0, Qt::WindowFlags  f=0 );//���캯��
    ~Drawer();//��������
	
    QToolButton *toolButton1_1;//�������������İ���(ͼ��ʵ���Ͼ��ǰ���)
    QToolButton *toolButton1_2;
    QToolButton *toolButton1_3;
    QToolButton *toolButton1_4;
    QToolButton *toolButton1_5;
    QToolButton *toolButton2_1;
    QToolButton *toolButton2_2;
    QToolButton *toolButton3_1;
    QToolButton *toolButton3_2;
};


#endif
