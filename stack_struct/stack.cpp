#include <stdio.h>
#include <malloc.h>
#include "stack.h"
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
    return p->elems[x];
}
STACK *const push(STACK *const p, int e)
{
    if (p->pos != p->max)
    {
        p->elems[p->pos] = e;
        p->pos++;
    }
    else
        return NULL;
    return p;
}
STACK *const pop(STACK *const p, int &e)
{
    if (p->pos > 0)
    {
        p->pos--;
        e = p->elems[p->pos];
    }
    else
        return NULL;
    return p;
}
STACK *const assign(STACK *const p, const STACK &s)
{
    free(p->elems);
    p->elems = (int *)malloc(sizeof(int) * s.max);
    for (int i = 0; i < s.max; i++)
        *((p->elems) + i) = s.elems[i];
    p->pos = s.pos;
    p->max = s.max;
    return p;
}
void print(const STACK *const p)
{
    int i = 0;
    for (i = 0; i < p->pos; i++)
    {
        printf("%d  ", p->elems[i]);
    }
}
void destroySTACK(STACK *const p)
{
    if(p->max!=0){
        p->pos = 0;
        p->max = 0;
        free(p->elems);
    }
}
