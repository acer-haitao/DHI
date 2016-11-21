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
    Drawer( QWidget *parent=0, Qt::WindowFlags  f=0 );//构造函数
    ~Drawer();//析构函数
	
    QToolButton *toolButton1_1;//定义各个抽屉里的按键(图像实质上就是按键)
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
