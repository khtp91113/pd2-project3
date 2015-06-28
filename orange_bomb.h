#ifndef ORANGE_BOMB_H
#define ORANGE_BOMB_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class orange_bomb:public object
{
    Q_OBJECT
public:
    orange_bomb(QWidget *parent);
    ~orange_bomb();
    virtual void paint(int type);
};

#endif // ORANGE_BOMB_H
