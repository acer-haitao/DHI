#ifndef TABLE_H
#define TABLE_H

#include <QtGui>
#include <QTableWidget>
#include <QLabel>
#include <QDateTimeEdit>
#include  <QComboBox >
#include <QSpinBox >


class Table : public QTableWidget
{
    Q_OBJECT
public:
    Table();
    ~Table();
};


#endif // TABLE_H
