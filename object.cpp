#include "object.h"
#include"QDebug"
object::object(QWidget *parent):w(parent)
{
    type=-1;
    label=new QLabel;
    button=new QPushButton;
    label->setParent(parent);
    button->setParent(parent);
}

object::~object()
{
    delete label;
    delete button;
}

bool object::operator==(const object&right)const
{
    if(type!=right.type)
        return false;
    return true;
}

