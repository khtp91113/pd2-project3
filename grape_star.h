#ifndef GRAPE_STAR_H
#define GRAPE_STAR_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class grape_star:public object
{
    Q_OBJECT
public:
    grape_star(QWidget *parent);
    ~grape_star();
    virtual void paint();
};

#endif // GRAPE_STAR_H
