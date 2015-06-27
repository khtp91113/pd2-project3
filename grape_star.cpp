#include "grape_star.h"

grape_star::grape_star(QWidget *parent):object(parent)
{
    type=42;
}

grape_star::~grape_star()
{

}

void grape_star::paint()
{
    label->setPixmap(QPixmap(":/star_grape.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
