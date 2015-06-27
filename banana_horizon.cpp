#include "banana_horizon.h"

banana_horizon::banana_horizon(QWidget *parent):object(parent)
{
    type=11;
}

banana_horizon::~banana_horizon()
{

}

void banana_horizon::paint()
{
    label->setPixmap(QPixmap(":/banana_horizon.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
