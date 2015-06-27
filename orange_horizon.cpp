#include "orange_horizon.h"

orange_horizon::orange_horizon(QWidget *parent):object(parent)
{
    type=13;
}

orange_horizon::~orange_horizon()
{

}

void orange_horizon::paint()
{
    label->setPixmap(QPixmap(":/orange_horizon.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
