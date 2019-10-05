#include <iostream>
#define maxSize 100
using namespace std;

struct SeqList
{
    /* data */
    int data[maxSize];
    int length;
};

int findElem(SeqList L,int x)
{
    int i;
    for ( i = 0; i < L.length; i++)
    {
        if (x<L.data[i])
        {
            return i;
        }
    }
    return i;
}


void insertElem(SeqList &L,int x)
{
    int p,i;
    p=findElem(L,x);
    for ( i = L.length; i >= p; i--)
        L.data[i+1]=L.data[i];
    L.data[p] = x;
    (L.length)++;
}

int insertElem(SeqList &L,int p,int e)
{
    int i;
    if (p < 0 || p > L.length || L.length == maxSize)
        return 0;
    for (i = L.length; i >= p; i--)
    {
        L.data[i+1] = L.data[i];
    }
    L.data[p] = e;
    (L.length)++;
    return 1; 
}

int deleteElem(SeqList &L,int p,int &e)
{
    int i;
    if (p < 0 || p > L.length || L.length == maxSize)
        return 0;
    e = L.data[p];
    for ( i = p; i < L.length-1 ; i++)
        L.data[i]=L.data[i+1];
    (L.length)--;
    return 1; 
}

void initList(SeqList &L){
    L.length = 0;
}

int getElem(SeqList L,int p,int &e)
{
    if (p < 0 || p > L.length || L.length == maxSize)
        return 0;
    e=L.data[p];
    return 1;
}

int main(void)
{
    // 初始化结构体
    SeqList seqList;
    seqList.length = 0;
    for(int i=0; i<10; i++){
        seqList.data[i]=i+10;
        seqList.length++;
    }  
    // insertElem(seqList,7);
    // for (int i = 0; i < seqList.length; i++)
    //     cout << seqList.data[i] << endl;
    cout << getElem(seqList,0);
}