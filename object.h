#ifndef OBJECT
#define OBJECT
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QObject>

class object:public QWidget
{
    Q_OBJECT

public:
    object(QWidget *parent=0);
    ~object();
    virtual void paint(int type)=0;
    QLabel *label;
    QPushButton *button;
    QWidget *w;
    bool operator==(const object&)const;
    int type,click;
};


#endif // OBJECT

