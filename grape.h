#ifndef GRAPE
#define GRAPE
#include "object.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>
class grape:public object
{
    Q_OBJECT
public:
    grape(QWidget *parent);
    ~grape();
    virtual void paint(int type);
   // virtual bool *operator==(const object*)const;
};
#endif // GRAPE
