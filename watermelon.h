#ifndef WATERMELON
#define WATERMELON
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>
class watermelon:public object
{
    Q_OBJECT
public:
    watermelon(QWidget *parent);
    ~watermelon();
    virtual void paint(int type);
 //   virtual bool *operator==(const object*)const;
};
#endif // WATERMELON

