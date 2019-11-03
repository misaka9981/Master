#include <iostream>
#include "../utility/Stack/SqStack.h"
using namespace std;

typedef struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

TreeNode* createTreeNode(int value)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left=NULL;
    node->right=NULL;
    node->parent=NULL;
    node->value=value;
    return node;
}


TreeNode* inOrder_Print1(TreeNode *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
        {
            inOrder_Print1(root->left);
        }
        cout << root->value << endl;
        if(root->right!=NULL)
        {
            inOrder_Print1(root->right);
        }
    }
}

TreeNode* inOrder_Print2(TreeNode *root)
{
    int top=-1;
    TreeNode* stack[10];
    stack[++top]=root;
    TreeNode* tmpNode=root;
    while (top!=-1 || tmpNode!=NULL)
    {
        while (tmpNode->left!=NULL)
        {
            tmpNode = tmpNode->left;
            stack[++top]=tmpNode;
        }
        tmpNode = stack[--top];
        cout<<tmpNode->value;
        if (tmpNode->right!=NULL)
        {
           tmpNode = tmpNode->right;
           stack[++top] = tmpNode; 
        }
    }   
}



TreeNode* TreeSearch(TreeNode *root,int value)
{

}

TreeNode* TreeInsert1(TreeNode *root,int value,TreeNode* parent)
{
    if(root == NULL)
    {
        root = createTreeNode(value);
        root->parent = parent;
    }
    else
    {
        if(value < root->value)
        {
            root->left = TreeInsert1(root->left,value,root);
        }
        if (value >= root->value)
        {
            root->right = TreeInsert1(root->right,value,root);
        }
    }
    return root;
    
}


TreeNode* TreeInsert2(TreeNode *root,int value)
{
    if (root==NULL)
    {
        root = createTreeNode(value);
    }
    else
    {
        TreeNode *pre = root;
        TreeNode *cur = root;
        while (cur!=NULL)
        {
            pre = cur;
            if(value<pre->value){
                cur = pre->left;
            }
            else if (value >= pre->value)
            {
                cur = pre->right;
            }
        }
        cur = createTreeNode(value);
        cur->parent = pre;
        if(value < pre->value)
            pre->left = cur;
        else if(value >= pre->value)
            pre->right = cur;
    }
    return root;
}

TreeNode* TreeDelete(TreeNode* root,int value)
{

}

int main()
{
    TreeNode * BST = NULL;
    BST = TreeInsert2(BST, 9);
    BST = TreeInsert2(BST, 5);
    BST = TreeInsert2(BST, 3);
    BST = TreeInsert2(BST, 1);
    BST = TreeInsert2(BST, 7);
    BST = TreeInsert2(BST, 4);
    BST = TreeInsert2(BST, 2);
    BST = TreeInsert2(BST, 11);


    
    inOrder_Print1(BST);
   
   
    
    return 0;
}




