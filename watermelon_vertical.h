#ifndef WATERMELON_VERTICAL_H
#define WATERMELON_VERTICAL_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class watermelon_vertical:public object
{
    Q_OBJECT
public:
    watermelon_vertical(QWidget *parent);
    ~watermelon_vertical();
    virtual void paint();
};

#endif // WATERMELON_VERTICAL_H
