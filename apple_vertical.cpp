#include "apple_vertical.h"

apple_vertical::apple_vertical(QWidget *parent):object(parent)
{
    type=10;
}

apple_vertical::~apple_vertical()
{

}

void apple_vertical::paint()
{
    label->setPixmap(QPixmap(":/apple_vertical.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
