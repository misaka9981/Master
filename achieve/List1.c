#include <stdio.h>
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
    assert(l!=NULL);
    l->array = (int *)malloc(sizeof(int)*capacity);
    l->capacity = capacity;
    l->length=0;
}

void initListMemory(SeqList2 *l,int capacity)
{
    assert(l!=NULL);
    l->array = (int *)malloc(sizeof(int)*capacity);
    l->capacity = capacity;
    l->length=0;
}

void SeqListDestory(SeqList2 *l){
    assert(l!=NULL);
    assert(l->array!=NULL);
    free(l->array);
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

int insertM(SeqList2 *l,int value)
{
    if (getLength(l)>=l->capacity)
        return 0;
    l->array[l->length] = value;
    l->length++;
}

