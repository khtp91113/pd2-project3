#include "watermelon_vertical.h"

watermelon_vertical::watermelon_vertical(QWidget *parent):object(parent)
{
    type=24;
}

watermelon_vertical::~watermelon_vertical()
{

}

void watermelon_vertical::paint()
{
    label->setPixmap(QPixmap(":/watermelon_vertical.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
