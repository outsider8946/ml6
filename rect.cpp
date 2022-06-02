#include "rect.h"
#include<QPainter>
#include "point.h"
#include <vector>
Rect::Rect(int x_1,int y_1,int x_2,int y_2)
{
   begin_x = (x_1>x_2)? x_2:x_1;
   begin_y = (y_1>y_2)? y_2:y_1;
   end_x = (x_1>x_2)? x_1:x_2;
   end_y = (y_1>y_2)? x_1:x_2;
}

void Rect::draw(QPainter *painter) const
{
    painter->drawLine(this->begin_x,this->begin_y,this->end_x,this->begin_y);
    painter->drawLine(this->begin_x,this->end_y,this->end_x,this->end_y);
    painter->drawLine(this->begin_x,this->begin_y,this->begin_x,this->end_y);
    painter->drawLine(this->end_x,this->begin_y,this->end_x,this->end_y);
}

int Rect::Get_Begin_X() const
{
    return begin_x;
}

int Rect::Get_Begin_Y() const
{
    return begin_y;
}

int Rect::Get_End_X() const
{
    return end_x;
}

int Rect::Get_End_Y() const
{
    return end_y;
}
void Rect::Set_Begin_X(int x)
{
    begin_x = x;
}

void Rect::Set_Begin_Y(int y)
{
    begin_y = y;
}

void Rect::Set_End_X(int x)
{
    end_x = x;
}

void Rect::Set_End_Y(int y)
{
    end_y = y;
}
void Rect::color(QPainter *painter, int cnt ,Rect r)
{
    int x,y,w,h =0;
    if(contains(r)==1)
    {
        if(r.Get_Begin_Y() < begin_y)
        {
             x = r.Get_Begin_X();
             y = begin_y;
             w = end_x-r.Get_Begin_X();
             h = r.Get_End_Y()-begin_y;
        }
        else
        {
             x = r.Get_Begin_X();
             y = r.Get_Begin_Y();
             w = end_x - r.Get_Begin_X();
             h = r.Get_End_Y()-r.Get_Begin_Y();
        }
    }
     if(contains(r)==2)
       {
         if(r.Get_Begin_Y() >begin_y)
         {
             x = r.Get_Begin_X();
             y = r.Get_Begin_Y();
             w = end_x-r.Get_Begin_X();
             h = end_y - r.Get_Begin_Y();
        }
     }
     if(contains(r)==3)
     {
         if(r.Get_Begin_Y()< begin_y && r.Get_Begin_X()<begin_x)
         {
              x = begin_x;
              y = begin_y;
              w = r.Get_End_X()-begin_x;
              h = r.Get_End_Y()-begin_y;
         }
         else
         {
             if(r.Get_Begin_X()<begin_x)
             {
                  x = begin_x;
                  y = r.Get_Begin_Y();
                  w = r.Get_End_X()-begin_x;
                  h = r.Get_End_Y() -r.Get_Begin_Y();
              }
             else
             {
                 if(!(r.Get_Begin_Y()>=begin_y && r.Get_End_Y()<=end_y))
                 {
                     x = r.Get_Begin_X();
                     y = begin_y;
                     w = r.Get_End_X()-r.Get_Begin_X();
                     h =r.Get_End_Y()- begin_y;
                 }
             }
         }
     }
     if(contains(r) == 4)
     {
         if(r.Get_Begin_X()<begin_x)
         {
              x = begin_x;
              y = r.Get_Begin_Y();
              w = r.Get_End_X()- begin_x;
              h = end_y - r.Get_Begin_Y();
         }
         else
         {
              x = r.Get_Begin_X();
              y = r.Get_Begin_Y();
              w = r.Get_End_X()-r.Get_Begin_X();
              h = end_y -r.Get_Begin_Y();
         }
     }

    if(contains(r) == 5 )
        {
           if(r.Get_End_Y()<=end_y && r.Get_Begin_Y()>=begin_y)
          {
             x = begin_x;
             y = r.Get_Begin_Y();
             w = end_x-begin_x;
             h = r.Get_End_Y() - r.Get_Begin_Y();
          }
           if(r.Get_End_Y()>end_y && r.Get_Begin_Y()>=begin_y)
           {
               x = begin_x;
               y = r.Get_Begin_Y();
               w = end_x- begin_x;
               h = end_y - r.Get_Begin_Y();
           }
           if(r.Get_End_Y()<=end_y && r.Get_Begin_Y()<begin_y)
           {
               x = begin_x;
               y = begin_y;
               w = end_x-begin_x;
               h = r.Get_End_Y() - begin_y;
           }

        }
    if(contains(r) == 6)
    {
        if(r.Get_Begin_X()>=begin_x && r.Get_End_X()<=end_x)
        {
            x = r.Get_Begin_X();
            y = begin_y;
            w = r.Get_End_X()-r.Get_Begin_X();
            h = end_y -begin_y;
        }
        if(r.Get_Begin_X()<begin_x && r.Get_End_X()<=end_x)
        {
            x = begin_x;
            y  = begin_y;
            w = r.Get_End_X()-begin_x;
            h = end_y - begin_y;
        }
        if(r.Get_Begin_X()>=begin_x && r.Get_End_X()>end_x)
        {
           x = r.Get_Begin_X();
           y  = begin_y;
           w = end_x-r.Get_Begin_X();
           h = end_y -begin_y;
        }
    }
    if(contains(r) == 7)
    {
        x = r.Get_Begin_X();
        y =r.Get_Begin_Y();
        w = r.Get_End_X()-r.Get_Begin_X();
        h = r.Get_End_Y()-r.Get_Begin_Y();
    }
    switch(cnt)
    {
        case 2 :
    {
        QBrush brush(Qt::red);
        painter->fillRect(x,y,w,h,brush);
        break;
    }

        case 3:
    {
        QBrush brush(Qt::yellow);
        painter->fillRect(x,y,w,h,brush);
        break;
    }

        case 4:
    {
        QBrush brush(Qt::green);
        painter->fillRect(x,y,w,h,brush);
        break;
    }

         case 5:
    {
        QBrush brush (Qt::blue);
        painter->fillRect(x,y,w,h,brush);
        break;
    }

         default:
            QBrush brush (Qt::black);
            painter->fillRect(x,y,w,h,brush);
     }

}

