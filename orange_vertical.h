#ifndef ORANGE_VERTICAL_H
#define ORANGE_VERTICAL_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class orange_vertical:public object
{
    Q_OBJECT
public:
    orange_vertical(QWidget *parent);
    ~orange_vertical();
    virtual void paint(int type);
};

#endif // ORANGE_VERTICAL_H
