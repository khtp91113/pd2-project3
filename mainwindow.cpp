#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(550,650);
    w=new QWidget;
    image.load(":/start.png");
    w->setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(image.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    w->setPalette(pal);

    start=new QPushButton;
    connect(start,SIGNAL(clicked()),this,SLOT(game()));
    start->setParent(w);
    start->setGeometry(175,500,200,30);
    start->setText("Start");
    end=new QPushButton;
    connect(end,SIGNAL(clicked()),this,SLOT(close()));
    end->setParent(w);
    end->setGeometry(175,550,200,30);
    end->setText("End");

    this->setCentralWidget(w);

}

MainWindow::~MainWindow()
{

}

void MainWindow::game()
{
    delete w;
    w=new QWidget;
    for(int i=0;i<76;i++)
    {
        label[i]=new QLabel;
        label[i]->setParent(w);
        button[i]=new QPushButton;
        button[i]->setParent(w);
    }
    for(int i=0,k=0,j=0;i<30;i++)
    {
        if(i%10==0)
            k++;
        j=i%10;
        label[i]->setGeometry(25+50*(k-1),100+j*50,50,50);
        button[i]->setGeometry(25+50*(k-1),100+j*50,50,50);
        button[i]->setFlat(true);
        button[i]->setStyleSheet("background:transparent");
        button[i]->raise();
    }
    for(int i=46,k=7,j=0;i<76;i++)
    {
        if((i-6)%10==0)
            k++;
        j=(i-6)%10;
        label[i]->setGeometry(25+50*(k-1),100+j*50,50,50);
        button[i]->setGeometry(25+50*(k-1),100+j*50,50,50);
        button[i]->setFlat(true);
        button[i]->setStyleSheet("background:transparent");
        button[i]->raise();
    }
    for(int i=30,k=3,j=0;i<46;i++)
    {
        if((i-2)%4==0)
            k++;
        j=(i-2)%4+3;
        label[i]->setGeometry(25+50*(k-1),100+j*50,50,50);
        button[i]->setGeometry(25+50*(k-1),100+j*50,50,50);
        button[i]->setFlat(true);
        button[i]->setStyleSheet("background:transparent");
        button[i]->raise();
    }
    this->setCentralWidget(w);
}
