#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QtGui>

class Geometry : public QDialog//派生类，基类
{
    Q_OBJECT   //若后面使用信号与插槽就必须声明该宏
public:
    Geometry();//定义类中各个函数和控件
    
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QLabel *label8;
    QLabel *label9;

    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *frameGeoLabel;
    QLabel *posLabel;
    QLabel *geoLabel;
    QLabel *widthLabel;
    QLabel *heightLabel;
    QLabel *rectLabel;
    QLabel *sizeLabel;
    
    void updateLabel();

protected:
    void moveEvent(QMoveEvent *);
    void resizeEvent(QResizeEvent *);

};

#endif // GEOMETRY_H
