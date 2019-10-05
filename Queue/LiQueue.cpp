#include <iostream>
using namespace std;

struct QNode
{
    int data;
    struct QNode *next;
};

struct LiQueue
{
    QNode *front;
    QNode *rear;
};