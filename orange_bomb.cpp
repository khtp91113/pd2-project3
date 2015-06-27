#include "orange_bomb.h"

orange_bomb::orange_bomb(QWidget *parent):object(parent)
{
    type=33;
}

orange_bomb::~orange_bomb()
{

}

void orange_bomb::paint()
{
    label->setPixmap(QPixmap(":/bomb_orange.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
