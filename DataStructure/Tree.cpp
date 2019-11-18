#include <iostream>
#include "../utility/Stack/SqStack.h"
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* makeEmpty(TreeNode *root)
{
    if (root!=NULL)
    {
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
    }
    
    return NULL;
}

TreeNode* find(int x,TreeNode *root)
{
    if(root==NULL)
        return NULL;
    if(root->value==x)
        return root;
    else if(x<root->value)
        return find(x,root->left);
    else
        return find(x,root->right);
}

TreeNode* createTreeNode(int value)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left=NULL;
    node->right=NULL;
    node->value=value;
    return node;
}

//中序1
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

//前序1
TreeNode* preOrder_Print1(TreeNode *root)
{
    if(root!=NULL)
    {
        cout << root->value << endl;
        if(root->left!=NULL)
        {
            inOrder_Print1(root->left);
        }
        if(root->right!=NULL)
        {
            inOrder_Print1(root->right);
        }
    }
}

//后序1
TreeNode* postOrder_Print1(TreeNode *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
        {
            inOrder_Print1(root->left);
        }
        if(root->right!=NULL)
        {
            inOrder_Print1(root->right);
        }
        cout << root->value << endl;
    }
}

//前序2
TreeNode* preOrder_Print2(TreeNode *root)
{
    int top=-1;
    TreeNode* stack[10];
    stack[++top]=root;
    TreeNode* tmpNode=NULL;
    while (top!=-1)
    {
        tmpNode=stack[top--];
        cout << tmpNode->value << endl;
        if(tmpNode->right!=NULL)
            stack[++top]=tmpNode->right;
        if(tmpNode->left!=NULL)
            stack[++top]=tmpNode->left;
    }   
}
//中序
TreeNode* inOrder_Print2(TreeNode *root)
{
    if(root!=NULL)
    {
        TreeNode* stack[10];
        int top=-1;
        TreeNode* tmpNode = root;
        while (top!=-1 || tmpNode!=NULL)
        {
            while (tmpNode!=NULL)
            {
                stack[++top]=tmpNode;
                tmpNode=tmpNode->left;
            }
            if (top!=-1)
            {
                tmpNode=stack[top--];
                cout << tmpNode->value << endl;
                tmpNode=tmpNode->right;
            }
        }
        
    }
}


TreeNode* TreeSearch(TreeNode *root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if (value>root->value)
    {
        return TreeSearch(root->right,value);
    }
    else if (value<root->value)
    {
        return TreeSearch(root->left,value);
    }
    else return root;
    
    
}

TreeNode* TreeInsert1(TreeNode *root,int value)
{
    if(root == NULL)
    {
        root = createTreeNode(value);
    }
    else
    {
        if(value < root->value)
        {
            root->left = TreeInsert1(root->left,value);
        }
        if (value >= root->value)
        {
            root->right = TreeInsert1(root->right,value);
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
    BST = TreeInsert1(BST, 9);
    BST = TreeInsert1(BST, 5);
    BST = TreeInsert1(BST, 3);
    BST = TreeInsert1(BST, 1);
    BST = TreeInsert1(BST, 7);
    BST = TreeInsert1(BST, 4);
    BST = TreeInsert1(BST, 2);
    BST = TreeInsert1(BST, 11);
    preOrder_Print2(BST);
    return 0;
}




