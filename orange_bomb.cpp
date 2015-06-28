#include "orange_bomb.h"

orange_bomb::orange_bomb(QWidget *parent):object(parent)
{
    type=33;
}

orange_bomb::~orange_bomb()
{
    delete label;
    delete button;
}

void orange_bomb::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/bomb_orange.png"));
    else
        label->setPixmap(QPixmap(":/bomb_orange_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
