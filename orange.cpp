#include "orange.h"

orange::orange(QWidget *parent):object(parent)
{
    type=3;
}
orange::~orange()
{

}

void orange::paint()
{
    label->setPixmap(QPixmap(":/orange.png"));
    label->setScaledContents(true);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}


