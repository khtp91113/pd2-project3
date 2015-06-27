#include "grape_horizon.h"

grape_horizon::grape_horizon(QWidget *parent):object(parent)
{
    type=12;
}

grape_horizon::~grape_horizon()
{

}

void grape_horizon::paint()
{
    label->setPixmap(QPixmap(":/grape_horizon.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
