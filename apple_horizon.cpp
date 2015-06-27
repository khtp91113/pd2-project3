#include "apple_horizon.h"

apple_horizon::apple_horizon(QWidget *parent):object(parent)
{
    type=20;
}

apple_horizon::~apple_horizon()
{

}

void apple_horizon::paint()
{
    label->setPixmap(QPixmap(":/apple_horizon.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
