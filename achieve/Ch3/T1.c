#include "../h/LinkedList.h"

void printList(Node *head)
{
    while (head!=NULL)
    {
        printf("%d",head->data);
        head = head->next;
    }
}
