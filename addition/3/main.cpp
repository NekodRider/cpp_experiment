#include<iostream>
#include<cmath>
using namespace std;
#include"point.h"
#include"line.h"
#include"circle.h"

void display(Point& a){
    a.display();
}
double getDist(Point &a,Point &b){
    return a.getDist(b);
}

int main(){
    Point a(1,1),b(4,5);
    Circle m(a,1),n(b,2);

    Point c(4,1);
    Line l(a,b);
    cout<<"A";
    display(a);
    cout<<"----B";
    display(b);
    cout<<"  Distance = "<<getDist(a,b)<<endl<<"Line ";
    display(l);
    cout<<"  Length = "<<l.getLength()<<"  MidPoint";
    l.displayMid();
    
    cout<<endl<<"CircleX";
    display(m);
    cout<<"Girth = "<<m.girth()<<", Area = "<<m.area()<<endl;
    cout<<"CircleY";
    display(n);
    cout<<"Girth = "<<n.girth()<<", Area = "<<n.area()<<endl;
    cout<<"The Distance of CircleX and CircleY = "<<getDist(m,n);
    return 0;
}