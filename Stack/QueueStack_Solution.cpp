#include <iostream>
using namespace std;
#define MaxSize 50

typedef struct
{
    int elem[MaxSize];
    int top[2];
}SqStack;

int push(SqStack &st,int stNo,int x)
{
    if (st.top[0]+1<st.top[1])
    {
        if(stNo == 0)
        {
            ++(st.top[0]);
            st.elem[st.top[0]] = x;
            return 1;
        }
    }
    
}