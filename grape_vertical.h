#ifndef GRAPE_VERTICAL_H
#define GRAPE_VERTICAL_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class grape_vertical:public object
{
    Q_OBJECT
public:
    grape_vertical(QWidget *parent);
    ~grape_vertical();
    virtual void paint();
};

#endif // GRAPE_VERTICAL_H
