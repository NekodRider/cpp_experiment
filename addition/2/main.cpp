#include<iostream>
using namespace std;
#include"circle.h"
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