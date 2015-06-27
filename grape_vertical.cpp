#include "grape_vertical.h"

grape_vertical::grape_vertical(QWidget *parent):object(parent)
{
    type=22;
}

grape_vertical::~grape_vertical()
{

}

void grape_vertical::paint()
{
    label->setPixmap(QPixmap(":/grape_vertical.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
