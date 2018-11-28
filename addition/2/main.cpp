#include<iostream>
#include <cmath>
#define PI 3.1415
using namespace std;

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

class Circle:public Point
{
    double r;

  public:
    Circle(Point o, double r):Point(o.getX(),o.getY())
    {
        this->r = r;
    }
    Point getXY()
    {
        Point res(this->getX(),this->getY());
        return res;
    }
    double getR()
    {
        return this->r;
    }
    double girth()
    {
        return PI * this->getR() * 2.0;
    }
    double area()
    {
        return PI * this->getR() * this->getR();
    }
    void display()
    {
        cout << "("<<this->getX()<<","<<this->getY()<<","<<this->getR()<<")"<<endl;
    }
    double getDist(Circle b){
        return (this->getXY()).getDist(b.getXY());
    }
};

int main(){
    Point a(1,1),b(4,5);
    Circle m(a,1),n(b,2);

    Point c(4,1);
    Line l(a,b);
    cout<<"A";
    a.display();
    cout<<"----B";
    b.display();
    cout<<"   Distance="<<a.getDist(b)<<"   Length="<<l.getLength()<<"  MidPoint";
    l.displayMid();
    cout<<"   C(4,1) to Line Dist="<<l.getDist(c)<<endl<<endl;

    cout<<"A";
    m.display();
    cout<<"Girth = "<<m.girth()<<", Area = "<<m.area()<<endl;
    cout<<"B";
    n.display();
    cout<<"Girth = "<<n.girth()<<", Area = "<<n.area()<<endl;
    cout<<"Dist="<<(m.getXY()).getDist(n.getXY());
    return 0;
}