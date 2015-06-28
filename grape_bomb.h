#ifndef GRAPE_BOMB_H
#define GRAPE_BOMB_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class grape_bomb:public object
{
    Q_OBJECT
public:
    grape_bomb(QWidget *parent);
    ~grape_bomb();
    virtual void paint(int type);
};

#endif // GRAPE_BOMB_H
