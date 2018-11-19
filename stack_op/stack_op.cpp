#include<cstdio>
#include<malloc.h>
#include"stack_op.h"
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
STACK::operator int() const{
    return this->pos;
}
int STACK::operator[](int x) const{
    return this->elems[x];
}
STACK& STACK::operator<<(int e){
    if(this->pos==this->max)
        return (*this);
    this->elems[this->pos]=e;
    this->pos++;
    return (*this);
}
STACK& STACK::operator>>(int &e){
    if(this->pos==0)
        return (*this);
    this->elems[this->pos]=0;
    this->pos--;
    e = this->elems[this->pos];
    return (*this);
}

STACK& STACK::operator=(const STACK &s){
    int i,*tmp=(int *)&(this->max),**p_tmp=(int **)&(this->elems);
    *tmp=s.size();
    free(*p_tmp);
    *p_tmp=(int *)malloc(sizeof(int)*s.size());
    this->pos=s;
    for(i=0;i<this->pos;i++){
        this->elems[i]=s[i];
    }
    return (*this);
}

void STACK::print() const{
    int i;
    for(i=0;i<this->pos;i++)
        printf("%d  ",this->elems[i]);
}
void STACK::empty(){
    int i;
    for(i=0;i<this->pos;i++)
        this->elems[i]=0;
    this->pos=0;
}
STACK::~STACK(){
    free(this->elems);
}