#include "watermelon_bomb.h"

watermelon_bomb::watermelon_bomb(QWidget *parent):object(parent)
{
    type=34;
}

watermelon_bomb::~watermelon_bomb()
{

}

void watermelon_bomb::paint()
{
    label->setPixmap(QPixmap(":/bomb_watermelon.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
