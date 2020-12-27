#include <iostream>
using namespace std;

struct AvlNode
{
    int data;
    AvlNode *right;
    AvlNode *left;
    AvlNode *parent;
    int height;
};

AvlNode * createavlNode(int val)
{
    AvlNode *Node = (AvlNode *)malloc(sizeof(AvlNode));
    Node->left=NULL;
    Node->right=NULL;
    Node->parent=NULL;
    Node->data=val;
    Node->height=0;
    return Node;
}

void Avl_print(AvlNode *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
        {
            Avl_print(root->left);
        }
        cout << root->data << endl;
        if(root->right!=NULL)
        {
            Avl_print(root->right);
        }
    }
}

int getHeight(AvlNode *root)
{
    if(root==NULL)
        return -1;
    else
        return root->height;
}

int Max(int a,int b)
{
    return a>b?a:b;
}


AvlNode * zag(AvlNode *A)//左旋
{
    AvlNode *B = A->right;
    A->right = B->left;
    B->left = A;
    A->height=Max(getHeight(A->left),getHeight(A->right))+1;
    B->height=Max(getHeight(B->left),getHeight(B->right))+1;
    return B;
}

AvlNode * zig(AvlNode *A)//右旋
{
    AvlNode *B = A->left;
    A->left = B->right;
    B->right = A;
    A->height=Max(getHeight(A->left),getHeight(A->right))+1;
    B->height=Max(getHeight(B->left),getHeight(B->right))+1;
    return B;
}

AvlNode * zigzaag(AvlNode *A)//左旋
{
    A->right=zig(A->right);
    return zag(A);
}

AvlNode * zagzig(AvlNode *A)//左旋
{
    A->left=zig(A->left);
    return zig(A);
}


