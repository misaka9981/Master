#include "BST.h"
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;


TreeNode* createTreeNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode*));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->val = val;
    return node;
}

TreeNode * makeEmpty(TreeNode * root)
{
    if(root!=NULL)
    {
        makeEmpty(root->left);
        makeEmpty(root->right);
        makeEmpty(root->parent);
        free(root);
    }
    return NULL;
}

TreeNode * insertByWhile(TreeNode * root,int val)
{
    if(root==NULL)
    {
        root = createTreeNode(val);
    }
    else
    {
        TreeNode * pre = root;
        TreeNode * cur = root;
        while (cur!=NULL)
        {
            pre = cur;
            if (val<pre->val)
            {
                cur = pre->left;
            }
            else if (val >= pre->val)
            {
                cur = pre->right;
            }
        }
        cur = createTreeNode(val);
        cur->parent = pre;
        if(val < pre->val)
            pre->left = cur;
        else if(val >= pre->val)
            pre->right = cur;
    }
    return root;
    
}



TreeNode* findByValue(TreeNode* root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    if (root->val==val)
    {
        return root;
    }else if (val < root->val)
    {
        findByValue(root->left,val);
    }else
    {
        findByValue(root->right,val);
    }
}

void inorderTreePrint(TreeNode *root)
{
    if(root != NULL){
        if (root->left!=NULL)
        {
            inorderTreePrint(root->left);
        }
        printf("%d",root->val);
        if (root->right!=NULL)
        {
            inorderTreePrint(root->right);
        }
        
    }
}

TreeNode * insertByRe(TreeNode *root,int val)
{
    if (root==NULL)
    {
        root=createTreeNode(val);
    }
    else if (val < root->val)
    {
        root->left = insertByRe(root->left,val);
    }
    else if (val > root->val)
    {
        root->right = insertByRe(root->right,val);
    }
    return root;
}

TreeNode * findMin(TreeNode * root)
{
    if (root==NULL)
    {
        return NULL;
    }
    else
    {
        while (root->left!=NULL)
        {
            root = root->left;    
        }
    }
    return root;
    
}

TreeNode* findMax(TreeNode * root)
{
    if (root==NULL)
    {
        return NULL;
    }
    else
    {
        while (root->right!=NULL)
        {
            root = root->right;    
        }
    }
    return root;
}

TreeNode * deleteByRe(TreeNode * root,int val)
{
    TreeNode *temp=NULL;
    if(root == NULL)
    {
        return root;
    }else if (val < root->val)
    {
        root->left = deleteByRe(root->left,val );
    }else if (val > root->val)
    {
        root->right = deleteByRe(root->right,val);
    }
    else
    {
        if(root->left && root->right)
		{
			temp = findMin(root->right);
			root->val = temp ->val;
			root->right = deleteByRe(root->right,root->val);
		}
		else 
		{
			temp = root;
			if(root->left == NULL)
				root = root->right;
			else
				root = root->left;
			free(temp);
		}
	}
	return root;                            
}

TreeNode * deleteByFind(TreeNode * root,int val)
{
    
}




int main(void){
    TreeNode * BST = NULL;
    BST = insertByWhile(BST, 30);
    BST = insertByWhile(BST, 15);
    BST = insertByWhile(BST, 41);
    BST = insertByWhile(BST, 50);
    BST = insertByWhile(BST, 33);
    BST = insertByWhile(BST, 35);
    BST = insertByWhile(BST, 34);
    BST = deleteByRe(BST,41);
    return 0;
}


