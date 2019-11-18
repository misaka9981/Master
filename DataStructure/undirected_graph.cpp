#include <iostream>
using namespace std;
#define MAXVEX 100//顶点数
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))

typedef struct
{
    char vexs[MAXVEX];
    int vexnum;
    int edgenum;
    int  edgeArr[MAXVEX][MAXVEX];
}ArrayGraph;

ArrayGraph* create_graph()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'}, 
        {'A', 'D'}, 
        {'A', 'F'}, 
        {'B', 'C'}, 
        {'C', 'D'}, 
        {'E', 'G'}, 
        {'F', 'G'}}; 
    int vlen=LENGTH(vexs);
    int elen=LENGTH(edges);
    int i,p1,p2;
    ArrayGraph *ph;
    ph->vexnum=vlen;
    ph->edgenum=elen;
    for (int i = 0; i < ph->vexnum; i++)
    {
        ph->vexs[i]=vexs[i];
    }
    for (int i = 0; i < ph->edgenum; i++)
    {
        p1 = get_position(*ph, edges[i][0]);
        p2 = get_position(*ph, edges[i][1]);

        ph->edgeArr[p1][p2] = 1;
        ph->edgeArr[p2][p1] = 1;
    }
}

static int get_position(ArrayGraph g,char ch)
{

}

void print_graph(ArrayGraph G)
{

}

int main()
{
    ArrayGraph* pG;


    pG = create_graph();
    // 打印矩阵队列
    print_graph(*pG);
    return 0;
}