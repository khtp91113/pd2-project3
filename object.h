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
    void set_v(int a);
    bool operator==(const object&)const;
    int v;
};


#endif // OBJECT

