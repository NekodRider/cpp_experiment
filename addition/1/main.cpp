#include<iostream>
using namespace std;
#include"line_point.h"
int main(){
    Point a(1,1),b(4,5),c(4,1);
    Line l(a,b);
    cout<<"A";
    a.display();
    cout<<"----B";
    b.display();
    cout<<"   Distance="<<a.getDist(b)<<"   Length="<<l.getLength()<<"  MidPoint";
    l.displayMid();
    cout<<"   C(4,1) to Line Dist="<<l.getDist(c);
    return 0;
}