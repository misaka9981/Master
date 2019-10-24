#include <iostream>
#define MaxSize 10
using namespace std;

typedef struct sqlist
{
    int data[MaxSize];
    int length; 
}sqlist;

void initSqlist(sqlist *&sq)
{
    sq->length=0; 
}
bool insertItem(sqlist *&sq,int value)
{
    if(sq->length>MaxSize)
    {
        return false;
    }
    sq->data[sq->length]=value;
    sq->length++;
    return true;
}

bool deleteItem(sqlist *&sq,int index)
{
    if (sq->length<0)
    {
        return false;
    }
    for (int i = index; i < sq->length-1; i++)
        sq->data[i]=sq->data[i+1];
    sq->length--;
    return true; 
}
void printSqlist(sqlist *sq)
{
    for (int i = 0; i < sq->length; i++)
    {
        cout << sq->data[i] << endl;
    }
}

int main()
{
    sqlist *sq=(sqlist *)malloc(sizeof(sqlist));
    initSqlist(sq);
    insertItem(sq,2);
    insertItem(sq,3);
    insertItem(sq,4);
    insertItem(sq,5);
    insertItem(sq,6);
    insertItem(sq,7);
    insertItem(sq,8);
    insertItem(sq,9);
    insertItem(sq,10);
    printSqlist(sq);
    deleteItem(sq,3);
    printSqlist(sq); 
    return 0;
}
