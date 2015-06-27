#ifndef APPLE_BOMB_H
#define APPLE_BOMB_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class apple_bomb:public object
{
    Q_OBJECT
public:
    apple_bomb(QWidget *parent);
    ~apple_bomb();
    virtual void paint();
};

#endif // APPLE_BOMB_H
