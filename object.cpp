#include "object.h"
#include"QDebug"
object::object(QWidget *parent):w(parent)
{
    label=new QLabel;
    button=new QPushButton;
    label->setParent(parent);
    button->setParent(parent);
}

object::~object()
{
    /*delete button;
    delete label;*/
}

bool object::operator==(const object&right)const
{
    if(type!=right.type)
        return false;
    return true;
}

