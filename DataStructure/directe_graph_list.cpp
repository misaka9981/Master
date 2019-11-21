#include <iostream>

#define MAX 100
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))
using namespace std;
// 邻接表中表对应的链表的顶点
typedef struct _ENode
{
    int ivex;                   // 该边所指向的顶点的位置
    struct _ENode *next_edge;   // 指向下一条弧的指针
}ENode, *PENode;

// 邻接表中表的顶点
typedef struct _VNode
{
    char data;              // 顶点信息
    ENode *first_edge;      // 指向第一条依附该顶点的弧
}VNode;

// 邻接表
typedef struct _LGraph
{
    int vexnum;             // 图的顶点的数目
    int edgnum;             // 图的边的数目
    VNode vexs[MAX];
}LGraph;

/*
 * 返回ch在matrix矩阵中的位置
 */
static int get_position(LGraph g, char ch)
{
    int i;
    for(i=0; i<g.vexnum; i++)
        if(g.vexs[i].data==ch)
            return i;
    return -1;
}



/*
 * 将node链接到list的末尾
 */
static void link_last(ENode *list, ENode *node)
{
    ENode *p = list;

    while(p->next_edge)
        p = p->next_edge;
    p->next_edge = node;
}



/*
 * 创建邻接表对应的图(用已提供的数据)
 */
LGraph* create_example_lgraph()
{
    char c1, c2;
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'B'}, 
        {'B', 'C'}, 
        {'B', 'E'}, 
        {'B', 'F'}, 
        {'C', 'E'}, 
        {'D', 'C'}, 
        {'E', 'B'}, 
        {'E', 'D'}, 
        {'F', 'G'}}; 
    int vlen = LENGTH(vexs);
    int elen = LENGTH(edges);
    int i, p1, p2;
    ENode *node1, *node2;
    LGraph* pG;



    // 初始化"顶点数"和"边数"
    pG->vexnum = vlen;
    pG->edgnum = elen;
    // 初始化"邻接表"的顶点
    for(i=0; i<pG->vexnum; i++)
    {
        pG->vexs[i].data = vexs[i];
        pG->vexs[i].first_edge = NULL;
    }

    // 初始化"邻接表"的边
    for(i=0; i<pG->edgnum; i++)
    {
        // 读取边的起始顶点和结束顶点
        c1 = edges[i][0];
        c2 = edges[i][1];

        p1 = get_position(*pG, c1);
        p2 = get_position(*pG, c2);
        // 初始化node1
        node1 = (ENode*)malloc(sizeof(ENode));
        node1->ivex = p2;
        // 将node1链接到"p1所在链表的末尾"
        if(pG->vexs[p1].first_edge == NULL)
          pG->vexs[p1].first_edge = node1;
        else
            link_last(pG->vexs[p1].first_edge, node1);
    }

    return pG;
}

/*
 * 打印邻接表图
 */
void print_lgraph(LGraph G)
{
    int i,j;
    ENode *node;

    for (i = 0; i < G.vexnum; i++)
    {
        cout<<i<<G.vexs[i].data<<endl;
        node = G.vexs[i].first_edge;
        while (node != NULL)
        {
            cout<<node->ivex<<G.vexs[node->ivex].data<<endl;
            node = node->next_edge;
        }
    }
}

void main()
{
    LGraph* pG;

    // 自定义"图"(自己输入数据)
    //pG = create_lgraph();
    // 采用已有的"图"
    pG = create_example_lgraph();

    // 打印图
    print_lgraph(*pG);
}