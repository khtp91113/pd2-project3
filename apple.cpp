#include "apple.h"

apple::apple(QWidget *parent):object(parent)
{
    type=0;
}
apple::~apple()
{

}

void apple::paint()
{
    label->setPixmap(QPixmap(":/apple.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}

