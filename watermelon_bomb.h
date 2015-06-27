#ifndef WATERMELON_BOMB_H
#define WATERMELON_BOMB_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class watermelon_bomb:public object
{
    Q_OBJECT
public:
    watermelon_bomb(QWidget *parent);
    ~watermelon_bomb();
    virtual void paint();
};

#endif // WATERMELON_BOMB_H
