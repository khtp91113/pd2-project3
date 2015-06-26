#include "banana.h"

banana::banana(QWidget *parent):object(parent)
{
    set_v(1);
}
banana::~banana()
{

}

void banana::paint(int type)
{
    if(type==0)
    {
        label->setPixmap(QPixmap(":/banana.png"));
        label->setScaledContents(true);
        button->setFlat(true);
        button->setStyleSheet("background:transparent");
        button->raise();
    }
}

