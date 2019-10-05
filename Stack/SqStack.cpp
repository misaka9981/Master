#include <iostream>
using namespace std;
#define MaxSize 50
struct SqStack
{
    int data[MaxSize];//存放栈中的元素
    int top;//栈顶指针
};

void initStack(SqStack &st)
{
    st.top = -1;
}

int isEmpty(SqStack &st)
{
    return st.top==-1;
}

int push(SqStack &st,int x)
{
    if(st.top == 100-1)
        return 0;
    ++(st.top);
    st.data[st.top] = x;
        return 1;
}

int pop(SqStack &st,int &x)
{
    if(st.top == -1)
        return 0;
    x = st.data[st.top];
    --(st.top);
    return 1; 
}




int main()
{
    SqStack st;
    initStack(st);
    for (int i = 0; i < 10; i++)
    {
        st.data[i] = i;
    }
    
}
