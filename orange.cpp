#include "orange.h"

orange::orange(QWidget *parent):object(parent)
{
    type=3;
}
orange::~orange()
{
    delete label;
    delete button;
}

void orange::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/orange.png"));
    else
        label->setPixmap(QPixmap(":/orange_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}


