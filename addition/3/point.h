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

