#include "apple_star.h"

apple_star::apple_star(QWidget *parent):object(parent)
{
    type=40;
}

apple_star::~apple_star()
{
    delete label;
    delete button;
}

void apple_star::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/star_apple.png"));
    else
        label->setPixmap(QPixmap(":/star_apple_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
