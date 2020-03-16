#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int* array;
    int capacity;
    int top;
}Stack;

int isEmpty(Stack *s)
{
    return s->top==-1;
}

int isFull(Stack *s)
{
    return s->top==s->capacity-1;
}

Stack* createStack(int max)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s==NULL)
        return NULL;
    s->capacity=max;
    s->array = (int *)malloc(sizeof(int)*s->capacity);
    makeEmpty(s);
    return s;
}

void makeEmpty(Stack *s)
{
    s->top=-1;
}

void dispose(Stack *s)
{
    if(s!=NULL)
    {
        free(s->array);
        free(s);
    }
}

void pop(Stack *s,int val)
{
    if (isEmpty(s))
    {
        printf("empty");
    }else
    {
        s->top--;
    }
    
    
}

void push(Stack *s,int val)
{
    if (isFull(s))
    {
        printf("full");
    }else{
        s->top++;
        s->array[s->top]=val;
    }
}


