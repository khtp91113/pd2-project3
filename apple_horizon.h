#ifndef APPLE_HORIZON_H
#define APPLE_HORIZON_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class apple_horizon:public object
{
    Q_OBJECT
public:
    apple_horizon(QWidget *parent);
    ~apple_horizon();
    virtual void paint();
};

#endif // APPLE_HORIZON_H
