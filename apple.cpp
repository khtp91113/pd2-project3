#include "apple.h"

apple::apple(QWidget *parent):object(parent)
{
    type=0;
}
apple::~apple()
{
    delete label;
    delete button;
}

void apple::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/apple.png"));
    else
        label->setPixmap(QPixmap(":/apple_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}

