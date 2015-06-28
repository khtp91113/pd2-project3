#include "watermelon_star.h"

watermelon_star::watermelon_star(QWidget *parent):object(parent)
{
    type=44;
}

watermelon_star::~watermelon_star()
{
    delete label;
    delete button;
}

void watermelon_star::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/star_watermelon.png"));
    else
        label->setPixmap(QPixmap(":/star_watermelon_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
