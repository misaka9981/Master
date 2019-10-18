#include <iostream>
using namespace std;


class BTNode
{
    public:
    int data;
    BTNode *lchild,*rchild;

    BTNode(int val)
    {
        this->data = val;
        lchild = NULL;
        rchild = NULL;
    }
};

void preOrder(BTNode *&bt)
{
    if (bt == NULL)
        return;
    cout << bt->data<<endl;
    preOrder(bt->lchild);
    preOrder(bt->rchild);
}

void inOrder(BTNode *bt)
{
    if (bt == NULL)
        return;
    cout << bt->data<<endl;
    inOrder(bt->lchild);
    inOrder(bt->rchild);
}

void postOrder(BTNode *bt)
{
    if (bt == NULL)
        return;
    cout << bt->data<<endl;
    postOrder(bt->lchild);
    postOrder(bt->rchild);
}


void preOrderNon(BTNode *bt)
{
    if (bt!=NULL)
    {
        BTNode *Stack[10];
        int top = -1;
        BTNode *p;
        Stack[++top] = bt;
        while (top!=-1)
        {
            p = Stack[top--];
            cout << p ->data << endl;
            if(p->rchild!=NULL)
                Stack[++top] = p->rchild;
            if(p->lchild!=NULL)
                Stack[++top] = p->lchild;
        }
        
    }
    
}



int main()
{
    BTNode *root = new BTNode(1);
    BTNode *node1 = new BTNode(2);
    BTNode *node2 = new BTNode(3);
    BTNode *node3 = new BTNode(4);
    BTNode *node4 = new BTNode(5);
    BTNode *node5 = new BTNode(6);
    BTNode *node6 = new BTNode(7); 
    root->lchild = node1;
    root->rchild = node2;
    node1->lchild = node3;
    node1->rchild = node4;
    node2->lchild = node5;
    node2->rchild = node6; 
    preOrderNon(root);  
    return 0;
}


