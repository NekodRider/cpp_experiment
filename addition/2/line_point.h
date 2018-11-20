#include <iostream>
#include <cmath>
class Point
{
  private:
    double x, y;

  public:
    Point(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }
    double getX()
    {
        return this->x;
    }
    double getY()
    {
        return this->y;
    }
    double getDist(Point b)
    {
        return sqrt(pow(abs(b.x - this->x), 2) + pow(abs(b.y - this->y), 2));
    }
    void display()
    {
        cout << "(" << this->x << "," << this->y << ")";
    }
};

class Line : public Point
{
    Point start, end;
    double length;

  public:
    Line(Point a, Point b) : Point((a.getX() + b.getX()) / 2, (a.getY() + b.getY()) / 2)
    {
        this->start = a;
        this->end = b;
        length = a.getDist(b);
    }
    void displayMid()
    {
        this->Point::display();
    }
    double getLength()
    {
        return this->length;
    }
    double getDist(Point p)
    {
        //|ad＋be＋cf－af－bc－de|/2
        return abs(this->start.getX() * this->end.getY() + this->start.getY() * p.getX() + this->end.getX() * p.getY() - this->start.getX() * p.getY() - this->start.getY() * this->end.getX() - this->end.getY() * p.getX()) / this->getLength();
    }
};
