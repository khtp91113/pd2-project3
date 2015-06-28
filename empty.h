#ifndef EMPTY
#define EMPTY
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class empty:public object
{
    Q_OBJECT
public:
    empty(QWidget *parent);
    ~empty();
    virtual void paint(int type);
};
#endif // EMPTY

