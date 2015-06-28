#include "banana_vertical.h"

banana_vertical::banana_vertical(QWidget *parent):object(parent)
{
    type=21;
}

banana_vertical::~banana_vertical()
{
    delete label;
    delete button;
}

void banana_vertical::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/vertical_banana.png"));
    else
        label->setPixmap(QPixmap(":/vertical_banana_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