bool Rect::check(Point &p)
{
    return ((p.GetX()<=end_x) && (p.GetX()>=begin_x) && (p.GetY()<=end_y) && (p.GetY()>=begin_y))?true:false;
}

int Rect::contains(Rect &r)
{
    int pos_1 =((r.Get_Begin_X()>=begin_x && r.Get_Begin_X()<=end_x && r.Get_End_Y()>=begin_y && r.Get_End_X()>= end_x && r.Get_End_Y()<=end_y))? 1:0;
    int pos_2 = ((r.Get_Begin_X()>=begin_x && r.Get_Begin_X()<=end_x && r.Get_Begin_Y()>=begin_y && r.Get_Begin_Y()<=end_y && r.Get_End_X()>=end_x && r.Get_End_Y()>=end_y))?2:0;
    int pos_3 =((r.Get_End_X()>=begin_x && r.Get_End_X()<=end_x && r.Get_End_Y()>=begin_y && r.Get_End_Y()<=end_y))?3:0;
    int pos_4 =((r.Get_End_X()>=begin_x && r.Get_End_X()<=end_x && r.Get_Begin_Y()>=begin_y && r.Get_Begin_Y()<=end_y))?4:0;
    int pos_5 =(r.Get_Begin_X()<=begin_x && r.Get_End_X()>=end_x )?5:0;
    int pos_6 =(r.Get_End_Y()>=end_y && r.Get_Begin_Y()<=begin_y)?6:0;
    int pos_7 = (r.Get_Begin_X()>=begin_x && r.Get_End_X()<= end_x && r.Get_Begin_Y()>=begin_y && r.Get_End_Y()<=end_y)?7:0;
    std::vector <int> pos {pos_1,pos_2,pos_3,pos_4,pos_5,pos_6,pos_7};
   for(int i = 0;i<pos.size();i++)
   {
       if(pos[i])
           return pos[i];
   }

}
