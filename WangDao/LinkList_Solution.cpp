#include <iostream>
#include "../utility/LinearTable/LinkedList.h"
using namespace std;


//递归删除不带头结点的单链表L所有给定值的节点

void deleteX(LNode *&lst,int x)
{
    LNode *pNode;
    if(lst == NULL)
        return;
    if(lst->data == x)
    {
        pNode = lst;
        lst = lst->next;
        delete pNode;
        deleteX(lst,x);
    }
    else
    {
        deleteX(lst->next,x);
    }    
} 

//带头结点的链表删除给定值的节点，并释放空间，节点不唯一
void deleteX2(LNode *&lst,int x)
{
    LNode *pNode = lst->next;
    LNode *preNode =lst;
    LNode *tmp;
    while (pNode != NULL)
    {
        if(pNode->data == x)
        {
           tmp = pNode;
           pNode = pNode->next;
           preNode->next = pNode;
           free(tmp);
        }
        else
        {
            preNode = pNode;
            pNode = pNode->next;
        }
    }
    
}

//带头节点的单链表，逆向输出
//为什么是最后输出这些节点的值的
void reversePrint(LNode *lst)
{
    if(lst->next!=NULL)
    {
        reversePrint(lst->next);
    }
    cout <<  lst->data << endl;
}

//带头节点的单链表删除最小节点的高效算法，最小节点唯一
void deleteMin(LNode *&lst)
{
    LNode *pre = lst;
    LNode *p = pre->next;
    LNode *minpre = pre,*min = p;
    while (p!=NULL)
    {
        if(p->data<min->data)
        {
            min = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = min->next;
    free(min);
}

//编写空间复杂度为O(1)的算法，将带头节点的链表逆置
void reverseD(LNode *&lst)
{
    LNode *rear,*p;
    p = lst->next;
    lst->next = NULL;
    while (p!=NULL)
    {
        rear = p->next;
        p->next = lst->next;
        lst->next = p;
        p = rear;
    }
}

int main()
{
    LNode *test;
    int a[10] = {1,2,3,3,3,6,7,8,9,10};
    createListR(test,a,10);
    //reversePrint(test);
    //deleteX2(test,3);
    //deleteMin(test);
    reverseD(test);
    LNode *tmp = test->next;
    while (tmp != NULL)
    {
        cout << tmp->data <<endl;
        tmp = tmp->next;
    }
    return 0;
}