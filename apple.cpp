#include "apple.h"

apple::apple(QWidget *parent):object(parent)
{
    set_v(0);
}
apple::~apple()
{

}

void apple::paint(int type)
{
    if(type==0)
    {
        label->setPixmap(QPixmap(":/apple.png"));
        label->setScaledContents(true);
        label->setFixedSize(50,50);
        button->setFixedSize(50,50);
        button->setFlat(true);
        button->setStyleSheet("background:transparent");
        button->raise();
    }
    if(type==1)
    {
        label->setPixmap(QPixmap(":/apple.png"));
        label->setScaledContents(true);
        label->setFixedSize(50,50);
        button->setFixedSize(50,50);
        button->setFlat(true);
        button->setStyleSheet("background:transparent");
        button->raise();
    }
}


