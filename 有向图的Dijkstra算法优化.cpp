// 有向图的Dijkstra算法优化
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;

// first: 距离，即 dist[second]；second：表示节点编号
typedef pair<int, int> PII;

const int N = 150010;

// dist[i]表示第i个点距离源点的距离
int dist[N];

// 顶点数组
int head[N];

struct Edge {
    int to;
    int w;
    int next;
} e[N];

// st[i]来判断是否是i的最短路
bool st[N];

// 小顶堆，按照dist[]来排
priority_queue<PII, vector<PII>, greater<PII>> q;

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

void dijkstra() {
    // 初始化距离数组，将源点到自身的距离设置为无穷大 
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;

    // 将源点加入优先队列，距离为0
    q.push({0, s});

    // 开始Dijkstra算法
    while (q.size()) {//只要队列非空 
        // 取出当前距离最小的节点（即取顶点） 
        PII t = q.top();
        //顶点出队列 
        q.pop();
        //u存放该点的编号，d存放该点到源点的距离 
        int u = t.second, d = t.first;

        // 如果该节点已经被标记为最短路径，则跳过
        if (st[u] == 1) continue;

        // 标记该节点为已经确定最短路径
        st[u] = 1;

        // 遍历以节点u为起点的所有边
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].to;

            // 如果节点v未被标记为最短路径且通过节点u到达节点v的距离更短
            if (st[v] == 0 && e[i].w + dist[u] < dist[v]) {
                // 更新从源点到节点v的距离
                dist[v] = dist[u] + e[i].w;

                // 将新的距离和节点v加入优先队列
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    // 将顶点数组中所有点初始化为-1，表示所有的点都还没有被初始化
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
    }
    cin >> s;
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}

/*
输入样例：
4 5
1 2 1
1 4 1
2 3 2
4 3 2
1 3 6
1
输出结果：
0 1 3 1 
*/

