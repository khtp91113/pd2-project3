#ifndef BANANA_STAR_H
#define BANANA_STAR_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class banana_star:public object
{
    Q_OBJECT
public:
    banana_star(QWidget *parent);
    ~banana_star();
    virtual void paint();
};

#endif // BANANA_STAR_H
