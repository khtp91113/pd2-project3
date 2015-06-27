#include "banana.h"

banana::banana(QWidget *parent):object(parent)
{
    type=1;
}
banana::~banana()
{

}

void banana::paint()
{
    label->setPixmap(QPixmap(":/banana.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}

