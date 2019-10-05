#include <iostream>
#include "../utility/LinearTable/SqList.h"
using namespace std;

bool deleteMin(SqList &st)
{
    int min = st.data[0];
    int index = 0;
    if(st.length == 0)
        return 0;
    for (int i = 0; i < st.length; i++)
    {
        if(st.data[i]<min)
        {
            min  = st.data[i];
            index = i;
        }
    }
    st.data[index] = st.data[st.length-1];
    st.length--;
    return 1;
}
//需要优化
void reverse(SqList &st)
{
    for (int i = 0; i < st.length/2-1; i++)
    {
        if(st.length%2==0)
        {
            for (int j = st.length/2; j <= st.length-1; j++)
            {
                int tmp = st.data[j];
                st.data[j] = st.data[i];
                st.data[i] = tmp;
            }  
        }else
        {
           for (int j = st.length/2+1; j <= st.length-1; j++)
            {
                int tmp = st.data[j];
                st.data[j] = st.data[i];
                st.data[i] = tmp;
            } 
        }
        
    }
}
//需要优化
void deleteAllMatch(SqList &st,int val)
{
    for (int i = 0; i < st.length; i++)
    {
        if (st.data[i] == val)
        {
            for (int j = i; j < st.length; j++)
            {
                st.data[j] = st.data[j+1];
            }
            
        }
    }
    
}


bool deleteRange(SqList &st,int s,int t)
{
    int range[st.length];
    int i;
    int j = 0;
    if(s >= t)
    {
        return;
    }
    for (i = 0; i < st.length; i++)
    {
        if(st.data[i] >= s && st.data[i] <= t)
            range[j++] = i;
    }
}

bool deleteRangeS(SqList &st,int s,int t)
{
    int i,j;
    if(s >= t)
    {
        return;
    }
    for (i = 0; i < st.length && st.data[i] < s; i++);
    for(j = i;j<st.length && st.data[j] <= t;j++);
    for(;j<st.length;i++,j++);
        st.data[i] = st.data[j];
    st.length = i;
    return 1;
}

void change(int a[],int m,int n)
{
    
}

int main()
{
    int a = 7;
    cout << a/2;
    return 0;
}