#include "banana.h"

banana::banana(QWidget *parent):object(parent)
{
    type=1;
}
banana::~banana()
{
    delete label;
    delete button;
}

void banana::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/banana.png"));
    else
        label->setPixmap(QPixmap(":/banana_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}

