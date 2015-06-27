#include "watermelon_horizon.h"

watermelon_horizon::watermelon_horizon(QWidget *parent):object(parent)
{
    type=14;
}

watermelon_horizon::~watermelon_horizon()
{

}

void watermelon_horizon::paint()
{
    label->setPixmap(QPixmap(":/watermelon_horizon.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
