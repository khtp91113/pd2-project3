#ifndef BANANA_VERTICAL_H
#define BANANA_VERTICAL_H
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class banana_vertical:public object
{
    Q_OBJECT
public:
    banana_vertical(QWidget *parent);
    ~banana_vertical();
    virtual void paint(int type);
};

#endif // BANANA_VERTICAL_H
