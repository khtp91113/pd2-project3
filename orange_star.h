#ifndef ORANGE_STAR_H
#define ORANGE_STAR_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class orange_star:public object
{
    Q_OBJECT
public:
    orange_star(QWidget *parent);
    ~orange_star();
    virtual void paint(int type);
};

#endif // ORANGE_STAR_H
