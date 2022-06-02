#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class Point;
class Rect;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    std::vector<Point> mas;
    std::vector<Rect> mas_0;
    std::vector<Point> mas_check;
    bool valid = false;
    int x,y;
};
#endif // MAINWINDOW_H
