#include <iostream>
using namespace std;


struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
};

void createDListR(DNode *&L,int a[],int n)
{
    DNode *s,*r;
    int i;
    L = (DNode *)malloc(sizeof(DNode));
    L->next = NULL;
    L->prev = NULL;
    r = L;
    for (i = 0; i < n; ++i)
    {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = a[i];
        r->next = s;
        s->prev = r;
        r = s;
    }
    r->next = NULL;
    
}

int findByIndex(DNode *L,int index)
{
    DNode *fNode;
    int i=1;
    fNode = L;
    while (fNode->next != NULL)
    {
        if (i == index)
        {
            return fNode->next->data;
        }
        else
            fNode = fNode->next;
            i++;
    }
    
}

void insertDNode(DNode *&L,int data,int index)
{
    DNode *newNode,*p;
    p = L;
    int i = 1;
    newNode->data = data;
    while (i != index)
    {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    newNode->prev = p;
    p->next = newNode;
    newNode->next->prev = newNode;
}

int main(int argc, char const *argv[])
{
    DNode *A;
    int a[10]={1,2,3,4,6};
    int b[10]={7,9,12,34,56};
    createDListR(A,a,5);
    insertDNode(A,7,3);
    //cout << findByIndex(A,2);
    return 0;
}

