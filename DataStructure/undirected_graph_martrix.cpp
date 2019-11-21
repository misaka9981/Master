#include <iostream>
using namespace std;
#define MAX 20
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))

typedef struct edgeNode
{
    int vex;
    struct edgeNode *next_edge;
}edgeNode;

typedef struct vexNode
{
    char data;
    edgeNode *first_edge;
}vexNode;

typedef struct LGraph
{
    int vexnum;
    int edgenum;
    vexNode vex[MAX];
}LGraph;

static int get_position(LGraph g, char ch)
{
    int i;
    for(i=0; i<g.vexnum; i++)
        if(g.vex[i].data==ch)
            return i;
    return -1;
}

static void link_last(edgeNode *list, edgeNode *node)
{
    edgeNode *p = list;

    while(p->next_edge)
        p = p->next_edge;
    p->next_edge = node;
}

LGraph* create_example_lgraph()
{
    char c1, c2;
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'}, 
        {'A', 'D'}, 
        {'A', 'F'}, 
        {'B', 'C'}, 
        {'C', 'D'}, 
        {'E', 'G'}, 
        {'F', 'G'}}; 
    int vlen = LENGTH(vexs);
    int elen = LENGTH(edges);
    int i, p1, p2;
    edgeNode *node1, *node2;
    LGraph* pg = (LGraph*)malloc(sizeof(LGraph));

    pg->vexnum = vlen;
    pg->edgenum = elen;//初始化顶点数和边数
    for ( i = 0; i < pg->vexnum; i++)
    {
        pg->vex[i].data = vexs[i];
        pg->vex[i].first_edge=NULL;
    }//初始化邻接表的顶点

    //初始化邻接表的边
    for (i = 0; i < pg->vexnum; i++)
    {
        c1=edges[i][0];
        c2=edges[i][1];
        
        p1 = get_position(*pg,c1);
        p2 = get_position(*pg,c2);

        //初始化node1
        node1=(edgeNode*)malloc(sizeof(edgeNode));
        node1->vex = p2;
        if(pg->vex[p1].first_edge==NULL)
            pg->vex[p1].first_edge=node1;
        else
            link_last(pg->vex[p1].first_edge,node1);
        // 将node1链接到"p1所在链表的末尾"
        if(pg->vex[p1].first_edge == NULL)
          pg->vex[p1].first_edge = node1;
        else
            link_last(pg->vex[p1].first_edge, node1);
        // 初始化node2
        node2 = (edgeNode*)malloc(sizeof(edgeNode));
        node2->vex = p1;
        // 将node2链接到"p2所在链表的末尾"
        if(pg->vex[p2].first_edge == NULL)
          pg->vex[p2].first_edge = node2;
        else
            link_last(pg->vex[p2].first_edge, node2);
    }
    return pg;
}


void print_lgraph(LGraph G)
{
    int i,j,k;
    edgeNode *node;

    printf("List Graph:\n");
    for (i = 0; i < G.vexnum; i++)
    {
        printf("%d(%c): ", i, G.vex[i].data);
        node = G.vex[i].first_edge;
        while (node != NULL)
        {
            cout<<node->vex<<G.vex[node->vex].data<<endl;
            node = node->next_edge;
        }
    }
}

int main()
{
    LGraph* pG;
    pG = create_example_lgraph();
    // 打印图
    print_lgraph(*pG);
    return 0;
}
