#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QPalette>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void game();
private:
    QImage image;
    QWidget *w;
    QLabel *label[76];
    QPushButton *button[76];
    QPushButton *start,*end;
    int value[2][76];
};

#endif // MAINWINDOW_H
