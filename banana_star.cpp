#include "banana_star.h"

banana_star::banana_star(QWidget *parent):object(parent)
{
    type=41;
}

banana_star::~banana_star()
{

}

void banana_star::paint()
{
    label->setPixmap(QPixmap(":/star_banana.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
