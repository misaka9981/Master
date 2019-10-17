#include <iostream>
#include "../utility/LinearTable/SqList.h"
#include "../utility/LinearTable/LinkedList.h"
#include "../utility/LinearTable/DLinkedLIst.h"
using namespace std;

/**
 * 数组A[],元素存储再下标0~m+n-1范围内,前m个元素递增有序，后n个也是
 * 设计算法，使整个顺序表有序
 * 
**/
void insertElem(SqList &a,int m,int n)
{
    int temp;
    int i,j;
    for (i = m; i < m+n; i++)
    {
        temp=a.data[i];
        for (j = i - 1; j>=0&&temp<a.data[j]; j--)
            a.data[j+1] = a.data[j];
        a.data[j+1] = temp;
    }   
}

void test01(){
    SqList A;
    int a[6] = {3,4,5,2,6,7};
    createSqList(A, a, 6);
    printSqList((char *)"before-A", A);
    insertElem(A, 3, 3);
    printSqList((char*) "after-A", A);
}

/**
 *递增有序单链表A,B中元素个数分别为m,n均有头节点，设计算法求出A,B差集
 *存在链表A中
**/
void difference(LNode *A,LNode *B)
{
    LNode *p = A->next,*q = B->next;
    LNode *pre = A;
    while (p!=NULL && q!=NULL)
    {
        if (p->data > q->data)
        {
            q = q->next;
        }
        else if (p->data < q->data)
        {
            pre = p;
            p = p->next;
        }
        else
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }     
    }     
}

void test02(){
    LNode *A, *B;
    int a[5] = {4, 7, 8, 11, 23};
    int b[5] = {1, 2, 4, 11, 20};
    createListR(A, a, 5);
    createListR(B, b, 5);
    printLinkedListH((char*) "A", A);
    printLinkedListH((char*) "B", B);
    difference(A, B);
    printLinkedListH((char*) "A-B", A);
}

/**
 * 逆置顺序表所有元素
 * 
 * */
void reverse(SqList &A)
{
    int i,j,tmp;
    for (i = 0,j = A.length-1;i<j;i++,j--)
    {
        tmp = A.data[i];
        A.data[i] = A.data[j];
        A.data[j] = tmp;
    }   
}

void test03(){
    SqList A;
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    createSqList(A, a, 8);
    printSqList((char*) "before_A", A);
    reverse(A);
    //reverse02(A);
    printSqList((char*) "after_A", A);
}

/**
 * 顺序表删除下标i~j,包括i,j
 * review
 * */
void delRange(SqList &A,int i,int j)
{
    int m;
    int len = j-i+1;
    for ( m = j + 1; m < A.length; m++)
    {
        A.data[m-len] = A.data[m]; 
    }
    A.length -= len;
    
}

void test04(){
    SqList A;
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    createSqList(A, a, 8);
    printSqList((char*) "before_A", A);

    delRange(A, 2, 5);
    printSqList((char*) "after_A", A);
}

/**
 * 将顺序表重所有小于表头的整数放在前半部分
 * 大于表头的放在后半部分
 * */
void move(SqList &A)
{
    int tmp;
    int i=0,j = A.length-1;
    tmp = A.data[i];
    while (i<j)
    {
        while(i<j){
        // 从右向左 找到第一个比表头元素小的数组下标
        while(i<j && A.data[j]>tmp) j--;
        if(i<j){
            A.data[i] = A.data[j];
            i++;
        }
        // 从左向右 找到第一个比表头元素大的数组下标
        while(i<j && A.data[i]<tmp) i++;
        if(i<j){
            A.data[j] = A.data[i];
            j--;
        }
    }
    A.data[i]=tmp;
    }  
}

void test05(){
    SqList A;
    int a[9] = {5, -1, 8, 6, 1, 3, 4, 8, 2};
    createSqList(A, a, 9);
    printSqList((char*) "before_A", A);

    move(A);
    printSqList((char*) "after_A", A);
}

/**
 * 递增非空单链表，删除值重复的结点
 **/
void unique(LNode *&L)
{
    LNode *preNode,*nextNode,*tmp;
    preNode = L->next;//指向头节点的next
    nextNode = preNode->next;//指向头节点的下一个节点 
    while (nextNode != NULL)
    {
        if(preNode->data == nextNode->data)
        {
            tmp = nextNode;
            preNode->next = nextNode->next;
            nextNode = nextNode->next;
        }
        else
        {
            preNode = nextNode;
            nextNode = nextNode->next;
        }
        
    }
    
}

void test06(){
    LNode *A, *B;
    int a[14] = {1, 1, 2, 3, 3, 3, 4, 4, 7, 7, 7, 9, 9, 9};
    createListR(A, a, 14);
    printLinkedListH((char*) "A", A);
    unique(A);
    printLinkedListH((char*) "Unique A", A);
}

