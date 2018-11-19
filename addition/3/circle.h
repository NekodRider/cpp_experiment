#define PI 3.1415
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