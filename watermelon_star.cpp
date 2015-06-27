#include "watermelon_star.h"

watermelon_star::watermelon_star(QWidget *parent):object(parent)
{
    type=44;
}

watermelon_star::~watermelon_star()
{

}

void watermelon_star::paint()
{
    label->setPixmap(QPixmap(":/star_watermelon.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
