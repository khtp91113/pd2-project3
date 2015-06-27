#ifndef BANANA_BOMB_H
#define BANANA_BOMB_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class banana_bomb:public object
{
    Q_OBJECT
public:
    banana_bomb(QWidget *parent);
    ~banana_bomb();
    virtual void paint();
};

#endif // BANANA_BOMB_H
