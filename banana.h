#ifndef BANANA
#define BANANA
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>
class banana:public object
{
    Q_OBJECT
public:
    banana(QWidget *parent);
    ~banana();
    virtual void paint(int type);
   // virtual bool *operator==(const object*)const;
};
#endif // BANANA

