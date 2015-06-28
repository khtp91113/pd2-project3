#include "banana_star.h"

banana_star::banana_star(QWidget *parent):object(parent)
{
    type=41;
}

banana_star::~banana_star()
{
    delete label;
    delete button;
}

void banana_star::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/star_banana.png"));
    else
        label->setPixmap(QPixmap(":/star_banana_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
