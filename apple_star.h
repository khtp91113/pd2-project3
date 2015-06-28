#ifndef APPLE_STAR_H
#define APPLE_STAR_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class apple_star:public object
{
    Q_OBJECT
public:
    apple_star(QWidget *parent);
    virtual ~apple_star();
    virtual void paint(int type);
};

#endif // APPLE_STAR_H
