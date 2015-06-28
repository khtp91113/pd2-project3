#ifndef WATERMELON_STAR_H
#define WATERMELON_STAR_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class watermelon_star:public object
{
    Q_OBJECT
public:
    watermelon_star(QWidget *parent);
    ~watermelon_star();
    virtual void paint(int type);
};

#endif // WATERMELON_STAR_H
