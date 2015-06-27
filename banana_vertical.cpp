#include "banana_vertical.h"

banana_vertical::banana_vertical(QWidget *parent):object(parent)
{
    type=21;
}

banana_vertical::~banana_vertical()
{

}

void banana_vertical::paint()
{
    label->setPixmap(QPixmap(":/banana_vertical.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
