#include <iostream>
using namespace std;

typedef struct Node *ptrToNode;
typedef ptrToNode Stack;

struct Node
{
    int data;
    ptrToNode next;
};

bool isEmpty(Stack s)
{
    return s->next==NULL;
}

void push(int x,Stack s)
{
    ptrToNode tmp;
    tmp = new Node;
    if(tmp == NULL)
    {
        return;
    }
    tmp->data = x;
    tmp->next = s->next;
    s->next = tmp;
}

int pop(Stack s)
{
    if (isEmpty(s))
    {
        return 0;
    }
    int tmp;
    ptrToNode p;
    p = s->next;
    tmp = p->data;
    s->next = p->next;
    delete p;
    return tmp;
}

Stack createStack()
{
    Stack s;
    s = new Node;
    if(s!=NULL)
    {
        s->next=NULL;
    }
    return s;
}

void makeEmpty(Stack s)
{
    if (s != NULL)
    {
        while (!isEmpty(s))
        pop(s);
    }
}

void didposeStack(Stack s)
{
    while (!isEmpty(s))
        pop(s);    
}



int main()
{
    Stack s = createStack();

    push(2,s);
    push(3,s);
    pop(s);
    pop(s);
    return 0;
}