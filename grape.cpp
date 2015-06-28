#include "grape.h"

grape::grape(QWidget *parent):object(parent)
{
    type=2;
    //connect(button,SIGNAL(clicked()),parent,SLOT(grape_button_click()));
}
grape::~grape()
{
    delete label;
    delete button;
}

void grape::paint(int type)
{
    if(type==0)
        label->setPixmap(QPixmap(":/grape.png"));
    else
        label->setPixmap(QPixmap(":/grape_pick.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}


