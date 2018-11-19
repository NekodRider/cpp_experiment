#include <cstdio>
#include "stack2queue.h"
QUEUE::QUEUE(int m) : STACK(m), s2(m) {}
QUEUE::QUEUE(const QUEUE &s) : STACK(s), s2(s.s2) {}
QUEUE::operator int() const
{
    return STACK::operator int() + int(this->s2);
}
int QUEUE::full() const
{
    return (STACK::operator int() == STACK::size() && int(this->s2) != 0) ? 1 : 0;
}

QUEUE& QUEUE::operator<<(int e){
    int i,tmp;
    if (this->full()) 
        throw std::overflow_error("QUEUE FULL.");
    STACK::operator<<(e);
    if(STACK::operator int()==STACK::size()&&this->full()==0){
        for(i=0;i<this->s2.size();i++){
            STACK::operator>>(tmp);
            this->s2<<tmp;
        }
    }
    return (*this);
}
QUEUE &QUEUE::operator>>(int &e)
{
    int i, tmp;
    if (int(this->s2) == 0&&STACK::operator int() == 0) 
        throw std::underflow_error("QUEUE EMPTY.");
    if (int(this->s2) != 0)
        this->s2 >> e;
    else
    {
        while (STACK::operator int() != 0)
        {
            STACK::operator>>(tmp);
            this->s2 << tmp;
        }
        this->s2 >> e;
    }
    return (*this);
}
int QUEUE::operator[](int x) const
{
    if (x < 0 || x >= int(*this)) 
        throw std::range_error("Index out of range.");
    if (x < this->s2)
    {
        return this->s2[this->s2 - 1 - x];
    }
    return STACK::operator[](x - this->s2);
}
QUEUE &QUEUE::operator=(const QUEUE &s)
{
    STACK::operator=(s);
    this->s2 = s.s2;
}
void QUEUE::print() const
{
    int i;
    for (i = 0; i < int(this->s2); i++)
        printf("%d  ", this->s2[this->s2 - 1 - i]);
    for (i = 0; i < STACK::operator int(); i++)
        printf("%d  ", STACK::operator[](i));
}
QUEUE::~QUEUE()
{
    delete (&s2);
}