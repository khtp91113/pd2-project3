#include "grape.h"

grape::grape(QWidget *parent):object(parent)
{
    type=2;
    //connect(button,SIGNAL(clicked()),parent,SLOT(grape_button_click()));
}
grape::~grape()
{

}

void grape::paint()
{
    label->setPixmap(QPixmap(":/grape.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}