/**
 * 删除带头结点的单链表中的一个最小值节点
 * */

void deleteMin(LNode *&L)
{
    LNode *preNode = L->next;
    LNode *minNode = L->next;
    LNode *tmpNode;
    int tmpNum = L->next->data;
    while (preNode->next != NULL)
    {
        if (tmpNum > preNode->next->data)
        {
            tmpNum = preNode->next->data;
            preNode = preNode->next;
        }
        else
        {
            preNode = preNode->next;
        }
        
    }
    preNode = L->next;
    while (preNode != NULL)
    {
        if(preNode->data == tmpNum)
        {
            tmpNode->next = preNode->next;
            preNode->next = preNode->next->next;
            //free(tmpNode);
        } 
        else
            tmpNode = preNode;
            preNode = preNode->next;
            //tmpNode = preNode;
        
    }    
}

void test07(){
    LNode *A, *B;
    int a[8] = { 4, 7, 9, 3, 20, 21, 4, 5};
    createListR(A, a, 8);
    printLinkedListH((char*) "A", A);
    deleteMin(A);
    printLinkedListH((char*) "delMin_A", A);
}

/**
 * 带头结点的单链表逆置
 * */
void reverseLNode(LNode *&L)
{
    LNode *p,*q,*r;
    p = L;
    q = L->next;
    L->next = NULL;
    while(q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    L = p; 
}

void test08(){
    LNode *A;
    int a[8] = { 4, 7, 9, 3, 20, 21, 4, 5};
    createListR(A, a, 8);
    printLinkedListH((char*) "A", A);
    reverseLNode(A);
    printLinkedListH((char*) "reverseLNode_A", A);
}

/**
 * 将带头结点的单链表分解成两个
 * A只含有原链表data域为奇数的结点
 * B只含有data域为偶数的节点，且保持相对有序
 * */
void split(LNode *&A,LNode *&B)
{
    LNode *preNode = A;
    LNode *pNode = preNode->next;
    LNode *r,*tmp;
    B = (LNode *)malloc(sizeof(LNode));
    B->next = NULL;
    r=B;
    while (pNode != NULL)
    {
        if (pNode->data%2 != 0)
        {
            preNode = pNode;
            pNode = pNode->next;
        }
        else
        {
            preNode->next = pNode->next;
            tmp = pNode;
            pNode = pNode->next;
            r->next = tmp;
            tmp->next = NULL;
            r = tmp;
        }     
    }
    
}

void test09(){
    LNode *A, *B;
    int a[8] = { 4, 7, 9, 3, 20, 21, 4, 5};
    createListR(A, a, 8);
    printLinkedListH((char*) "A", A);
    split(A, B);
    printLinkedListH((char*) "split_A", A);
    printLinkedListH((char*) "split_B", B);
}
/**
 * N<=9,int i,A[]求最小值，不能破坏数组
 * 是否能用j
 * */
int findMin(int A[],int N)
{
    int i = A[0];
    for (int j = 0; j < N; j++)
    {
        if(i>A[j])
        {
            i = A[j];
        }
    }
    return i;
}

/**
 * 逆序打印单链表中的数据，指针L指向单链表的开始节点
 * */
void reprint(LNode *L)
{
    if(L==NULL)
    {
        return;
    }
    reprint(L->next);
    cout << L->data << endl;
}

void test11(){
    LNode *A;
    int a[8] = { 4, 7, 9, 3, 20, 21, 4, 5};
    createListR(A, a, 8);
    printLinkedListH((char*) "A", A);
    reprint(A);
}

/**
 * 以不多于3n/2的比较平均次数，在一个有n个整数的顺序表A中找出最大值
 * 和最小值
 * */
void findMinMax(int A[], int n, int &max, int &min)
{

}

/**
 * 设A＝（a1，…，am）和B＝（b1，…，bn）均为顺序表，A’和B’分别为A和B中除去最大共同
 *    前缀后的子表（例如，A＝（x，y，y，z，x，z），B＝（x，y，y，z，y，x，x，z），
 *    则两者中最大的共同前缀为（x，y，y，z），在两表中除去最大共同前缀后的子表分别为A’＝（x，z）
 *    和B’＝（y，x，x，z））。若A’＝B’＝空表，则A＝B；若A’＝空表，而B’≠空表，或者两者均不为空，
 *    且A’的首元小于B’的首元，则A < B，否则A > B。试写一个比较A、B大小的算法。
 *    （请注意：在算法中，不要破坏原表A和B，并且也不一定先求得A’和B’才进行比较）
 */

char* compare01(char A[], int m, char B[], int n)
{
    
}
int main()
{
    test01();
    return 0;
}
