#ifndef ORANGE_HORIZON_H
#define ORANGE_HORIZON_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class orange_horizon:public object
{
    Q_OBJECT
public:
    orange_horizon(QWidget *parent);
    ~orange_horizon();
    virtual void paint();
};

#endif // ORANGE_HORIZON_H
