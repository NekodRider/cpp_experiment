#include<iostream>
#include<math.h>
class Point{
    private:
        double x,y;
    public:
        Point(double x=0,double y=0){
            this->x = x;
            this->y = y;
        }
        double getX(){
            return this->x;
        }
        double getY(){
            return this->y;
        }
        double getDist(Point b){
            return sqrt(pow(abs(b.x-this->x),2)+pow(abs(b.y-this->y),2));
        }
        void display(){
            cout<<"("<<this->x<<","<<this->y<<")";
        }
};

class Line{
    private:
        Point start,end;
        double length;
    public:
        Line(Point a,Point b){
            this->start = a;
            this->end = b;
            length = a.getDist(b);
        }
        void getMid(Point &mid){
            double  midX = (this->start.getX()+this->end.getX())/2,
                    midY = (this->start.getY()+this->end.getY())/2;
            mid = Point(midX,midY);
        }
        void displayMid(){
            Point mid;
            this->getMid(mid);
            mid.display();
        }
        double getLength(){
            return this->length;
        }
        double getDist(Point p){
            //|ad＋be＋cf－af－bc－de|/2
            return abs(this->start.getX()*this->end.getY()+this->start.getY()*p.getX()+this->end.getX()*p.getY()-this->start.getX()*p.getY()-this->start.getY()*this->end.getX()-this->end.getY()*p.getX())/this->getLength();
        }

};
