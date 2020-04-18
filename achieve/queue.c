#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int val;
    int *array;
    int front;
    int rear;
    int capacity;
    int length;
}queue;


int isEmpty(queue *q)
{
    return q->length==0;
}    

void makeEmpty(queue *q)
{
    q->length=0;
    q->front = 0;
    q->rear = 0;
}

queue * createQueue(int length)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->array = (int *)malloc(sizeof(int)*length);
    makeEmpty(q);
    q->capacity = length;
    return q;
}

void enqueue(queue *q,int val)
{
    if (q->length>=q->capacity)
    {
        printf("full");
    }else
    {
        q->array[q->rear] = val;
        q->rear = (q->rear+1)%q->capacity;
        q->length++;
    }
}

int deQueue(queue *q)
{
    if (q->length==0)
    {
        printf("empty");
    }else
    {
        int res = q->array[q->front];
        q->front = (q->front+1)%q->capacity;
        q->length--;
        return res;
    }
}

void queue_test(void){
    queue *q = createQueue(6);
    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 1);
    enqueue(q, 9);
    enqueue(q, 8);
    enqueue(q, 11);
}

int main()
{
    queue_test();
    return 0;
}



