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
    virtual ~apple_vertical();
    virtual void paint(int type);
};

#endif // APPLE_VERTICAL_H


