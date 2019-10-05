#include <iostream>

using namespace std;

struct LNode
{
    int data;
    struct LNode *next;
};

void initStack(LNode *&lst)
{
    lst = (LNode *)malloc(sizeof(LNode));
    lst->next = NULL;
}

int isEmpty(LNode *lst)
{
    if(lst->next == NULL)
        return 1;
    else
        return 0;
}

void push(LNode *lst,int x)
{
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    p->next = NULL;
    p->data = x;
    p->next = lst->next;
    lst->next = p;
}

int pop(LNode *lst,int &x)
{
    LNode *p;
    if(lst->next == NULL)
        return 0;
    
    p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
    return 1;
}

void printLinkedListH(char* name, LNode *a){
    if(a==NULL){
        printf("empty LinkedList!!\n");
        return;
    }
    LNode *tmp;
    tmp = a->next;
    printf("LinkedList %s : [", name);
    while(tmp){
        printf(" %d ",tmp->data);
        tmp = tmp->next;
    }
    printf("]\n");
}

int main()
{
    LNode *A;
    initStack(A);
    push(A,1);
    push(A,2);
    push(A,3);
    push(A,4);
    push(A,5);
    push(A,6);
    printLinkedListH((char*) "A", A);
    return 0;
}





