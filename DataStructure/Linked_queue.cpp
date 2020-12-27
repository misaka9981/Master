#include <iostream>
using namespace std;

struct queueInfor
{
    struct Node *front;
    struct Node *rear;
};

typedef queueInfor *queue;

struct Node
{
    int data;
    struct Node* next;
};

bool isEmpty(queue q)
{
    return q->front==NULL;
}

queue createQueue()
{
    queue q;
    q = new queueInfor;
    if(q==NULL)
    {
        return NULL;
    }
    q->rear=NULL;
    q->front=NULL;
    return q;
}

int deQueue(queue q)
{
   if(isEmpty(q))
   {
       return 0;
   }
   int tmp;
   struct Node *p;
   p = new Node;
   tmp = q->front->data;
   p=q->front;
   q->front=p->next;
   delete p;
   if(q->front==NULL)
   {
       q->rear=NULL;
   }
    return tmp;
}

void enQueue(int x,queue q)
{
    struct Node *tmp;
    tmp = (Node *)malloc(sizeof(Node));
    if(tmp==NULL)
    {
        return;
    }
    tmp->data=x;
    tmp->next = NULL;
    if(q->rear == NULL)
    {
        q->rear=q->front=tmp;
    }
    else
    {
        q->rear->next=tmp;
        q->rear = tmp;
    }
}

int main()
{
    queue q;
    q=createQueue();
    enQueue(2,q);
    enQueue(3,q);
    enQueue(4,q);
    deQueue(q);
    return 0;
}



