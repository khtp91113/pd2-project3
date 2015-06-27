#include "orange_star.h"

orange_star::orange_star(QWidget *parent):object(parent)
{
    type=43;
}

orange_star::~orange_star()
{

}

void orange_star::paint()
{
    label->setPixmap(QPixmap(":/star_orange.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
