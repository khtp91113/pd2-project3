#ifndef APPLE
#define APPLE
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class apple:public object
{
    Q_OBJECT
public:
    apple(QWidget *parent);
    ~apple();
    virtual void paint();
};

#endif // APPLE

