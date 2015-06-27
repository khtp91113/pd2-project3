#ifndef WATERMELON_HORIZON_H
#define WATERMELON_HORIZON_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class watermelon_horizon:public object
{
    Q_OBJECT
public:
    watermelon_horizon(QWidget *parent);
    ~watermelon_horizon();
    virtual void paint();
};

#endif // WATERMELON_HORIZON_H
