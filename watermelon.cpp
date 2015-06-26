#include "watermelon.h"

watermelon::watermelon(QWidget *parent):object(parent)
{
    set_v(4);
}
watermelon::~watermelon()
{

}

void watermelon::paint(int type)
{
    if(type==0)
    {
        label->setPixmap(QPixmap(":/watermelon.png"));
        label->setScaledContents(true);
        button->setFlat(true);
        button->setStyleSheet("background:transparent");
        button->raise();
    }
}

