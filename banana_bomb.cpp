#include "banana_bomb.h"

banana_bomb::banana_bomb(QWidget *parent):object(parent)
{
    type=31;
}

banana_bomb::~banana_bomb()
{
    delete label;
    delete button;
}

void banana_bomb::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/bomb_banana.png"));
    else
        label->setPixmap(QPixmap(":/bomb_banana_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
