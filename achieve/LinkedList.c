#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node * CreateNode(int value)
{
    Node *node =(Node *)malloc(sizeof(Node));
    node->data = value;
    node->next =NULL;
    return node;
}

Node* LinkedListSearchByVal(Node *head,int value)
{
    if(head==NULL)
    {
        return NULL;
    }
    while (head->data!=value)
    {
        head = head->next;
    }
    return head;
   //等同于LinkedListSearchByVal(head->next,value)
}

Node* LinkedListSearchByIndex(Node* head,int index)
{
    Node *tmp=head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return tmp;
    
}

void LinkedListInsertF(Node* head,int val)
{
    if (head==NULL)
    {
        printf("error");
    }else
    {
        Node *tmpNode = (Node *)malloc(sizeof(Node));
        tmpNode->data=val;
        tmpNode->next=head->next;
        head->next = tmpNode;
    }
}

void LinkedListInsertR(Node* head,int val)
{
    if (head==NULL)
    {
        printf("error");
    }else
    {
    Node *tmpNode = (Node *)malloc(sizeof(Node));
    tmpNode->data=val;
    Node *s = head;
    while (s->next!=NULL)
        s = s->next;
    s->next=tmpNode;
    tmpNode->next=NULL;
    }
}

void LinkedListInsertM(Node* head,int val,int index)
{
    if (head==NULL)
    {
        printf("error");
    }else
    {
    for (int i = 0; i < index; i++)
    {
        head = head->next;
    }
    Node *tmp = head->next;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = tmp;
    head->next = newNode;
    }
}

Node* LinkedListDeleteF(Node* head)
{
    // Node *tmp;
    // tmp = head->next;
    // free(head);
    // return tmp;
    return head->next;
}

Node* LinkedListDeleteR(Node* head)
{
    Node *tmp = head;
    while (tmp->next->next!=NULL)
    {
        tmp = tmp->next;
    }
    tmp->next=NULL;
    return head;
}

Node* LinkedListDeleteByVal(Node* head,int val)
{
    while (head!=NULL)
    {
        if(head->data!=val)
            break;
        head = head->next;
    }
    Node *pre =head;
    Node *cur = head;
    while (cur!=NULL)
    {
        if(cur->data==val)
        {
            pre->next = cur->next;
        }else
        {
            pre=cur;
        }
        cur = cur->next;
        
    }
    return head;
}   
    
    



Node* LinkedListDeleteByPos(Node* head,int index)
{
    Node *tmp = head;
    for (int i = 0; i < index-1; i++)
    {
        tmp = tmp->next;
    }
    Node *tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);
    return head;
}
int main()
{
    Node* head = CreateNode(1);
    LinkedListInsertR(head,2);
    LinkedListInsertR(head,3);
    LinkedListInsertR(head,4);
    LinkedListInsertR(head,5);
    LinkedListInsertR(head,6);
    LinkedListInsertM(head,11,3);
    head = LinkedListDeleteByPos(head,2);
    //head = LinkedListDeleteByVal(head,3);
    // Node* tmp = LinkedListSearchByVal(head,6);
    // printf("%d",tmp->data);
    while (head!=NULL)
    {
        printf("%d",head->data);
        head = head->next;
    }
    
    return 0;
}