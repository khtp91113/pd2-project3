#include "orange_star.h"

orange_star::orange_star(QWidget *parent):object(parent)
{
    type=43;
}

orange_star::~orange_star()
{
    delete label;
    delete button;
}

void orange_star::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/star_orange.png"));
    else
        label->setPixmap(QPixmap(":/star_orange_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
