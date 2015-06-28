#include "grape_star.h"

grape_star::grape_star(QWidget *parent):object(parent)
{
    type=42;
}

grape_star::~grape_star()
{
    delete label;
    delete button;
}

void grape_star::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/star_grape.png"));
    else
        label->setPixmap(QPixmap(":/star_grape_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
