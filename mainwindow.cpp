#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(550,650);
    w=new QWidget;
    image.load(":/start.jpg");
    w->setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(image.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    w->setPalette(pal);

    QFont f;
    f.setFamily("French Script MT");
    f.setPointSize(20);
    start=new QPushButton;
    connect(start,SIGNAL(clicked()),this,SLOT(game()));
    start->setParent(w);
    start->setGeometry(175,500,200,30);
    start->setText("Start");
    start->setFont(f);
    end=new QPushButton;
    connect(end,SIGNAL(clicked()),this,SLOT(button_end()));
    end->setParent(w);
    end->setGeometry(175,550,200,30);
    end->setText("End");
    end->setFont(f);
    QFont g;
    g.setFamily("Jokerman");
    g.setPointSize(30);
    QLabel *title=new QLabel;
    title->setParent(w);
    title->setText("<h2><font color=blue><center>Fruit Crush!!</center></font></h2>");
    title->setFont(g);
    title->setGeometry(80,100,400,200);

    this->setCentralWidget(w);

}

MainWindow::~MainWindow()
{

}

void MainWindow::button_end()
{
    QMediaPlayer *warning=new QMediaPlayer;
    warning->setMedia(QUrl("qrc:/warning.mp3"));
    warning->play();
    QMessageBox message(QMessageBox::NoIcon,"Quit","<h2>Are you sure you want to quit?</h2>",QMessageBox::Yes | QMessageBox::No);
    message.setIconPixmap(QPixmap(":/warning.jpg"));
    if(message.exec() == QMessageBox::Yes)
        this->close();
}

