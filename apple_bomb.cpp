#include "apple_bomb.h"

apple_bomb::apple_bomb(QWidget *parent):object(parent)
{
    type=30;
}

apple_bomb::~apple_bomb()
{

}

void apple_bomb::paint()
{
    label->setPixmap(QPixmap(":/bomb_apple.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
