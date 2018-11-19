#include"../stack_op/stack_op.h"
#include<stdexcept>
class QUEUE:public STACK{
    STACK  s2;
public:
    int full() const;
    QUEUE(int m);		//初始化队列：每个栈最多m个元素
    QUEUE(const QUEUE&s); 		//用队列s拷贝初始化队列
    operator int ( ) const;			//返回队列的实际元素个数
    QUEUE& operator<<(int e); 		//将e入队列,并返回队列
    QUEUE& operator>>(int &e);	//出队列到e,并返回队列
    int operator[ ](int x)const;   //取下标为x的元素,第1个元素下标为0
    QUEUE& operator=(const QUEUE&s); //赋s给队列,并返回被赋值的队列
    void print( ) const;			//打印队列
    ~QUEUE( );					//销毁队列
};

