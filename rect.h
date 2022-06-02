#ifndef RECT_H
#define RECT_H

class QPainter;
class QBrush;
class Point;
class Rect
{
private:
    int begin_x;
    int end_x;
    int begin_y;
    int end_y;
public:
    Rect(int x_1 = 0,int y_1 =0,int x_2=0,int y_2=0);
    void draw(QPainter *painter) const;
    int Get_Begin_X() const;
    int Get_Begin_Y() const;
    int Get_End_X() const;
    int Get_End_Y() const;
    void Set_Begin_X(int x);
    void Set_Begin_Y(int y);
    void Set_End_X(int x);
    void Set_End_Y(int y);
    void color(QPainter * painter,int cnt,Rect r);
    bool check(Point& p);
    int contains(Rect& r);
    int counter (Rect& r);
};

#endif // RECT_H
