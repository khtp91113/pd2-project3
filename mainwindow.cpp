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
        obj[i]->paint();
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
                     1,1,3,2,1,0,1,3,1,2,
                     2,2,3,4,1,0,4,3,0,3,
                     4,0,0,3,4,3,3,2,3,4,
                     2,1,3,0,3,1,2,3,1,4,
                     0,3,0,1,0,1,3,2,2,3};
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
   int k,temp[100]={0};
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
       obj[i]->paint();
       obj[i]->label->show();
   }
   set_place();
   for(int i=0;i<100;i++)
       value[1][i]=0;
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
    signal=new QSignalMapper(this);
    for(int i=0;i<100;i++)
    {
        connect(obj[i]->button,SIGNAL(clicked()),signal,SLOT(map()));
        signal->setMapping(obj[i]->button,i);
    }
    connect(signal,SIGNAL(mapped(int)),this,SLOT(button_click(int)));
}

void MainWindow::judge(int p1,int p2)
{
    int effort=0;

    if(*obj[p1]==*obj[p2])
    {
        QPropertyAnimation *animation_2,*animation_3;
        animation_2=new QPropertyAnimation(obj[p1]->label,"geometry");
        animation_3=new QPropertyAnimation(obj[p2]->label,"geometry");
        switch(value[0][p1])
        {
        case 0:
            obj[p2]->label->setPixmap(QPixmap(":/apple.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 1:
            obj[p2]->label->setPixmap(QPixmap(":/banana.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 2:
            obj[p2]->label->setPixmap(QPixmap(":/grape.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 3:
            obj[p2]->label->setPixmap(QPixmap(":/orange.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 4:
            obj[p2]->label->setPixmap(QPixmap(":/watermelon.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 10:
            obj[p2]->label->setPixmap(QPixmap(":/horizon_apple.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 11:
            obj[p2]->label->setPixmap(QPixmap(":/horizon_banana.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 12:
            obj[p2]->label->setPixmap(QPixmap(":/horizon_grape.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 13:
            obj[p2]->label->setPixmap(QPixmap(":/horizon_orange.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 14:
            obj[p2]->label->setPixmap(QPixmap(":/horizon_watermelon.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 20:
            obj[p2]->label->setPixmap(QPixmap(":/vertical_apple.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 21:
            obj[p2]->label->setPixmap(QPixmap(":/vertical_banana.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 22:
            obj[p2]->label->setPixmap(QPixmap(":/vertical_grape.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 23:
            obj[p2]->label->setPixmap(QPixmap(":/vertical_orange.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 24:
            obj[p2]->label->setPixmap(QPixmap(":/vertical_watermelon.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 30:
            obj[p2]->label->setPixmap(QPixmap(":/bomb_apple.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 31:
            obj[p2]->label->setPixmap(QPixmap(":/bomb_banana.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 32:
            obj[p2]->label->setPixmap(QPixmap(":/bomb_grape.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 33:
            obj[p2]->label->setPixmap(QPixmap(":/bomb_orange.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 34:
            obj[p2]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 40:
            obj[p2]->label->setPixmap(QPixmap(":/star_apple.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 41:
            obj[p2]->label->setPixmap(QPixmap(":/star_banana.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 42:
            obj[p2]->label->setPixmap(QPixmap(":/star_grape.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 43:
            obj[p2]->label->setPixmap(QPixmap(":/star_orange.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        case 44:
            obj[p2]->label->setPixmap(QPixmap(":/star_watermelon.png"));
            obj[p2]->label->setScaledContents(true);
            break;
        }
        switch(value[0][p2])
        {

        case 0:
            obj[p1]->label->setPixmap(QPixmap(":/apple.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 1:
            obj[p1]->label->setPixmap(QPixmap(":/banana.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 2:
            obj[p1]->label->setPixmap(QPixmap(":/grape.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 3:
            obj[p1]->label->setPixmap(QPixmap(":/orange.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 4:
            obj[p1]->label->setPixmap(QPixmap(":/watermelon.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 10:
            obj[p1]->label->setPixmap(QPixmap(":/horizon_apple.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 11:
            obj[p1]->label->setPixmap(QPixmap(":/horizon_banana.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 12:
            obj[p1]->label->setPixmap(QPixmap(":/horizon_grape.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 13:
            obj[p1]->label->setPixmap(QPixmap(":/horizon_orange.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 14:
            obj[p1]->label->setPixmap(QPixmap(":/horizon_watermelon.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 20:
            obj[p1]->label->setPixmap(QPixmap(":/vertical_apple.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 21:
            obj[p1]->label->setPixmap(QPixmap(":/vertical_banana.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 22:
            obj[p1]->label->setPixmap(QPixmap(":/vertical_grape.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 23:
            obj[p1]->label->setPixmap(QPixmap(":/vertical_orange.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 24:
            obj[p1]->label->setPixmap(QPixmap(":/vertical_watermelon.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 30:
            obj[p1]->label->setPixmap(QPixmap(":/bomb_apple.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 31:
            obj[p1]->label->setPixmap(QPixmap(":/bomb_banana.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 32:
            obj[p1]->label->setPixmap(QPixmap(":/bomb_grape.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 33:
            obj[p1]->label->setPixmap(QPixmap(":/bomb_orange.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 34:
            obj[p1]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 40:
            obj[p1]->label->setPixmap(QPixmap(":/star_apple.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 41:
            obj[p1]->label->setPixmap(QPixmap(":/star_banana.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 42:
            obj[p1]->label->setPixmap(QPixmap(":/star_grape.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 43:
            obj[p1]->label->setPixmap(QPixmap(":/star_orange.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        case 44:
            obj[p1]->label->setPixmap(QPixmap(":/star_watermelon.png"));
            obj[p1]->label->setScaledContents(true);
            break;
        }
        animation_2->setDuration(500);
        animation_2->setStartValue(QRect(20+p2%10*52,570-p2/10*52,50,50));
        animation_2->setEndValue(QRect(20+p1%10*52,570-p1/10*52,50,50));
        animation_3->setDuration(500);
        animation_3->setStartValue(QRect(20+p1%10*52,570-p1/10*52,50,50));
        animation_3->setEndValue(QRect(20+p2%10*52,570-p2/10*52,50,50));
        QParallelAnimationGroup *group1=new QParallelAnimationGroup;
        group1->addAnimation(animation_2);
        group1->addAnimation(animation_3);
        group1->start();
        elapse(500);
    }
    if(value[0][p1]/10==4)
    {
        obj[p1]->label->setPixmap(QPixmap(":/base.png"));
        obj[p1]->label->setScaledContents(true);
        obj[p1]->type=-1;
        value[0][p1]=-1;
        star_eliminate(p2,0);
    }
    if(value[0][p2]/10==4)
    {
        obj[p2]->label->setPixmap(QPixmap(":/base.png"));
        obj[p2]->label->setScaledContents(true);
        value[0][p2]=-1;
        obj[p2]->type=-1;
        star_eliminate(p1,0);
    }
    while(effort==0)
    {
        effort=1;
        //星星(橫)
        for(int i=0;i<100;i++)
        {
            if(value[0][i]%10==value[0][i+1]%10&&value[0][i+1]%10==value[0][i+2]%10&&value[0][i+2]%10==value[0][i+3]%10&&value[0][i+3]%10==value[0][i+4]%10)
            {
                int temp[5]={value[0][i],value[0][i+1],value[0][i+2],value[0][i+3],value[0][i+4]};
                effort=0;
                obj[i]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i]=-1;
                obj[i]->type=-1;
                elapse(50);
                obj[i+1]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+1]=-1;
                obj[i+1]->type=-1;
                elapse(50);
                obj[i+2]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+2]=-1;
                obj[i+2]->type=-1;
                elapse(50);
                obj[i+3]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+3]=-1;
                obj[i+3]->type=-1;
                elapse(50);
                obj[i+4]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+4]=-1;
                obj[i+4]->type=-1;
                switch(temp[0]%10)
                {
                case 0:
                    obj[i]->label->setPixmap(QPixmap(":/star_apple.png"));
                    value[0][i]=40;
                    obj[i]->type=40;
                    break;
                case 1:
                    obj[i]->label->setPixmap(QPixmap(":/star_banana.png"));
                    value[0][i]=41;
                    obj[i]->type=41;
                    break;
                case 2:
                    obj[i]->label->setPixmap(QPixmap(":/star_grape.png"));
                    value[0][i]=42;
                    obj[i]->type=42;
                    break;
                case 3:
                    obj[i]->label->setPixmap(QPixmap(":/star_orange.png"));
                    value[0][i]=43;
                    obj[i]->type=43;
                    break;
                case 4:
                    obj[i]->label->setPixmap(QPixmap(":/star_watermelon.png"));
                    value[0][i]=44;
                    obj[i]->type=44;
                    break;
                }
                set_place();

                for(int j=0;j<=4;j++)//檢查消掉的有沒有特殊形
                {
                    if(temp[j]/10==1||temp[j]/10==2||temp[j]/10==3||temp[j]/10==4)
                    {
                        switch(temp[j]/10)
                        {
                        case 1:
                            horizon_eliminate(i+j,0);
                            break;
                        case 2:
                            vertical_eliminate(i+j,0);
                            break;
                        case 3:
                            bomb_eliminate(i+j,0);
                            break;
                        case 4:
                            star_eliminate(i+j,0);
                            break;
                        }
                    }
                }
                random_generate();
            }
            if(i%10==6)
                i+=3;
        }
        //星星(直)
        for(int i=0;i<60;i++)
        {
            if(value[0][i]%10==value[0][i+10]%10&&value[0][i+10]%10==value[0][i+20]%10&&value[0][i+20]%10==value[0][i+30]%10&&value[0][i+30]%10==value[0][i+40]%10)
            {
                int temp[5]={value[0][i],value[0][i+10],value[0][i+20],value[0][i+30],value[0][i+40]};
                effort=0;
                obj[i]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i]=-1;
                obj[i]->type=-1;
                elapse(50);
                obj[i+10]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+10]=-1;
                obj[i+10]->type=-1;
                elapse(50);
                obj[i+20]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+20]=-1;
                obj[i+20]->type=-1;
                elapse(50);
                obj[i+30]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+30]=-1;
                obj[i+30]->type=-1;
                elapse(50);
                obj[i+40]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+40]=-1;
                obj[i+40]->type=-1;
                switch(temp[0]%10)
                {
                case 0:
                    obj[i]->label->setPixmap(QPixmap(":/star_apple.png"));
                    value[0][i]=40;
                    obj[i]->type=40;
                    break;
                case 1:
                    obj[i]->label->setPixmap(QPixmap(":/star_banana.png"));
                    value[0][i]=41;
                    obj[i]->type=41;
                    break;
                case 2:
                    obj[i]->label->setPixmap(QPixmap(":/star_grape.png"));
                    value[0][i]=42;
                    obj[i]->type=42;
                    break;
                case 3:
                    obj[i]->label->setPixmap(QPixmap(":/star_orange.png"));
                    value[0][i]=43;
                    obj[i]->type=43;
                    break;
                case 4:
                    obj[i]->label->setPixmap(QPixmap(":/star_watermelon.png"));
                    value[0][i]=44;
                    obj[i]->type=44;
                    break;
                }
                set_place();

                for(int j=0;j<=4;j++)
                {
                    if(temp[j]/10==1||temp[j]/10==2||temp[j]/10==3||temp[j]/10==4)
                    {
                        switch(temp[j]/10)
                        {
                        case 1:
                            horizon_eliminate(i+10*j,0);
                            break;
                        case 2:
                            vertical_eliminate(i+10*j,0);
                            break;
                        case 3:
                            bomb_eliminate(i+10*j,0);
                            break;
                        case 4:
                            star_eliminate(i+10*j,0);
                            break;
                        }
                    }
                }
                  random_generate();
            }
        }
        //bomb
        //L型
        for(int i=0;i<=77;i++)
        {
            if(value[0][i]%10==value[0][i+1]%10&&value[0][i+1]%10==value[0][i+2]%10&&value[0][i+2]%10==value[0][i+10]%10&&value[0][i+10]%10==value[0][i+20]%10)
            {
                int temp[5]={value[0][i],value[0][i+1],value[0][i+2],value[0][i+10],value[0][i+20]};
                int place[5]={i,i+1,i+2,i+10,i+20};
                effort=0;
                obj[i]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i]=-1;
                obj[i]->type=-1;
                elapse(50);
                obj[i+1]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+1]=-1;
                obj[i+1]->type=-1;
                elapse(50);
                obj[i+2]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+2]=-1;
                obj[i+2]->type=-1;
                elapse(50);
                obj[i+10]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+10]=-1;
                obj[i+10]->type=-1;
                elapse(50);
                obj[i+20]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+20]=-1;
                obj[i+20]->type=-1;
                switch(temp[0]%10)
                {
                case 0:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_apple.png"));
                    value[0][i]=30;
                    obj[i]->type=30;
                    break;
                case 1:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_banana.png"));
                    value[0][i]=31;
                    obj[i]->type=31;
                    break;
                case 2:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_grape.png"));
                    value[0][i]=32;
                    obj[i]->type=32;
                    break;
                case 3:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_orange.png"));
                    value[0][i]=33;
                    obj[i]->type=33;
                    break;
                case 4:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
                    value[0][i]=34;
                    obj[i]->type=34;
                    break;
                }
                set_place();

                for(int j=0;j<=4;j++)
                {
                    if(temp[j]/10==1||temp[j]/10==2||temp[j]/10==3||temp[j]/10==4)
                    {
                        switch(temp[j]/10)
                        {
                        case 1:
                            horizon_eliminate(place[j],1);
                            break;
                        case 2:
                            vertical_eliminate(place[j],1);
                            break;
                        case 3:
                            bomb_eliminate(place[j],1);
                            break;
                        case 4:
                            star_eliminate(place[j],1);
                            break;
                        }
                     }
                }
                random_generate();
            }
            if(i%10==7)
                i+=2;
        }
        //|-型
        for(int i=0;i<=77;i++)
        {
            if(value[0][i]%10==value[0][i+10]%10&&value[0][i+10]%10==value[0][i+20]%10&&value[0][i+20]%10==value[0][i+21]%10&&value[0][i+21]%10==value[0][i+22]%10)
            {
                int temp[5]={value[0][i],value[0][i+10],value[0][i+20],value[0][i+21],value[0][i+22]};
                int place[5]={i,i+10,i+20,i+21,i+22};
                effort=0;
                obj[i]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i]=-1;
                obj[i]->type=-1;
                elapse(50);
                obj[i+10]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+10]=-1;
                obj[i+10]->type=-1;
                elapse(50);
                obj[i+20]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+20]=-1;
                obj[i+20]->type=-1;
                elapse(50);
                obj[i+21]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+21]=-1;
                obj[i+21]->type=-1;
                elapse(50);
                obj[i+22]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+22]=-1;
                obj[i+21]->type=-1;
                switch(temp[0]%10)
                {
                case 0:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_apple.png"));
                    value[0][i]=30;
                    obj[i]->type=30;
                    break;
                case 1:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_banana.png"));
                    value[0][i]=31;
                    obj[i]->type=31;
                    break;
                case 2:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_grape.png"));
                    value[0][i]=32;
                    obj[i]->type=32;
                    break;
                case 3:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_orange.png"));
                    value[0][i]=33;
                    obj[i]->type=33;
                    break;
                case 4:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
                    value[0][i]=34;
                    obj[i]->type=34;
                    break;
                }
                set_place();
                for(int j=0;j<=4;j++)
                {
                    if(temp[j]/10==1||temp[j]/10==2||temp[j]/10==3||temp[j]/10==4)
                    {
                        switch(temp[j]/10)
                        {
                        case 1:
                            horizon_eliminate(place[j],0);
                            break;
                        case 2:
                            vertical_eliminate(place[j],0);
                            break;
                        case 3:
                            bomb_eliminate(place[j],0);
                            break;
                        case 4:
                            star_eliminate(place[j],0);
                            break;
                        }
                    }
                }
                random_generate();
            }
            if(i%10==7)
                i+=2;
        }
        // _|型
        for(int i=0;i<=79;i++)
        {
            if(value[0][i]%10==value[0][i+1]%10&&value[0][i+1]%10==value[0][i+2]%10&&value[0][i+2]%10==value[0][i+12]%10&&value[0][i+12]%10==value[0][i+22]%10)
            {
                int temp[5]={value[0][i],value[0][i+1],value[0][i+2],value[0][i+12],value[0][i+22]};
                int place[5]={i,i+1,i+2,i+12,i+22};
                effort=0;
                obj[i]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i]=-1;
                obj[i]->type=-1;
                elapse(50);
                obj[i+1]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+1]=-1;
                obj[i+1]->type=-1;
                elapse(50);
                obj[i+2]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+2]=-1;
                obj[i+2]->type=-1;
                elapse(50);
                obj[i+12]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+12]=-1;
                obj[i+12]->type=-1;
                elapse(50);
                obj[i+22]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+22]=-1;
                obj[i+22]->type=-1;
                switch(temp[0]%10)
                {
                case 0:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_apple.png"));
                    value[0][i]=30;
                    obj[i]->type=30;
                    break;
                case 1:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_banana.png"));
                    value[0][i]=31;
                    obj[i]->type=31;
                    break;
                case 2:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_grape.png"));
                    value[0][i]=32;
                    obj[i]->type=32;
                    break;
                case 3:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_orange.png"));
                    value[0][i]=33;
                    obj[i]->type=33;
                    break;
                case 4:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
                    value[0][i]=34;
                    obj[i]->type=34;
                    break;
                }
                set_place();
                for(int j=0;j<=4;j++)
                {
                    if(temp[j]/10==1||temp[j]/10==2||temp[j]/10==3||temp[j]/10==4)
                    {
                        switch(temp[j]/10)
                        {
                        case 1:
                            horizon_eliminate(place[j],0);
                            break;
                        case 2:
                            vertical_eliminate(place[j],0);
                            break;
                        case 3:
                            bomb_eliminate(place[j],0);
                            break;
                        case 4:
                            star_eliminate(place[j],0);
                            break;
                        }
                    }
                }
                random_generate();
            }
            if(i%10==7)
                i+=2;
        }
        // -|型
        for(int i=2;i<=79;i++)
        {
            if(value[0][i]%10==value[0][i+10]%10&&value[0][i+10]%10==value[0][i+20]%10&&value[0][i+20]%10==value[0][i+19]%10&&value[0][i+19]%10==value[0][i+18]%10)
            {
                int temp[5]={value[0][i],value[0][i+10],value[0][i+20],value[0][i+19],value[0][i+18]};
                int place[5]={i,i+10,i+20,i+19,i+18};
                effort=0;
                obj[i]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i]=-1;
                obj[i]->type=-1;
                elapse(50);
                obj[i+10]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+10]=-1;
                obj[i+10]->type=-1;
                elapse(50);
                obj[i+20]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+20]=-1;
                obj[i+20]->type=-1;
                elapse(50);
                obj[i+19]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+19]=-1;
                obj[i+19]->type=-1;
                elapse(50);
                obj[i+18]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+18]=-1;
                obj[i+18]->type=-1;
                switch(temp[0]%10)
                {
                case 0:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_apple.png"));
                    value[0][i]=30;
                    obj[i]->type=30;
                    break;
                case 1:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_banana.png"));
                    value[0][i]=31;
                    obj[i]->type=31;
                    break;
                case 2:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_grape.png"));
                    value[0][i]=32;
                    obj[i]->type=32;
                    break;
                case 3:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_orange.png"));
                    value[0][i]=33;
                    obj[i]->type=33;
                    break;
                case 4:
                    obj[i]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
                    value[0][i]=34;
                    obj[i]->type=34;
                    break;
                }
                set_place();
                for(int j=0;j<=4;j++)
                {
                    if(temp[j]/10==1||temp[j]/10==2||temp[j]/10==3||temp[j]/10==4)
                    {
                        switch(temp[j]/10)
                        {
                        case 1:
                            horizon_eliminate(place[j],0);
                            break;
                        case 2:
                            vertical_eliminate(place[j],0);
                            break;
                        case 3:
                            bomb_eliminate(place[j],0);
                            break;
                        case 4:
                            star_eliminate(place[j],0);
                            break;
                        }
                    }
                }
                random_generate();
            }
            if(i%10==9)
                i+=2;
        }
        //直線
        for(int i=0;i<=69;i++)
        {
            if(value[0][i]%10==value[0][i+10]%10&&value[0][i+10]%10==value[0][i+20]%10&&value[0][i+20]%10==value[0][i+30]%10)
            {
                int temp[4]={value[0][i],value[0][i+10],value[0][i+20],value[0][i+30]};
                effort=0;
                obj[i]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i]=-1;
                obj[i]->type=-1;
                elapse(50);
                obj[i+10]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+10]=-1;
                obj[i+10]->type=-1;
                elapse(50);
                obj[i+20]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+20]=-1;
                obj[i+20]->type=-1;
                elapse(50);
                obj[i+30]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+30]=-1;
                obj[i+30]->type=-1;
                switch(temp[0]%10)
                {
                case 0:
                    obj[i]->label->setPixmap(QPixmap(":/vertical_apple.png"));
                    value[0][i]=20;
                    obj[i]->type=20;
                    break;
                case 1:
                    obj[i]->label->setPixmap(QPixmap(":/vertical_banana.png"));
                    value[0][i]=21;
                    obj[i]->type=21;
                    break;
                case 2:
                    obj[i]->label->setPixmap(QPixmap(":/vertical_grape.png"));
                    value[0][i]=22;
                    obj[i]->type=22;
                    break;
                case 3:
                    obj[i]->label->setPixmap(QPixmap(":/vertical_orange.png"));
                    value[0][i]=23;
                    obj[i]->type=23;
                    break;
                case 4:
                    obj[i]->label->setPixmap(QPixmap(":/vertical_watermelon.png"));
                    value[0][i]=24;
                    obj[i]->type=24;
                    break;
                }
                set_place();
                for(int j=0;j<4;j++)
                {
                    if(temp[j]/10==1||temp[j]/10==2||temp[j]/10==3||temp[j]/10==4)
                    {
                        switch(temp[j]/10)
                        {
                        case 1:
                            horizon_eliminate(i+10*j,0);
                            break;
                        case 2:
                            vertical_eliminate(i+10*j,0);
                            break;
                        case 3:
                            bomb_eliminate(i+10*j,0);
                            break;
                        case 4:
                            star_eliminate(i+10*j,0);
                            break;
                        }
                    }
                }
                random_generate();
            }
        }
        //橫
        for(int i=0;i<=96;i++)
        {
            if(value[0][i]%10==value[0][i+1]%10&&value[0][i+1]%10==value[0][i+2]%10&&value[0][i+2]%10==value[0][i+3]%10)
            {
                int temp[4]={value[0][i],value[0][i+1],value[0][i+2],value[0][i+3]};
                effort=0;
                obj[i]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i]=-1;
                obj[i]->type=-1;
                elapse(50);
                obj[i+1]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+1]=-1;
                obj[i+1]->type=-1;
                elapse(50);
                obj[i+2]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+2]=-1;
                obj[i+2]->type=-1;
                elapse(50);
                obj[i+3]->label->setPixmap(QPixmap(":/base.png"));
                value[0][i+3]=-1;
                obj[i+3]->type=-1;
                switch(temp[0]%10)
                {
                case 0:
                    obj[i]->label->setPixmap(QPixmap(":/horizon_apple.png"));
                    value[0][i]=10;
                    obj[i]->type=10;
                    break;
                case 1:
                    obj[i]->label->setPixmap(QPixmap(":/horizon_banana.png"));
                    value[0][i]=11;
                    obj[i]->type=11;
                    break;
                case 2:
                    obj[i]->label->setPixmap(QPixmap(":/horizon_grape.png"));
                    value[0][i]=12;
                    obj[i]->type=12;
                    break;
                case 3:
                    obj[i]->label->setPixmap(QPixmap(":/horizon_orange.png"));
                    value[0][i]=13;
                    obj[i]->type=13;
                    break;
                case 4:
                    obj[i]->label->setPixmap(QPixmap(":/horizon_watermelon.png"));
                    value[0][i]=14;
                    obj[i]->type=14;
                    break;
                }
                set_place();
                for(int j=0;j<=3;j++)
                {
                    if(temp[j]/10==1||temp[j]/10==2||temp[j]/10==3||temp[j]/10==4)
                    {
                        switch(temp[j]/10)
                        {
                        case 1:
                            horizon_eliminate(i+j,0);
                            break;
                        case 2:
                            vertical_eliminate(i+j,0);
                            break;
                        case 3:
                            bomb_eliminate(i+j,0);
                            break;
                        case 4:
                            star_eliminate(i+j,0);
                            break;
                        }
                    }
                }
                random_generate();
            }
            if(i%10==6)
                i+=3;
        }
    }
}

void MainWindow::button_click(int p)
{
    int click=0,i;
    for(i=0;i<100;i++)//已有被選取的在value[1][]改成1
        if(value[1][i]==1&&i!=p)
        {
            click++;
            break;
        }
    if(click==0)//沒有選過的
    {
        switch(value[0][p])
        {
        case 0:
            obj[p]->label->setPixmap(QPixmap(":/apple_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 1:
            obj[p]->label->setPixmap(QPixmap(":/banana_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 2:
            obj[p]->label->setPixmap(QPixmap(":/grape_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 3:
            obj[p]->label->setPixmap(QPixmap(":/orange_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 4:
            obj[p]->label->setPixmap(QPixmap(":/watermelon_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 10:
            obj[p]->label->setPixmap(QPixmap(":/horizon_apple_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 11:
            obj[p]->label->setPixmap(QPixmap(":/horizon_banana_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 12:
            obj[p]->label->setPixmap(QPixmap(":/horizon_grape_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 13:
            obj[p]->label->setPixmap(QPixmap(":/horizon_orange_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 14:
            obj[p]->label->setPixmap(QPixmap(":/horizon_watermelon_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 20:
            obj[p]->label->setPixmap(QPixmap(":/vertical_apple_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 21:
            obj[p]->label->setPixmap(QPixmap(":/vertical_banana_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 22:
            obj[p]->label->setPixmap(QPixmap(":/vertical_grape_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 23:
            obj[p]->label->setPixmap(QPixmap(":/vertical_orange_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 24:
            obj[p]->label->setPixmap(QPixmap(":/vertical_watermelon_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 30:
            obj[p]->label->setPixmap(QPixmap(":/bomb_apple_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 31:
            obj[p]->label->setPixmap(QPixmap(":/bomb_banana_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 32:
            obj[p]->label->setPixmap(QPixmap(":/bomb_grape_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 33:
            obj[p]->label->setPixmap(QPixmap(":/bomb_orange_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 34:
            obj[p]->label->setPixmap(QPixmap(":/bomb_watermelon_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 40:
            obj[p]->label->setPixmap(QPixmap(":/star_apple_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 41:
            obj[p]->label->setPixmap(QPixmap(":/star_banana_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 42:
            obj[p]->label->setPixmap(QPixmap(":/star_grape_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 43:
            obj[p]->label->setPixmap(QPixmap(":/star_orange_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        case 44:
            obj[p]->label->setPixmap(QPixmap(":/star_watermelon_pick.png"));
            obj[p]->label->setScaledContents(true);
            break;
        }
        value[1][p]=1;
    }
    else//有已被選取
    {
        value[1][i]=0;
        switch(value[0][i])//先把已被選取的還原
        {
        case 0:
            obj[i]->label->setPixmap(QPixmap(":/apple.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 1:
            obj[i]->label->setPixmap(QPixmap(":/banana.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 2:
            obj[i]->label->setPixmap(QPixmap(":/grape.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 3:
            obj[i]->label->setPixmap(QPixmap(":/orange.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 4:
            obj[i]->label->setPixmap(QPixmap(":/watermelon.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 10:
            obj[i]->label->setPixmap(QPixmap(":/horizon_apple.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 11:
            obj[i]->label->setPixmap(QPixmap(":/horizon_banana.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 12:
            obj[i]->label->setPixmap(QPixmap(":/horizon_grape.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 13:
            obj[i]->label->setPixmap(QPixmap(":/horizon_orange.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 14:
            obj[i]->label->setPixmap(QPixmap(":/horizon_watermelon.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 20:
            obj[i]->label->setPixmap(QPixmap(":/vertical_apple.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 21:
            obj[i]->label->setPixmap(QPixmap(":/vertical_banana.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 22:
            obj[i]->label->setPixmap(QPixmap(":/vertical_grape.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 23:
            obj[i]->label->setPixmap(QPixmap(":/vertical_orange.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 24:
            obj[i]->label->setPixmap(QPixmap(":/vertical_watermelon.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 30:
            obj[i]->label->setPixmap(QPixmap(":/bomb_apple.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 31:
            obj[i]->label->setPixmap(QPixmap(":/bomb_banana.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 32:
            obj[i]->label->setPixmap(QPixmap(":/bomb_grape.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 33:
            obj[i]->label->setPixmap(QPixmap(":/bomb_orange.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 34:
            obj[i]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 40:
            obj[i]->label->setPixmap(QPixmap(":/star_apple.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 41:
            obj[i]->label->setPixmap(QPixmap(":/star_banana.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 42:
            obj[i]->label->setPixmap(QPixmap(":/star_grape.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 43:
            obj[i]->label->setPixmap(QPixmap(":/star_orange.png"));
            obj[i]->label->setScaledContents(true);
            break;
        case 44:
            obj[i]->label->setPixmap(QPixmap(":/star_watermelon.png"));
            obj[i]->label->setScaledContents(true);
            break;
        }
        if(i%10>=1&&p==i-1)//左邊
        {
            change(i,p);
            value[1][p]=0;
        }
        else if(i%10<=8&&p==i+1)//右邊
        {
            change(i,p);
            value[1][p]=0;
        }
        else if(i<90&&p==i+10)//上
        {
            change(i,p);
            value[1][p]=0;
        }
        else if(i>9&&p==i-10)
        {
            change(i,p);
            value[1][p]=0;
        }
        else
        {
            value[1][p]=1;
            switch(value[0][p])
            {
            case 0:
                obj[p]->label->setPixmap(QPixmap(":/apple_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 1:
                obj[p]->label->setPixmap(QPixmap(":/banana_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 2:
                obj[p]->label->setPixmap(QPixmap(":/grape_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 3:
                obj[p]->label->setPixmap(QPixmap(":/orange_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 4:
                obj[p]->label->setPixmap(QPixmap(":/watermelon_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 10:
                obj[p]->label->setPixmap(QPixmap(":/horizon_apple_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 11:
                obj[p]->label->setPixmap(QPixmap(":/horizon_banana_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 12:
                obj[p]->label->setPixmap(QPixmap(":/horizon_grape_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 13:
                obj[p]->label->setPixmap(QPixmap(":/horizon_orange_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 14:
                obj[p]->label->setPixmap(QPixmap(":/horizon_watermelon_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 20:
                obj[p]->label->setPixmap(QPixmap(":/vertical_apple_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 21:
                obj[p]->label->setPixmap(QPixmap(":/vertical_banana_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 22:
                obj[p]->label->setPixmap(QPixmap(":/vertical_grape_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 23:
                obj[p]->label->setPixmap(QPixmap(":/vertical_orange_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 24:
                obj[p]->label->setPixmap(QPixmap(":/vertical_watermelon_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 30:
                obj[p]->label->setPixmap(QPixmap(":/bomb_apple_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 31:
                obj[p]->label->setPixmap(QPixmap(":/bomb_banana_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 32:
                obj[p]->label->setPixmap(QPixmap(":/bomb_grape_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 33:
                obj[p]->label->setPixmap(QPixmap(":/bomb_orange_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 34:
                obj[p]->label->setPixmap(QPixmap(":/bomb_watermelon_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 40:
                obj[p]->label->setPixmap(QPixmap(":/star_apple_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 41:
                obj[p]->label->setPixmap(QPixmap(":/star_banana_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 42:
                obj[p]->label->setPixmap(QPixmap(":/star_grape_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 43:
                obj[p]->label->setPixmap(QPixmap(":/star_orange_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            case 44:
                obj[p]->label->setPixmap(QPixmap(":/star_watermelon_pick.png"));
                obj[p]->label->setScaledContents(true);
                break;
            }
        }
    }
    return;
}

void MainWindow::change(int p1,int p2)
{
    QPropertyAnimation *animation_0,*animation_1;
    animation_0=new QPropertyAnimation(obj[p1]->label,"geometry");
    animation_1=new QPropertyAnimation(obj[p2]->label,"geometry");

    switch(value[0][p1])//用抓的
    {
    case 0:
        obj[p2]->label->setPixmap(QPixmap(":/apple.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 1:
        obj[p2]->label->setPixmap(QPixmap(":/banana.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 2:
        obj[p2]->label->setPixmap(QPixmap(":/grape.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 3:
        obj[p2]->label->setPixmap(QPixmap(":/orange.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 4:
        obj[p2]->label->setPixmap(QPixmap(":/watermelon.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 10:
        obj[p2]->label->setPixmap(QPixmap(":/horizon_apple.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 11:
        obj[p2]->label->setPixmap(QPixmap(":/horizon_banana.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 12:
        obj[p2]->label->setPixmap(QPixmap(":/horizon_grape.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 13:
        obj[p2]->label->setPixmap(QPixmap(":/horizon_orange.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 14:
        obj[p2]->label->setPixmap(QPixmap(":/horizon_watermelon.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 20:
        obj[p2]->label->setPixmap(QPixmap(":/vertical_apple.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 21:
        obj[p2]->label->setPixmap(QPixmap(":/vertical_banana.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 22:
        obj[p2]->label->setPixmap(QPixmap(":/vertical_grape.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 23:
        obj[p2]->label->setPixmap(QPixmap(":/vertical_orange.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 24:
        obj[p2]->label->setPixmap(QPixmap(":/vertical_watermelon.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 30:
        obj[p2]->label->setPixmap(QPixmap(":/bomb_apple.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 31:
        obj[p2]->label->setPixmap(QPixmap(":/bomb_banana.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 32:
        obj[p2]->label->setPixmap(QPixmap(":/bomb_grape.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 33:
        obj[p2]->label->setPixmap(QPixmap(":/bomb_orange.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 34:
        obj[p2]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 40:
        obj[p2]->label->setPixmap(QPixmap(":/star_apple.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 41:
        obj[p2]->label->setPixmap(QPixmap(":/star_banana.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 42:
        obj[p2]->label->setPixmap(QPixmap(":/star_grape.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 43:
        obj[p2]->label->setPixmap(QPixmap(":/star_orange.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    case 44:
        obj[p2]->label->setPixmap(QPixmap(":/star_watermelon.png"));
        obj[p2]->label->setScaledContents(true);
        break;
    }
    switch(value[0][p2])
    {

    case 0:
        obj[p1]->label->setPixmap(QPixmap(":/apple.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 1:
        obj[p1]->label->setPixmap(QPixmap(":/banana.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 2:
        obj[p1]->label->setPixmap(QPixmap(":/grape.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 3:
        obj[p1]->label->setPixmap(QPixmap(":/orange.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 4:
        obj[p1]->label->setPixmap(QPixmap(":/watermelon.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 10:
        obj[p1]->label->setPixmap(QPixmap(":/horizon_apple.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 11:
        obj[p1]->label->setPixmap(QPixmap(":/horizon_banana.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 12:
        obj[p1]->label->setPixmap(QPixmap(":/horizon_grape.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 13:
        obj[p1]->label->setPixmap(QPixmap(":/horizon_orange.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 14:
        obj[p1]->label->setPixmap(QPixmap(":/horizon_watermelon.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 20:
        obj[p1]->label->setPixmap(QPixmap(":/vertical_apple.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 21:
        obj[p1]->label->setPixmap(QPixmap(":/vertical_banana.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 22:
        obj[p1]->label->setPixmap(QPixmap(":/vertical_grape.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 23:
        obj[p1]->label->setPixmap(QPixmap(":/vertical_orange.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 24:
        obj[p1]->label->setPixmap(QPixmap(":/vertical_watermelon.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 30:
        obj[p1]->label->setPixmap(QPixmap(":/bomb_apple.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 31:
        obj[p1]->label->setPixmap(QPixmap(":/bomb_banana.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 32:
        obj[p1]->label->setPixmap(QPixmap(":/bomb_grape.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 33:
        obj[p1]->label->setPixmap(QPixmap(":/bomb_orange.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 34:
        obj[p1]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 40:
        obj[p1]->label->setPixmap(QPixmap(":/star_apple.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 41:
        obj[p1]->label->setPixmap(QPixmap(":/star_banana.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 42:
        obj[p1]->label->setPixmap(QPixmap(":/star_grape.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 43:
        obj[p1]->label->setPixmap(QPixmap(":/star_orange.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    case 44:
        obj[p1]->label->setPixmap(QPixmap(":/star_watermelon.png"));
        obj[p1]->label->setScaledContents(true);
        break;
    }
    animation_0->setDuration(500);//抓過來 位置從p2->p1
    animation_0->setStartValue(QRect(20+p2%10*52,570-p2/10*52,50,50));
    animation_0->setEndValue(QRect(20+p1%10*52,570-p1/10*52,50,50));
    animation_1->setDuration(500);
    animation_1->setStartValue(QRect(20+p1%10*52,570-p1/10*52,50,50));
    animation_1->setEndValue(QRect(20+p2%10*52,570-p2/10*52,50,50));


    QParallelAnimationGroup *group=new QParallelAnimationGroup;
    group->addAnimation(animation_0);
    group->addAnimation(animation_1);
    group->start();
    elapse(500);
    int l=value[0][p1];
    int k=obj[p1]->type;
    value[0][p1]=value[0][p2];
    obj[p1]->type=obj[p2]->type;
    value[0][p2]=l;
    obj[p2]->type=k;

    judge(p1,p2);


}
void MainWindow::star_eliminate(int p,int loop)
{
    int star=value[0][p]%10;
    value[0][p]=-1;
    obj[p]->label->setPixmap(QPixmap(":/base.png"));
    obj[p]->type=-1;
    for(int i=0;i<100;i++)
        if(value[0][i]==star)
        {
            obj[i]->label->setPixmap(QPixmap(":/base.png"));
            obj[i]->label->setScaledContents(true);
            if(value[0][i]>=10)
            {
                switch(value[0][i]/10)
                {
                case 1:
                    horizon_eliminate(i,1);
                    break;
                case 2:
                    vertical_eliminate(i,1);
                    break;
                case 3:
                    bomb_eliminate(i,1);
                    break;
                case 4:
                    star_eliminate(i,1);
                    break;
                }
            }
            value[0][i]=-1;
            obj[i]->type=-1;
        }
    if(loop==0)
        random_generate();
}
void MainWindow::bomb_eliminate(int p,int loop)
{
    obj[p]->label->setPixmap(QPixmap(":/base.png"));
    obj[p]->label->setScaledContents(true);
    value[0][p]=-1;
    obj[p]->type=-1;
    for(int i=p-11;i<=p+11;i++)
    {
        if(i==p)
            continue;
        if(i%10<1||i%10>8||i/10>8||i/10<1)
            continue;
        obj[i]->label->setPixmap(QPixmap(":/base.png"));
        obj[i]->label->setScaledContents(true);
        elapse(50);
       /* if(value[0][i]>=10)
        {
            switch(value[0][i]/10)
            {
            case 1:
                horizon_eliminate(i,1);
                break;
            case 2:
                vertical_eliminate(i,1);
                break;
            case 3:
                bomb_eliminate(i,1);
                break;
            case 4:
                star_eliminate(i,1);
                break;
            }
        }*/
        value[0][i]=-1;
        obj[i]->type=-1;
        if(i==p-9||i==p+1)
            i+=7;
    }

    if(loop==0)
        random_generate();
}
void MainWindow::vertical_eliminate(int p,int loop)
{
    for(int i=p%10;i<100;i+=10)
    {
        obj[i]->label->setPixmap(QPixmap(":/base.png"));
        obj[i]->label->setScaledContents(true);
        if(i==p)
        {
            value[0][i]=-1;
            obj[i]->type=-1;
            continue;
        }
        if(value[0][i]>=10)
        {
            switch(value[0][i]/10)
            {
            case 1:
                horizon_eliminate(i,1);
                break;
            case 2:
                vertical_eliminate(i,1);
                break;
            case 3:
                bomb_eliminate(i,1);
                break;
            case 4:
                star_eliminate(i,1);
                break;
            }
        }
        value[0][i]=-1;
        obj[i]->type=-1;
    }
    if(loop==0)
        random_generate();
}
void MainWindow::horizon_eliminate(int p,int loop)
{
    for(int i=p/10*10;i<p/10*10+10;i++)
    {
        obj[i]->label->setPixmap(QPixmap(":/base.png"));
        obj[i]->label->setScaledContents(true);
        if(i==p)
        {
            value[0][i]=-1;
            obj[i]->type=-1;
            continue;
        }
        if(value[0][i]>=10)
        {
            switch(value[0][i]/10)
            {
            case 1:
                horizon_eliminate(i,1);
                break;
            case 2:
                vertical_eliminate(i,1);
                break;
            case 3:
                bomb_eliminate(i,1);
                break;
            case 4:
                star_eliminate(i,1);
                break;
            }
        }
        value[0][i]=-1;
        obj[i]->type=-1;
    }
    if(loop==0)
        random_generate();
}

void MainWindow::random_generate()
{
    srand(time(NULL));
    int all_empty=0;
    QParallelAnimationGroup *group=new QParallelAnimationGroup;
    QPropertyAnimation *animation[200];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            if(value[0][i+j*10]==-1)//在行找base
            {
                animation[i+j*10]=new QPropertyAnimation(obj[i+j*10]->label,"geometry");
                all_empty=0;
                for(int k=i+j*10+10;k<100;k+=10)
                {
                    if(value[0][k]!=-1)//找到上面最接近不為base的
                    {
                        all_empty++;
                        obj[k]->label->setPixmap(QPixmap(":/base.png"));
                        obj[k]->label->setScaledContents(true);
                        value[0][i+j*10]=value[0][k];
                        obj[i+j*10]->type=obj[k]->type;
                        obj[k]->type=-1;
                        value[0][k]=-1;
                        obj[i+j*10]->label->setGeometry(20+k%10*52,570-k/10*52,50,50);
                        switch(value[0][i+j*10])
                        {
                        case 0:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/apple.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 1:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/banana.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 2:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/grape.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 3:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/orange.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 4:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/watermelon.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 10:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/horizon_apple.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 11:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/horizon_banana.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 12:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/horizon_grape.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 13:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/horizon_orange.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 14:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/horizon_watermelon.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 20:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/vertical_apple.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 21:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/vertical_banana.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 22:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/vertical_grape.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 23:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/vertical_orange.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 24:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/vertical_watermelon.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 30:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/bomb_apple.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 31:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/bomb_banana.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 32:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/bomb_grape.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 33:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/bomb_orange.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 34:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/bomb_watermelon.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 40:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/star_apple.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 41:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/star_banana.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 42:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/star_grape.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 43:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/star_orange.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        case 44:
                            obj[i+j*10]->label->setPixmap(QPixmap(":/star_watermelon.png"));
                            obj[i+j*10]->label->setScaledContents(true);
                            break;
                        }
                        animation[i+j*10]->setDuration(500);
                        animation[i+j*10]->setStartValue(QRect(20+k%10*52,570-k/10*52,50,50));
                        animation[i+j*10]->setEndValue(QRect(20+(i+j*10)%10*52,570-(i+j*10)/10*52,50,50));
                        group->addAnimation(animation[i+j*10]);

                        break;
                    }
                }
                if(all_empty==0)
                {

                    for(int k=i+10*j;k<100;k+=10)
                    {

                        value[0][k]=rand()%5;

                        switch(value[0][k])
                        {
                        case 0:
                            obj[k]->label->setPixmap(QPixmap(":/apple.png"));
                            obj[k]->label->setScaledContents(true);
                            obj[k]->type=0;
                            break;
                        case 1:
                            obj[k]->label->setPixmap(QPixmap(":/banana.png"));
                            obj[k]->label->setScaledContents(true);
                            obj[k]->type=1;
                            break;
                        case 2:
                            obj[k]->label->setPixmap(QPixmap(":/grape.png"));
                            obj[k]->label->setScaledContents(true);
                            obj[k]->type=2;
                            break;
                        case 3:
                            obj[k]->label->setPixmap(QPixmap(":/orange.png"));
                            obj[k]->label->setScaledContents(true);
                            obj[k]->type=3;
                            break;
                        case 4:
                            obj[k]->label->setPixmap(QPixmap(":/watermelon.png"));
                            obj[k]->label->setScaledContents(true);
                            obj[k]->type=4;
                            break;
                        }
                        animation[100+k]=new QPropertyAnimation(obj[k]->label,"geometry");
                        animation[100+k]->setDuration(500);
                        animation[100+k]->setStartValue(QRect(20+k%10*52,108-k/10*52,50,50));
                        animation[100+k]->setEndValue(QRect(20+k%10*52,570-k/10*52,50,50));
                        group->addAnimation(animation[100+k]);
                    }
                }
            }
        }
    group->start();
    elapse(1000);
}
