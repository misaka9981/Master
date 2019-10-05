#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};

Node* createNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = nullptr;
    node->data = val;
    return node;
}

Node* LinkList_search(Node *lst, int val)
{
    if(lst == NULL)
    {
        return 0;
    }else if (lst->data == val)
    {
        return lst;
    }else
    {
        return LinkList_search(lst->next,val);
    }
}

void LinkList_insertF(Node *lst,int val)
{
    Node *pNode;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    pNode = lst;
    if(pNode->next == NULL)
    {
        newNode->next = NULL;
        pNode->next = newNode;
    }else
    {
        Node *tmp = pNode->next;
        pNode->next = newNode;
        newNode->next = tmp;
    }
    lst->data++;
}

void LinkList_insertR(Node *lst,int val)
{
    Node *pNode;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    pNode = lst;
    while (pNode->next != NULL)
    {
        pNode = pNode->next;
    }
    pNode->next = newNode;
    newNode->next = NULL;
}

void LinkList_insertByIndex(Node *lst, int val, int index)
{
    Node *tmp = lst;
    for (int i = 1; i <= index;++i)
    {
        tmp = tmp->next;
        if(tmp == NULL){
            return;
        }
    }
    Node *newNode = createNode(val);
    newNode->next = tmp->next;
    tmp->next = newNode;
    lst->data++;
}

Node * findNode(Node * head, int loc)
{
    Node *tmp = head;
    for (int i = 0; i <= loc; i++)
    {
        tmp = tmp->next;
        if(tmp == NULL)
        {
            return NULL;
        }
    }
    return tmp;
}

int LinkList_delete(Node *lst, int index)
{
    Node *tmp1 = findNode(lst,index);
    Node *tmp2 = tmp1->next;
    int res = tmp2->data;
    tmp1->next = tmp2->next;
    lst->data--;
    return res;
}

void LinkList_push(Node *lst, int val)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->data = val;
    p->next = lst->next;
    lst->next = p;
    lst->data++;
}

int LinkList_pop(Node * lst)
{
    Node *tmp = lst->next;
    int res = tmp->data;
    lst->next = tmp->next;
    lst->data--;
    return res;
}

void LinkList_enqueue(Node *lst, int val)
{
    Node *newNode = createNode(val);
    Node *tmp = findNode(lst,lst->data-1);
    newNode->next = tmp->next;
    tmp->next = newNode;
    lst->data++;
}

int LinkList_dequeue(Node *lst)
{

}

void LinkList_print(Node *lst)
{
    Node *tmp;
    tmp = lst->next;
    while (tmp)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
    
}

void linklist_test(void)
{
    Node * lst = createNode(0);    //头节点记录链表的长度
    LinkList_enqueue(lst,1);
    LinkList_enqueue(lst,2);
    LinkList_enqueue(lst,3);
    LinkList_enqueue(lst,4);
    LinkList_enqueue(lst,5);
    LinkList_enqueue(lst,6);
    LinkList_enqueue(lst,7);
    LinkList_enqueue(lst,8);
    LinkList_print(lst);
}

int main()
{
    linklist_test();
    return 0;
}