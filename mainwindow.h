#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "object.h"
#include "empty.h"
#include "apple.h"
#include "banana.h"
#include "grape.h"
#include "orange.h"
#include "watermelon.h"
#include "apple_vertical.h"
#include "banana_vertical.h"
#include "grape_vertical.h"
#include "orange_vertical.h"
#include "watermelon_vertical.h"
#include "apple_horizon.h"
#include "banana_horizon.h"
#include "grape_horizon.h"
#include "orange_horizon.h"
#include "watermelon_horizon.h"
#include "apple_bomb.h"
#include "banana_bomb.h"
#include "grape_bomb.h"
#include "orange_bomb.h"
#include "watermelon_bomb.h"
#include "apple_star.h"
#include "banana_star.h"
#include "grape_star.h"
#include "orange_star.h"
#include "watermelon_star.h"
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QPalette>
#include <QFont>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <time.h>
#include <QString>
#include <QTime>
#include <QCoreApplication>
#include <QSignalMapper>
#include <QLCDNumber>
#include <QtCore>
#include <QDateTime>
#include <QDialog>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void game_start();
    void judge(int p1,int p2);
    void generate();
    void set_place();
    void elapse(int time);
    void generate_first_board();
    void change(int p1,int p2);
    void horizon_eliminate(int p,int loop);
    void vertical_eliminate(int p,int loop);
    void bomb_eliminate(int p,int loop);
    void star_eliminate(int p,int loop);
    void random_generate();
    void time_out();
    void build(int i,int paint_type);
    void switch_build(int i,int value_change);
signals:
    void quit(int star,int score);

public slots:
    void game();
    void button_end();
    void button_click(int i);
    void count_time();
    void restart_game();
    void close_game();
private:
    QImage image;
    QWidget *w;
    object *obj[100];
    QPushButton *start,*end;
    int value[2][100];
    QLabel *Time,*Score;
    QSignalMapper *signal;
    QLCDNumber *Count_down;
    QLCDNumber *Count_score;
    QTimer *timer;
    int time_limit;
    QDialog *end_game;
    int your_score;
    int star,score;
};

#endif // MAINWINDOW_H
