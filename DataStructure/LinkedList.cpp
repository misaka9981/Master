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
    LNode *newNode,*r=head;
    for (int i = 0; i < n; i++)
    {
        newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data=A[i];
        r->next=newNode;
        r=newNode;
        head->data++;
    }
    r->next=NULL;
    // LNode *newNode;
    // for (int i = 0; i < n; i++)
    // {
    //     newNode = (LNode *)malloc(sizeof(LNode));
    //     newNode->data=A[i];
    //     head->next=newNode;
    //     head=newNode;
    //     head->data++;
    // }
    // head->next=NULL;
    
}
LNode* findNode(LNode *head,int index)
{
    LNode *tmp = head;
    for (int i = 0; i <= index; i++)
    {
        tmp = tmp->next;
        if(tmp==NULL)
            return NULL;
    }
    return tmp;
    
}


void insertByIndex(LNode *head,int value,int loc)
{
    LNode *newNode = createNode(value);
    LNode *tmp = findNode(head,loc-1);
    if(tmp=NULL)
    {
        return ;
    }
    else
    {
        newNode->next = tmp->next;
        tmp->next = newNode;
        head->data++;
    }
}
int LinkedList_delete(LNode *head,int index)
{
    LNode *tmpNode = findNode(head,index-1);
    LNode *deleteNode = tmpNode->next;
    if(deleteNode==NULL)
    {
        cout <<"error"<<endl;
        return 0;
    }
    else
    {
        tmpNode->next=deleteNode->next;
        free(deleteNode);
        head->data--;
        return 1;
    }
}

void LinkedList_push(LNode *head,int value)
{
    LNode *newNode = createNode(value);
    newNode->next = head->next;
    head->next = newNode;
    head->data++;
}

int LinkedList_pop(LNode *head)
{
    LNode *tmp = head->next;
    int res = tmp->data;
    head->next = tmp->next;
    free(tmp);
    head->data--;
    return res;
}

void LinkedList_enqueue(LNode *head,int value)
{
    LNode *newNode = createNode(value);
    LNode *tmp = findNode(head,head->data);
    tmp->next = newNode;
    head->data++;
}



int main()
{

}