void MainWindow::game()
{
    for(int i=0;i<1;i++)
        for(int j=0;j<76;j++)
            value[i][j]=0;   
    delete w;
    w=new QWidget;
    image.load(":/back.jpg");
    w->setAutoFillBackground(true);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window,QBrush(image.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    w->setPalette(pal);
    for(int i=0;i<100;i++)
        obj[i]=new empty(w);
    set_place();
    for(int i=0;i<100;i++)
        obj[i]->paint(0);
    QLabel *base[100];
    for(int i=0;i<100;i++)
    {
        base[i]=new QLabel;
        base[i]->setParent(w);
        base[i]->lower();
    }
    for(int i=0;i<100;i++)
    {
        base[i]->setPixmap(QPixmap(":/base.png"));
        base[i]->setScaledContents(true);
        base[i]->setGeometry(20+i%10*52,570-i/10*52,50,50);
    }
    QFont f;
    f.setPointSize(30);
    f.setFamily("French Script MT");
    Time=new QLabel;
    Time->setParent(w);
    Time->setGeometry(10,25,200,70);
    Time->setText("<h2><font color=orange><center>Time</center></font></h2>");
    Time->setFont(f);
    Score=new QLabel;
    Score->setParent(w);
    Score->setGeometry(250,25,200,70);
    Score->setText("<h2><font color=red><center>Score</center></font></h2>");
    Score->setFont(f);
    this->setCentralWidget(w);
    game_start();
}

void MainWindow::set_place()
{
    for(int i=0;i<100;i++)
    {
        obj[i]->label->setGeometry(20+i%10*52,570-i/10*52,50,50);
        obj[i]->button->setGeometry(20+i%10*52,570-i/10*52,50,50);
    }
}

void MainWindow::elapse(int time)
{
    QTime t;
    t.start();
    while(t.elapsed()<time)
        QCoreApplication::processEvents();
}

void MainWindow::generate_first_board()
{
   srand(time(NULL));
   int board[100];
   int board_1[100]={0,3,2,0,1,4,0,1,2,1,
                     4,2,1,2,3,2,3,1,3,3,
                     4,1,4,4,0,3,3,4,0,3,
                     0,4,4,2,1,3,4,2,1,4,
                     1,1,2,0,1,4,2,0,1,0,
                     0,3,2,1,4,3,3,1,0,0,
                     1,0,0,2,0,2,2,3,2,1,
                     3,4,2,0,2,0,0,2,0,2,
                     4,3,4,3,1,3,0,0,3,3,
                     0,4,3,1,3,3,2,0,0,4};
   int board_2[100]={3,4,1,0,3,3,0,0,3,1,
                     4,3,3,1,4,2,1,3,2,4,
                     1,0,2,4,2,4,4,2,1,3,
                     4,3,0,1,2,2,1,0,3,4,
                     2,1,4,0,3,0,2,0,4,2,
                     2,1,1,3,1,2,2,4,3,2,
                     0,2,3,4,4,2,3,2,3,4,
                     0,4,0,3,3,4,3,4,2,3,
                     3,0,4,1,3,4,4,2,4,1,
                     2,0,3,0,2,1,3,1,2,2};
   int board_3[100]={2,1,3,3,4,1,4,1,3,4,
                     4,0,4,2,3,4,0,0,4,4,
                     2,1,1,3,3,2,3,2,1,2,
                     0,4,2,4,2,2,3,0,4,3,
                     2,0,4,2,2,3,0,1,4,1,
                     1,3,1,1,0,0,1,3,1,2,
                     2,2,3,4,1,0,4,3,0,3,
                     4,0,0,3,4,3,3,2,3,4,
                     2,1,3,0,3,1,2,3,1,4,
                     0,2,0,2,0,1,3,2,2,3};
   int rotate,type,select;
   select=rand()%3;
   switch(select)
   {
   case 0:
       for(int i=0;i<100;i++)
           board[i]=board_1[i];
       break;
   case 1:
       for(int i=0;i<100;i++)
           board[i]=board_2[i];
   default:
       for(int i=0;i<100;i++)
           board[i]=board_3[i];
       break;
   }

   type=rand()%4;
   switch(type)
   {
   case 0:
       for(int i=0;i<100;i++)
           value[0][i]=board[i];
       break;
   case 1:
       for(int i=0;i<100;i++)
       {
           if(board[i]==0)
               value[0][i]=1;
           else if(board[i]==1)
               value[0][i]=4;
           else if(board[i]==2)
               value[0][i]=3;
           else if(board[i]==3)
               value[0][i]=0;
           else
               value[0][i]=2;
       }
       break;
   case 2:
       for(int i=0;i<100;i++)
       {
           if(board[i]==0)
               value[0][i]=2;
           else if(board[i]==1)
               value[0][i]=0;
           else if(board[i]==2)
               value[0][i]=1;
           else if(board[i]==3)
               value[0][i]=4;
           else
               value[0][i]=3;
       }
       break;
   case 3:
       for(int i=0;i<100;i++)
       {
           if(board[i]==0)
               value[0][i]=4;
           else if(board[i]==1)
               value[0][i]=2;
           else if(board[i]==2)
               value[0][i]=3;
           else if(board[i]==3)
               value[0][i]=0;
           else
               value[0][i]=1;
       }
       break;
   default:
       for(int i=0;i<100;i++)
       {
           if(board[i]==0)
               value[0][i]=3;
           else if(board[i]==1)
               value[0][i]=0;
           else if(board[i]==2)
               value[0][i]=2;
           else if(board[i]==3)
               value[0][i]=1;
           else
               value[0][i]=4;
       }
       break;
   }
   rotate=rand()%3;
   int k;
   switch(rotate)
   {
   case 0:
       for(int i=0;i<100;i++)
           temp[i]=value[0][i];
       for(int i=0;i<100;i++)
           value[0][i]=temp[100-i-1];
       break;
   case 1:
       k=99;
       for(int i=0;i<100;i++)
           temp[i]=value[0][i];
       for(int i=0;i<100;i++)
       {
           value[0][i]=temp[k];
           k-=10;
           if(k<0)
               k+=99;
       }
       break;
   default:
       k=90;
       for(int i=0;i<100;i++)
           temp[i]=value[0][i];
       for(int i=0;i<100;i++)
       {
           value[0][i]=temp[k];
           k-=10;
           if(k<0)
               k+=101;
       }
       break;
   }
   for(int i=0;i<100;i++)
       delete obj[i];
   for(int i=0;i<100;i++)
   {
       if(value[0][i]==0)
           obj[i]=new apple(w);
       else if(value[0][i]==1)
           obj[i]=new banana(w);
       else if(value[0][i]==2)
           obj[i]=new grape(w);
       else if(value[0][i]==3)
           obj[i]=new orange(w);
       else
           obj[i]=new watermelon(w);
   }
   for(int i=0;i<100;i++)
   {
       obj[i]->paint(0);
       obj[i]->label->show();
   }
   set_place();
   QPropertyAnimation *animation[10];
   for(int i=0;i<100;i++)
       animation[i]=new QPropertyAnimation(obj[i]->label,"geometry");
   for(int i=0;i<100;i++)
   {
       if(i<10)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),102,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),570,50,50));
       }
       else if(i<20)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),50,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),518,50,50));
       }
       else if(i<30)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),-2,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),466,50,50));
       }
       else if(i<40)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),-54,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),414,50,50));
       }
       else if(i<50)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),-106,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),362,50,50));
       }
       else if(i<60)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),-158,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),310,50,50));
       }
       else if(i<70)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),-210,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),258,50,50));
       }
       else if(i<80)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),-262,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),206,50,50));
       }
       else if(i<90)
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),-314,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),154,50,50));
       }
       else
       {
           animation[i]->setDuration(1000);
           animation[i]->setStartValue(QRect(20+52*(i%10),-366,50,50));
           animation[i]->setEndValue(QRect(20+52*(i%10),102,50,50));
       }
   }
   QParallelAnimationGroup *group=new QParallelAnimationGroup;
   for(int i=0;i<100;i++)
       group->addAnimation(animation[i]);
   group->start();
   elapse(1200);
   QLabel *START=new QLabel;
   START->setText("<h2><center>START</center></h2>");
   QFont f;
   f.setPointSize(60);
   f.setFamily("French Script MT");
   START->setFont(f);
   START->setParent(this);
   START->setGeometry(70,300,400,100);
   START->show();
   elapse(600);
   START->setVisible(false);
}

void MainWindow::game_start()
{
    generate_first_board();
}

void MainWindow::judge()
{

}
