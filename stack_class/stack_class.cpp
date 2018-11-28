#include "stack_class.h"

STACK::STACK(int m) : max(m), elems((int *)malloc(sizeof(int) * m))
{
    this->pos = 0;
}

STACK::STACK(const STACK &s) : max(s.max), elems((int *)malloc(sizeof(int) * s.max))
{
    this->pos = s.pos;
    for (int i = 0; i < s.pos; i++)
        this->elems[i] = s.elems[i];
}

int STACK::size() const
{
    return this->max;
}

int STACK::howMany() const
{
    return this->pos;
}

int STACK::getelem(int x) const
{
    if (x < 0 || x >= pos)
        throw std::range_error("Index out of range.");
    return this->elems[x];
}

STACK &STACK::push(int e)
{
    if (this->pos == this->max)
        throw std::overflow_error("STACK FULL.");
    this->elems[this->pos++] = e;
    return *this;
}

STACK &STACK::pop(int &e)
{
    if (this->pos == 0)
        throw std::underflow_error("STACK EMPTY.");
    e = this->elems[--this->pos];
    this->elems[this->pos] = 0;
    return *this;
}

STACK &STACK::assign(const STACK &s)
{
    if (int(this) == int(&s))
        return *this;
    this->pos = s.pos;
    *(int *)&(this->max) = s.size();
    for (int i = 0; i < this->pos; i++)
        this->elems[i] = s.elems[i];
    return *this;
}

void STACK::print() const
{
    for (int i = 0; i < this->pos; i++)
        printf("%d  ", this->elems[i]);
}

STACK::~STACK()
{
    delete[] elems;
    *(int *)&max = pos = 0;
}
