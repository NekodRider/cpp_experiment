#include <iostream>
#include <cstring>
#include "stack2queue.h"
using namespace std;
int main()
{
    int M,F,m,f,i,count=1;
    cout<<"Input male num and female num:";
    cin>>M;
    cin>>F;
    QUEUE male(M),female(F);
    cout<<"Input male pos and female pos:";
    cin>>m;
    cin>>f;
    for(i=0;i<M;i++){
        if(i==m-1)
            male<<1;
        else
            male<<0;
    }
    for(i=0;i<F;i++){
        if(i==f-1)
            female<<1;
        else
            female<<0;
    }
    while(1){
        int p,q;
        male>>p;
        female>>q;
        cout<<p<<" "<<q<<endl;
        if(p==1&&q==1){
            cout<<count;
            break;
        }
        count++;
        male<<p;
        female<<q;
    }
    return 0;
}
