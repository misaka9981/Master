#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
    int data;
    struct stackNode *next;
}stackNode;

stackNode * CreateNode(int value)
{
    stackNode *node =(stackNode *)malloc(sizeof(stackNode));
    node->data = value;
    node->next =NULL;
    return node;
}

int isEmpty(stackNode *s)
{
    return s->next == NULL;
}

void makeEmpty(stackNode *s)
{
    if(s==NULL)
    {
        printf("empty");
    }
    else
    {
        while (!isEmpty(s))
        {
            pop(s);
        }
        
    }
    
}

void push(stackNode *s,int val)
{
    stackNode *newNode ;
    newNode = (stackNode *)malloc(sizeof(stackNode));
    newNode->data = val;
    newNode->next = s->next;
    s->next = newNode;
}

void pop(stackNode *s)
{
    stackNode *tmp;
    tmp = s->next;
    s->next = s->next->next;
    free(tmp);
}