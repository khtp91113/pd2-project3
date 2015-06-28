#ifndef GRAPE_HORIZON_H
#define GRAPE_HORIZON_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class grape_horizon:public object
{
    Q_OBJECT
public:
    grape_horizon(QWidget *parent);
    ~grape_horizon();
    virtual void paint(int type);
};

#endif // GRAPE_HORIZON_H
