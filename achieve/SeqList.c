#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct SeqList1
{
    int data[SIZE];
    int length;
}SeqList1;

typedef struct SeqList2
{
    int* array;
    int length;
    int capacity;
}SeqList2;

void initListArray(SeqList2 *l,int capacity)
{
    l->array = (int *)malloc(sizeof(int)*capacity);
    l->capacity = capacity;
    l->length=0;
}

void initListMemory(SeqList2 *l,int capacity)
{
    l->array = (int *)malloc(sizeof(int)*capacity);
    l->capacity = capacity;
    l->length=0;
}

void SeqListDestory(SeqList2 *l){
    l->length = 0;
    l->capacity = 0;
}

int isEmpty(SeqList2 *l)
{
    return l==NULL;
}

int getLength(SeqList2 *l)
{
    return l->length;
}

int insertF(SeqList2 *l,int value)
{
    if (getLength(l)>=l->capacity)
        return 0;
    for (int i = l->length; i >=1; i++)
    {
        l->array[i]=l->array[i-1];
    }
    l->array[0]=value;
    l->length++;
}

int insertR(SeqList2 *l,int value)
{
    if (getLength(l)>=l->capacity)
        return 0;
    l->array[l->length]=value;
    l->length++;
}

int insertM(SeqList2 *l,int pos,int value)
{
    if (getLength(l)>=l->capacity)
        return 0;
    for (int i = l->length; i > pos; i--)
    {
        l->array[i] = l->array[i-1];
    }
    l->array[pos] = value;
    l->length++;
}

int deleteF(SeqList2 *l)
{
    if(l==NULL)
        return 0;
    for (int i = 0; i < l->length-1; i++)
    {
        l->array[i]=l->array[i+1];
    }
    l->length--;  
}

int deleteR(SeqList2 *l)
{
    l->length--;
}

int deleteM(SeqList2 *l,int pos)
{
    for (int i = pos; i < l->length; i++)
    {
        l->array[i]=l->array[i+1];
    }
    l->length--;
}

int main()
{
    SeqList2 *sq= (SeqList2 *)malloc(sizeof(SeqList2));
    initListMemory(sq,6);
    insertR(sq,1);
    insertR(sq,2);
    insertR(sq,3);
    insertR(sq,4);
    insertR(sq,4);
    insertM(sq,3,8);
    for (int i = 0; i < sq->length; i++)
    {
        printf("%d",sq->array[i]);
    }
    
    return 0;
}