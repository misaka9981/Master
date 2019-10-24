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
    
}

TreeNode* TreeSearch(TreeNode *root,int value)
{

}

TreeNode* TreeInsert(TreeNode *root,int value)
{

}

TreeNode* TreeDelete(TreeNode* root,int value)
{

}




