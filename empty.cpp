#include "empty.h"
#include "QDebug"
empty::empty(QWidget *parent):object(parent)
{
}
empty::~empty()
{

}

void empty::paint()
{
    label->setPixmap(QPixmap(":/base.png"));
    label->setScaledContents(true);
    label->setFixedSize(50,50);
    button->setFixedSize(50,50);
    button->setFlat(true);
    button->setStyleSheet("background:transparent");
    button->raise();
}
