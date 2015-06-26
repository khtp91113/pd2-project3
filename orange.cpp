#include "orange.h"

orange::orange(QWidget *parent):object(parent)
{
    set_v(3);
}
orange::~orange()
{

}

void orange::paint(int type)
{
    if(type==0)
    {
        label->setPixmap(QPixmap(":/orange.png"));
        label->setScaledContents(true);
        button->setFlat(true);
        button->setStyleSheet("background:transparent");
        button->raise();
    }
}

