#include "stack_struct.h"

void initSTACK(STACK *const p, int m)
{
    p->elems = (int *)malloc(sizeof(int) * m);
    p->pos = 0;
    p->max = m;
}

void initSTACK(STACK *const p, const STACK &s)
{
    p->elems = (int *)malloc(sizeof(int) * s.max);
    for (int i = 0; i < s.max; i++)
        *((p->elems) + i) = s.elems[i];
    p->pos = s.pos;
    p->max = s.max;
}

int size(const STACK *const p)
{
    return p->max;
}

int howMany(const STACK *const p)
{
    return p->pos;
}

int getelem(const STACK *const p, int x)
{
    if (x < 0 || x >= p->pos)
        throw std::range_error("Index out of range.");
    return p->elems[x];
}

STACK *const push(STACK *const p, int e)
{
    if (p->pos >= p->max)
        throw std::overflow_error("STACK FULL.");
    else
        p->elems[p->pos++] = e;
    return p;
}

STACK *const pop(STACK *const p, int &e)
{
    if (p->pos == 0)
        throw std::underflow_error("STACK EMPTY.");
    else
    {
        e = p->elems[--p->pos];
        p->elems[p->pos] = 0;
    }
    return p;
}

STACK *const assign(STACK *const p, const STACK &s)
{
    if (int(p) == int(&s))
        throw std::invalid_argument("COPY ITSELF.");
    free(p->elems);
    p->elems = (int *)malloc(sizeof(int) * s.max);
    for (int i = 0; i < s.pos; i++)
        *((p->elems) + i) = s.elems[i];
    p->pos = s.pos;
    p->max = s.max;
    return p;
}

void print(const STACK *const p)
{
    for (int i = 0; i < p->pos; i++)
        printf("%d  ", p->elems[i]);
}

void destroySTACK(STACK *const p)
{
    if (p->max != 0)
    {
        p->max = p->pos = 0;
        delete[] p->elems;
    }
}
