#ifndef POINT_H
#define POINT_H
class QPainter;
class Rect;
class Point
{
private:
    int x=0;
    int y=0;
    int size =3;
    int thickness =1;
public:
    Point(int x1,int y1,int size1);
    int GetX() const;
    void SetX(int x);
    int GetY() const;
    void SetY(int y);
    int GetSize() const;
    void SetSize(int size=3);
    void draw(QPainter *painter) const;
    int GetThickness() const;
    void SetThickness(int thickness=1);
};

#endif // POINT_H
