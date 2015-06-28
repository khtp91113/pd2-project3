#include "apple_bomb.h"

apple_bomb::apple_bomb(QWidget *parent):object(parent)
{
    type=30;
}

apple_bomb::~apple_bomb()
{
    delete label;
    delete button;
}

void apple_bomb::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/bomb_apple.png"));
    else
        label->setPixmap(QPixmap(":/bomb_apple_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
