#include "../LinkedList.c"
#include <stdio.h>

void PrintLots(Node *L,Node *P)
{
    Node *tmpL = L;
    Node *tmpP = P;
    int index = 1;
    int ele;

    while (tmpL!=NULL && tmpP!=NULL)
    {
        if (tmpP->data==index++)
        {
            printf("%d",tmpL->data);
            tmpP = tmpP->next;
        }
        tmpL = tmpL->next;
    }
    
}

int main(void)
{
    Node *P = CreateNode(1);
    LinkedListInsertR(P,3);
    LinkedListInsertR(P,4);
    LinkedListInsertR(P,5);
    Node *L = CreateNode(4);
    LinkedListInsertR(L,3);
    LinkedListInsertR(L,4);
    LinkedListInsertR(L,6);
    LinkedListInsertR(L,3);
    LinkedListInsertR(L,4);
    LinkedListInsertR(L,6);
    PrintLots(L,P);
    return 0;
}