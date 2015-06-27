#ifndef ORANGE
#define ORANGE
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>
class orange:public object
{
    Q_OBJECT
public:
    orange(QWidget *parent);
    ~orange();
    virtual void paint();

};
#endif // ORANGE

