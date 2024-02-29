// SPFA算法
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;

const int N = 150010;

// dist[i]表示第i个点距离源点的距离
int dist[N];

// 顶点数组
int head[N];

struct Edge {
    int to;    // 边的目标顶点
    int w;     // 边的权值
    int next;  // 指向下一条边的索引
} e[N];

// st[i]来判断顶点是否在队列中 
bool st[N];

// cnt表示边数
int cnt = 0;

// n是点数，m是边数，s是源点
int n, m, s;

// 链式前向星加边
void add(int x, int y, int w) {
    // 此时的关系：e[cnt].w 存 x-->y 上的权值
    e[cnt].to = y; // x-->y
    e[cnt].w = w;
    // 模拟链表头插法
    e[cnt].next = head[x];
    head[x] = cnt;
    cnt++;
}

// SPFA算法实现
void SPFA()
{
    memset(dist, 0x3f, sizeof dist);  // 将距离数组初始化为无穷大
    dist[s] = 0;                      // 源点到自身的距离为0
    queue<int> q;
    st[s] = 1;                        // 标记源点已经在队列中
    q.push(s);                        // 将源点入队
    while (!q.empty())				  //只要队列非空 
    {
        int u = q.front();            // 取队尾顶点
        q.pop();
        st[u] = 0;                    // 标记为不在队列中
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;           // 边的目标顶点
            if (st[v] == 0 && dist[v] > e[i].w + dist[u])
            {
                dist[v] = dist[u] + e[i].w;
                q.push(v);              // 将目标顶点入队
                st[v] = 1;              // 标记目标顶点在队列中
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    // 将顶点数组中所有点初始化为-1，表示所有的点都还没有被初始化
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
    }
    SPFA();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}

/*
输入样例：
4 5 1
1 2 1
1 4 1
2 3 2
4 3 2
1 3 6
输出结果：
0 1 3 1 
*/

