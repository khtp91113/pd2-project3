#ifndef APPLE_VERTICAL_H
#define APPLE_VERTICAL_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class apple_vertical:public object
{
    Q_OBJECT
public:
    apple_vertical(QWidget *parent);
    ~apple_vertical();
    virtual void paint();
};

#endif // APPLE_VERTICAL_H


