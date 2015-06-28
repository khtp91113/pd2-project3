#include "watermelon.h"

watermelon::watermelon(QWidget *parent):object(parent)
{
    type=4;
}
watermelon::~watermelon()
{
    delete label;
    delete button;
}

void watermelon::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/watermelon.png"));
    else
        label->setPixmap(QPixmap(":/watermelon_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}


