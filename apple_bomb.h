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
    virtual ~apple_bomb();
    virtual void paint(int type);
};

#endif // APPLE_BOMB_H
