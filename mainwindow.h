#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "object.h"
#include "empty.h"
#include "apple.h"
#include "banana.h"
#include "grape.h"
#include "orange.h"
#include "watermelon.h"
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
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void game_start();
    void judge();
    void generate();
    void set_place();
    void elapse(int time);
    void generate_first_board();

public slots:
    void game();
    void button_end();
private:
    QImage image;
    QWidget *w;
    object *obj[100];
    QPushButton *start,*end;
    int value[2][100];
    int temp[100];
    QLabel *Time,*Score;
};

#endif // MAINWINDOW_H
