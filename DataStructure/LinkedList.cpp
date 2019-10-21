#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LnNde;

LNode* createNode(int value)
{
    LNode *node = (LNode  *)malloc(sizeof(LNode));
    node->data = value;
    node->next = NULL;
    return node;
}

void LinkedList_insertF(LNode *head,int A[],int n)
{
    LNode *newNode;
    for (int i = 0; i < n; i++)
    {
        newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data=A[i];
        newNode->next=head->next;
        head->next=newNode;
        head->data++;
    }
}


void LinkedList_insertR(LNode *head,int A[],int n)
{
    // LNode *newNode,*r=head;
    // for (int i = 0; i < n; i++)
    // {
    //     newNode = (LNode *)malloc(sizeof(LNode));
    //     newNode->data=A[i];
    //     r->next=newNode;
    //     r=newNode;
    //     head->data++;
    // }
    // r->next=NULL;
    LNode *newNode;
    for (int i = 0; i < n; i++)
    {
        newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data=A[i];
        head->next=newNode;
        head=newNode;
        head->data++;
    }
    head->next=NULL;
    
}

void insertByIndex(LNode *head,int value,int loc)
{
    LNode *newNode = createNode(value);
    LNode *tmp;
}

int main()
{
    LNode *head = (LNode *)malloc(sizeof(LNode));
    head->data = 0;
    head->next=NULL;
    int A[13]={1,2,3,4,5,6,7,5,9,7,2,4,6};
    LinkedList_insertR(head,A,13);
    return 0;
}
