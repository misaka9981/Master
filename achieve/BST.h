#ifndef _BST_H
#define _BST_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

TreeNode* createTreeNode(int val);
TreeNode * makeEmpty(TreeNode * root);
TreeNode * findByValue(TreeNode *root,int val);
TreeNode* findMax(TreeNode * root);
TreeNode * findMin(TreeNode * root);
TreeNode * insertByRe(TreeNode * root,int val);
TreeNode * insertByWhile(TreeNode * root,int val);
TreeNode * deleteByRe(TreeNode * root,int val);
TreeNode * deleteByFind(TreeNode * root,int val);
void inorderTreePrint(TreeNode *root);

#endif