#include <iostream>
using namespace std;

typedef struct TBTNode
{
    char data;
    int ltag,rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
}TBTNode;

void InThread(TBTNode *p,TBTNode *&pre)
{
    if(p!=NULL)
    {
        InThread(p->lchild,pre);
        if(p->lchild==NULL)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL)
        {
            pre->rchild=p;
            pre->rtag=1;
        }
        pre = p;
        p=p->rchild;
        
        InThread(p,pre);
    }
}

void createInThread(TBTNode *root)
{
    TBTNode *pre=NULL;
    if(root!=NULL)
    {
        InThread(root,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}


TBTNode *First(TBTNode *p)
{
    while (p->ltag==0)
        p=p->lchild;
        return p; 
}

TBTNode *Next(TBTNode *p)
{
    if(p->rtag==0)
        return First(p->rchild);
    else
        return p->rchild;
}