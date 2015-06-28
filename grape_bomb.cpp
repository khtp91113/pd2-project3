#include "grape_bomb.h"

grape_bomb::grape_bomb(QWidget *parent):object(parent)
{
    type=32;
}

grape_bomb::~grape_bomb()
{
    delete label;
    delete button;
}

void grape_bomb::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/bomb_grape.png"));
    else
        label->setPixmap(QPixmap(":/bomb_grape_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
