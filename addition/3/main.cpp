#include<iostream>
#include<typeinfo>
using namespace std;
#include"point.h"
#include"line.h"
#include"circle.h"

void display(Point& a){

    a.display();
}
double getDist(Point &a,Point &b){
    cout<<endl<<typeid(a).name()<<endl;
    if(typeid(a).name()=="Point"){
        if(typeid(b).name()=="Line"){
            return b.getDist(a);
        }
        if(typeid(b).name()=="Circle"){
            Circle *p=(Circle *)&b;
            return a.getDist(b)-p->getR();
        }
    }
    if(typeid(a).name()=="Line"){
        if(typeid(b).name()=="Line"){
            return -1;
        }
        if(typeid(b).name()=="Circle"){
            Circle *p=(Circle *)&b;
            return a.getDist(b)-p->getR();
        }
    }
    if(typeid(a).name()=="Circle"){
        Circle *p=(Circle *)&a;
        if(typeid(b).name()=="Line"){
            return b.getDist(a)-p->getR();
        }
        if(typeid(b).name()=="Point"){
            return a.getDist(b)-p->getR();
        }
    }
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
    cout<<"  Distance="<<getDist(a,b)<<endl;
    display(l);
    cout<<"  Length="<<l.getLength()<<"  MidPoint";
    l.displayMid();
    
    cout<<endl<<"A";
    display(m);
    cout<<"Girth = "<<m.girth()<<", Area = "<<m.area()<<endl;
    cout<<"B";
    display(n);
    cout<<"Girth = "<<n.girth()<<", Area = "<<n.area()<<endl;
    cout<<"Dist="<<getDist(m,n);
    return 0;
}