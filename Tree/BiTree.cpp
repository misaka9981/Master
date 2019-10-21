#include <iostream>
using namespace std;

typedef struct BTNode
{
    int data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

void createBT(BTNode *&T)
{
    char ch;
    for (int i = 0; i < 13; ++i)
    {
        if((ch=getchar()) == '#')
            T = NULL;
        else
            T = new BTNode;
            T->data = ch;
            createBT(T->lchild);
            createBT(T->rchild);
    }
     
   
}

int main()
{
    int A[13]={1,2,3,4,5,6,7,8,9,12,45,66,34};
    BTNode *root = (BTNode *)malloc(sizeof(BTNode));
    createBT(root);
    return 0;
}