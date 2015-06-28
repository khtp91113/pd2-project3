#include "watermelon_bomb.h"

watermelon_bomb::watermelon_bomb(QWidget *parent):object(parent)
{
    type=34;
}

watermelon_bomb::~watermelon_bomb()
{
    delete label;
    delete button;
}

void watermelon_bomb::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/bomb_watermelon.png"));
    else
        label->setPixmap(QPixmap(":/bomb_watermelon_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
