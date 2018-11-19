#include<cstdio>
#include<malloc.h>
#include"stack_class.h"
STACK::STACK(int m):max(m),elems((int *)malloc(sizeof(int)*m)){
    this->pos = 0;
}
STACK::STACK(const STACK &s):max(s.max),elems((int *)malloc(sizeof(int)*s.max)){
    int i;
    this->pos = s.pos;
    for(i=0;i<s.max;i++)
        this->elems[i]=s.elems[i];
}
int STACK::size() const{
    return this->max;
}
int STACK::howMany() const{
    return this->pos;
}
int STACK::getelem(int x) const{
    return this->elems[x];
}
STACK& STACK::push(int e){
    if(this->pos==this->max)
        return *this;
    this->elems[this->pos]=e;
    this->pos++;
    return *this;
}
STACK& STACK::pop(int &e){
    if(this->pos==0)
        return *this;
    this->elems[this->pos]=0;
    this->pos--;
    e = this->elems[this->pos];
    return *this;
}
STACK& STACK::assign(const STACK &s){
    int i;
    if(s.pos>this->max)
        this->pos=this->max;
    else
        this->pos=s.pos;
    for(i=0;i<this->pos;i++){
        this->elems[i]=s.elems[i];
    }
    return *this;
}
void STACK::print() const{
    int i;
    for(i=0;i<this->pos;i++)
        printf("%d  ",this->elems[i]);
}
STACK::~STACK(){
    free(this->elems);
}