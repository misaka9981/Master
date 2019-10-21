#include <iostream>
using namespace std;

struct SNode
{
    int data;
    struct SNode *next;
};

//头插法
void createListF(SNode *&L,int a[],int n)
{
    SNode *newNode;
    L = (SNode *)malloc(sizeof(SNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        newNode = (SNode *)malloc(sizeof(SNode));
        newNode->data = a[i];
        newNode->next = L->next;
        L->next = newNode;
    }
}

//尾插法
void createListR(SNode *&L,int a[],int n)
{
    L = (SNode *)malloc(sizeof(SNode));
    SNode *newNode,*r = L;
    for (int i = 0; i < n; i++)
    {
        newNode = (SNode *)malloc(sizeof(SNode));
        newNode->data = a[i];
        r->next = newNode;
        r = newNode;
    }
    r->next = NULL; 
}



void merge(SNode *A,SNode *B,SNode *&L)
{
    SNode *p = A->next;
    SNode *q = B->next;
    SNode *r;
    L = A;
    L -> next = NULL;
    free(B);
    r = L;
    while (p != NULL && q != NULL)
    {
        if (p->data <= q->data)
        {
            r ->next = p;
            p = p -> next;
            r = r->next;
        }
        else
        {
            r->next = q;
            q=q->next;
            r=r->next;
        }
    }
    r->next=NULL;
    if(p!=NULL)
        r->next=p;
    if(q!=NULL)
        r->next=q;
}

int findByIndex(SNode *L,int index)
{
    SNode *fNode;
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
int deleteNode(SNode *L,int x)
{
    SNode *p,*q;
    p = L;
    while (p->next != NULL)
    {
        if(p->next->data == x)
            break;
        p = p->next;
    }
    if(p->next == NULL)
        return 0;
    else
    {
        q=p->next;
        p->next=p->next->next;
        free(q);
        return 1;
    }
    
}



int main(void)
{
    SNode *A;
    int a[10]={1,2,3,4,6};
    int b[10]={7,9,12,34,56};
    //createListR(A,a,5);
    createListF(A,a,5);
    cout << findByIndex(A,5);
    // SNode *tmp;
    // tmp = A->next;
    // while(tmp){
    //     printf(" %d ",tmp->data);
    //     tmp = tmp->next;
    // }

    return 0;
}
