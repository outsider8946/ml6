#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include<point.h>
#include<vector>
#include "rect.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(valid)
    {
        for(int i = 0;i<mas_0.size();++i)
        {
                for(int j = i+1;j<mas_0.size();++j)
                {
                    if(mas_0[i].contains(mas_0[j])!=0 && !mas_check.empty())
                    {
                        int cnt =0;
                        for(int k = 0;k< mas_0.size();k++)
                        {
                            if (mas_check[0].GetX()>=mas_0[i].Get_Begin_X() && mas_check[0].GetX()<=mas_0[i].Get_End_X() && mas_check[0].GetY()>=mas_0[i].Get_Begin_Y() && mas_check[0].GetY()<=mas_0[i].Get_End_Y())
                                 {
                                      cnt++;
                                      mas_0[i].color(&painter,cnt,mas_0[j]);
                                  }
                        }

                    }
                }
         }

    }
        for(int i = 0;i<mas_0.size();i++)
        {
            mas_0[i].draw(&painter);
        }
        for(int i = 0;i<mas_check.size();i++)
        {
            mas_check[i].draw(&painter);
        }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    static int cnt=-1;
    Point point(event->x(),event->y(),3);
    if((event->modifiers()==Qt::ControlModifier) && (event->button()==Qt::LeftButton))
    {
         mas.push_back(point);
         if ((!mas.empty()) && (mas.size()%2==0))
         {
             Rect rect;
             cnt++;
             rect.Set_Begin_X(mas[cnt].GetX());
             rect.Set_Begin_Y(mas[cnt].GetY());
             cnt++;
             rect.Set_End_X(mas[cnt].GetX());
             rect.Set_End_Y(mas[cnt].GetY());
             if(rect.Get_Begin_X()>rect.Get_End_X())
             {
                 int value =rect.Get_Begin_X();
                 rect.Set_Begin_X(rect.Get_End_X());
                 rect.Set_End_X(value);
             }
             if(rect.Get_Begin_Y()>rect.Get_End_Y())
             {
                 int value =rect.Get_Begin_Y();
                 rect.Set_Begin_Y(rect.Get_End_Y());
                 rect.Set_End_Y(value);
             }
             mas_0.push_back(rect);
         }
      }

    else
        if (event->button()==Qt::LeftButton)
        {
            if(mas_check.empty())
                mas_check.push_back(point);
            else
            {
                mas_check.pop_back();
                mas_check.push_back(point);
            }
        }
   valid = true;
   repaint();
}

