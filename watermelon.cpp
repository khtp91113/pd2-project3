#include "watermelon.h"

watermelon::watermelon(QWidget *parent):object(parent)
{
    type=4;
}
watermelon::~watermelon()
{

}

void watermelon::paint()
{
    label->setPixmap(QPixmap(":/watermelon.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}


