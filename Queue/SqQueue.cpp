#include <iostream>
using namespace std;
#define MaxSize 10
struct SqQueue
{
    int data[MaxSize];
    int front;
    int rear;
};


void initQueue(SqQueue &qu)
{
    qu.front = qu.rear = 0;
}

int isQueueEmpty(SqQueue &qu)
{
    return qu.front == qu.rear;
}

int enQueue(SqQueue &qu,int x)
{
    if ((qu.rear+1)%MaxSize == qu.front)
        return 0;
    qu.rear = (qu.rear+1)%MaxSize;
    qu.data[qu.rear] = x;
    return 1; 
}

int deQueue(SqQueue &qu,int &x)
{
    if (qu.rear == qu.front)
        return 0;
    qu.front = (qu.front+1)%MaxSize;
    x = qu.data[qu.front];
    return 1; 
}