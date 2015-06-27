#include "grape_bomb.h"

grape_bomb::grape_bomb(QWidget *parent):object(parent)
{
    type=32;
}

grape_bomb::~grape_bomb()
{

}

void grape_bomb::paint()
{
    label->setPixmap(QPixmap(":/bomb_grape.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
