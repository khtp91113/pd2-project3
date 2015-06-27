#include "banana_bomb.h"

banana_bomb::banana_bomb(QWidget *parent):object(parent)
{
    type=31;
}

banana_bomb::~banana_bomb()
{

}

void banana_bomb::paint()
{
    label->setPixmap(QPixmap(":/bomb_banana.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
