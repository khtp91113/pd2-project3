#include "grape.h"

grape::grape(QWidget *parent):object(parent)
{
    set_v(2);
}
grape::~grape()
{

}

void grape::paint(int type)
{
    if(type==0)
    {
        label->setPixmap(QPixmap(":/grape.png"));
        label->setScaledContents(true);
        button->setFlat(true);
        button->setStyleSheet("background:transparent");
        button->raise();
    }
}

