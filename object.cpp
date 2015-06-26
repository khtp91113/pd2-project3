#include "object.h"
#include"QDebug"
object::object(QWidget *parent):w(parent)
{
    v=-1;
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
void object::set_v(int a)
{
    v=a;
}

bool object::operator==(const object&right)const
{
    if(v!=right.v)
        return false;
    return true;
}

