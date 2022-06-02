#include "point.h"
#include<QPainter>
#include  "rect.h"
Point::Point(int x1,int y1,int size1):x(x1),y(y1),size(size1){}

 int Point::GetX() const {
    return x;
}

void Point::SetX(int x)
{
    this->x=x;
}

 int Point::GetY() const
{
    return y;
}

void Point::SetY(int y)
{
    this-> y =y;
}
int Point::GetSize() const
{
    return size;
}

void Point::SetSize(int size)
{
    this-> size = size;
}

void Point::draw(QPainter *painter) const
{
        painter->drawLine(this->x,this->y-((size)/2),this->x,this->y+((size/2)));
        painter->drawLine((this->x+(size)/2),this->y,this->x-((size)/2),this->y);
}
int Point::GetThickness() const
{
    return thickness;
}
void Point:: SetThickness(int thickness)
{
    this-> thickness = thickness;
}



