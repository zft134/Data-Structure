//最小生成树之prime算法 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 5005;  // 定义最大节点数
const int inf = 0x7fffffff;  // 定义无穷大值

int cnt;  // 计数器，记录边的数量
int n, m;  // 节点数和边数
struct edge {
    int to;  // 边的目标节点
    int w;   // 边的权重
    int next;  // 链表中下一条边的索引
} e[2 * maxn];  // 存储边信息的结构体数组
int head[maxn];  // 存储每个节点链表头的数组
int dis[maxn];  // 存储节点到最小生成树的距离
bool vis[maxn];  // 记录节点是否已经加入最小生成树

// 链式前向星加点
void add(int x, int y, int w) {
    cnt++;  // 计数器加一，表示新加入一条边
    e[cnt].to = y;  // 边的目标节点为y
    e[cnt].w = w;   // 边的权重为w
    e[cnt].next = head[x];  // 将新边插入到节点x的链表头部
    head[x] = cnt;  // 更新节点x的链表头为新加入边的索引

    /*
    例如，如果原来链表结构是：
    head[x] -> a -> b -> c

    调用add(x, y, w)后，更新后的链表结构为：
    head[x] -> 新边 -> a -> b -> c
    */
}

// Prim算法
void prim() {
    // 初始化距离数组为无穷大
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[0] = 0;
    vis[0] = 1;

    int now = 0; // now是最近点的下标

    // 更新与起始节点相邻的节点的距离
    for (int i = head[now]; i; i = e[i].next) {
        int u = e[i].to;
        dis[u] = min(dis[u], e[i].w);
    }

    int mindis;

    // 依次加入最小生成树的节点
    for (int i = 1; i <= n; i++) {
        now = -1;
        mindis = inf;

        // 找距离最小的未访问节点
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0 && dis[j] < mindis) {
                now = j;
                mindis = dis[j];
            }
        }

        // 如果找不到未访问的节点，退出循环
        if (now == -1) return;

        // 输出本次加入最小生成树的节点信息
        cout << "本次把点 " << now << " 通过边权为 " << mindis << " 的边加入到生成树中" << endl;
        vis[now] = 1;

        // 更新新加入节点的相邻节点的距离
        for (int j = head[now]; j; j = e[j].next) {
            int u = e[j].to;
            dis[u] = min(dis[u], e[j].w);
        }
    }
}

int main() {
    // 输入节点数和边数
    cin >> n >> m;

    // 输入每条边的起点、终点和权重，构建图
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, w);
    }

    // 执行Prim算法，输出最小生成树的过程信息
    prim();

    return 0;
}

/*
输入样例：
9 15
0 1 3
0 5 4
1 6 6
6 5 7
1 2 8			
1 8 5
2 8 2
2 3 12
8 3 11
6 3 14
6 7 9
5 4 18
3 7 6
7 4 1
3 4 10
输出结果：
本次把点 1 通过边权为 3 的边加入到生成树中
本次把点 5 通过边权为 4 的边加入到生成树中
本次把点 8 通过边权为 5 的边加入到生成树中
本次把点 2 通过边权为 2 的边加入到生成树中
本次把点 6 通过边权为 6 的边加入到生成树中
本次把点 7 通过边权为 9 的边加入到生成树中
本次把点 4 通过边权为 1 的边加入到生成树中
本次把点 3 通过边权为 6 的边加入到生成树中 
*/  

