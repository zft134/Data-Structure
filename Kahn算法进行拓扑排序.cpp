// Kahn算法进行拓扑排序
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int maxn = 5e3 + 5; // 最大顶点数
const int inf = 0x7fffffff; // 无穷大值，用于初始化
int cnt; // 边计数器
struct edge // 定义边的结构体，用于链式前向星表示图中的边
{
    int v; // 边的目标顶点
    int next; // 下一条边的索引
} e[2 * maxn]; // 边数组大小
int head[maxn]; // 每个顶点的链表头，用于链式前向星存储图
int n, m; // 顶点数和边数
int ind[maxn]; // 每个顶点的入度
int topo[maxn], k = 0; // 拓扑排序后的顶点序列

// 链式前向星加边 
void add(int x, int y)
{
    cnt++; // 边数加一
    e[cnt].v = y; // 目标顶点为y
    e[cnt].next = head[x]; // 将边插入到x的链表头
    head[x] = cnt;
}

// 使用Kahn算法进行拓扑排序的函数
bool kahn()
{
    int u, v; // 当前处理的顶点和其邻接顶点
    queue<int> q; // 用于BFS的队列
    
    // 将入度为0的顶点加入队列
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    
    // 进行BFS
    while (!q.empty())
    {
        u = q.front(); // 取队首顶点
        q.pop();
        k++; // 拓扑排序序号加一
        topo[k] = u; // 将当前顶点加入拓扑排序序列
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            v = e[i].v; // 取邻接顶点
            ind[v]--; // 相邻顶点的入度减一
            if (ind[v] == 0) // 如果相邻顶点入度为0，则入队
            {
                q.push(v);
            }
        }
    }
    
    // 如果所有顶点都被访问到了，返回true，否则返回false（表示存在环）
    if (k == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin >> n >> m; // 输入顶点数和边数
    memset(head, -1, sizeof(head)); // 将每个顶点的链表头初始化为-1
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y; // 输入有向边的起点和终点
        add(x, y); // 添加有向边 x -> y 到图中
        ind[y]++; // 增加顶点 y 的入度
    }
    
    // 进行拓扑排序
    if (kahn())
    {
        // 输出拓扑排序后的顶点序列
        for (int i = 1; i <= n; i++)
        {
            cout << topo[i] << " ";
        }
    }
    else
    {
        cout << "含环" << endl; // 输出存在环的提示信息
    }
    
    return 0;
}

/*
样例输入:
5 5
1 2
2 4
3 2
3 4
4 5 

输出:
1 3 2 4 5 
*/

