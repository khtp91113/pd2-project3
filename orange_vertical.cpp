#include "orange_vertical.h"

orange_vertical::orange_vertical(QWidget *parent):object(parent)
{
    type=23;
}

orange_vertical::~orange_vertical()
{

}

void orange_vertical::paint()
{
    label->setPixmap(QPixmap(":/orange_vertical.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
