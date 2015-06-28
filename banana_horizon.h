#ifndef BANANA_HORIZON_H
#define BANANA_HORIZON_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class banana_horizon:public object
{
    Q_OBJECT
public:
    banana_horizon(QWidget *parent);
    ~banana_horizon();
    virtual void paint(int type);
};

#endif // BANANA_HORIZON_H
