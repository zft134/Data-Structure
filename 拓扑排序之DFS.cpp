// 拓扑排序之DFS
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

const int maxn = 5e3 + 5; // 最大顶点数
const int inf = 0x7fffffff; // 无穷大值，用于初始化
int cnt; // 边计数器
struct edge // 定义边的结构体，用于存储图的边信息
{
    int v; // 边的目标顶点
    int next; // 下一条边的索引
} e[2 * maxn]; // 边数组大小
int head[maxn]; // 每个顶点的链表头，用于存储图的结构
int vis[maxn]; // 记录顶点的访问状态，0表示未访问，1表示正在访问，2表示已完成访问
int n, m; // 顶点数和边数
stack<int> s; // 用于存储拓扑排序结果的栈
bool flag = false; // 标记是否存在环

// 添加边到图中的函数
void add(int x, int y)
{//x-->y
    cnt++; // 边数加一
    e[cnt].v = y; // 目标顶点为y
    e[cnt].next = head[x]; // 将边插入到x的链表头
    head[x] = cnt;
}

// 深度优先搜索进行拓扑排序的函数
void dfs(int u)
{
    int v;
    vis[u] = 1; // 标记当前顶点为正在访问状态
    for(int i = head[u]; i != -1; i = e[i].next)//链式前向星遍历邻边 
    {
        v = e[i].v; // 取邻接顶点
        if(vis[v] == 1) // 如果邻接顶点已经被访问过，则说明存在环
        {
            flag = true; // 标记存在环
            return;
        }
        else if(vis[v] == 0) // 如果邻接顶点未被访问过，则进行递归访问
        {
            dfs(v);
            if(flag) return; // 如果在递归过程中发现存在环，则直接结束递归
        }
    }
    vis[u] = 2; // 标记当前顶点为已完成访问状态
    s.push(u); // 将当前顶点入栈
}

int main()
{
    cin >> n >> m; // 输入顶点数和边数
    memset(head, -1, sizeof(head)); // 将每个顶点的链表头初始化为-1
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y; // 输入有向边的起点和终点
        add(x, y); // 添加有向边 x -> y 到图中
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) // 如果顶点未被访问过，则进行深度优先搜索
        {
            dfs(i);
        }
    }
    if(flag == false) // 如果不存在环，则输出拓扑排序结果
    {
        while(!s.empty())
        {
            cout << s.top() << " "; // 输出栈顶元素（拓扑排序结果）
            s.pop(); // 弹出栈顶元素
        }
    }
    else // 如果存在环，则输出提示信息
    {
        cout << "含环" << endl;
    }
    return 0;
}

/*
输入样例：
5 5
1 2
2 4
3 2
3 4
4 5
输出结果：
3 1 2 4 5 
*/

