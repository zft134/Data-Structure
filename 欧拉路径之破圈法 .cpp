// 欧拉路径之破圈法

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int n, m, cnt; // n表示节点数量，m表示边的数量，cnt用于记录边的数量
const int maxn = 1e3 + 5; // 定义最大节点数量

// 定义边结构体
struct edge {
    int v; // 目标节点
    int next; // 下一条边的索引
    bool del; // 标记当前边是否已删除
} e[maxn];

int head[maxn]; // 记录每个节点的第一条边的索引
stack<int> ansv; // 存储欧拉路径

// 添加边的函数
void add(int x, int y) {
    e[cnt].v = y; // 将目标节点存入边结构体
    e[cnt].del = false; // 初始化边的删除标记为false，表示该边未被删除
    e[cnt].next = head[x]; // 将当前节点x的第一条边指向的下一条边更新为原来指向的第一条边
    head[x] = cnt; // 更新当前节点x的第一条边为新添加的边
    cnt++; // 更新边的数量
}

// 深度优先搜索欧拉路径的函数
void DFS(int u) {
    // 遍历当前节点u的所有边
    for (int i = head[u]; i != -1; i = e[i].next) {//链式前向星遍历邻边 
        if (e[i].del == true) { // 如果当前边已被删除，则跳过该边
            head[u] = e[i].next; // 更新当前节点u的第一条边为下一条边，主要目的是跳过已经删除的边 
            continue;
        }
        e[i].del = e[i ^ 1].del = true; // 标记当前边及其对应的反向边为已删除
        DFS(e[i].v); // 递归搜索从当前边指向的节点出发的欧拉路径
    }
    ansv.push(u); // 将当前节点u压入栈中，表示欧拉路径中的一个节点
}

int main() {
    int x = 0, y = 0;
    cin >> n >> m; // 输入节点数量和边的数量
    memset(head, -1, sizeof head); // 初始化头指针数组，所有节点的第一条边索引初始化为-1，表示无边
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        add(x, y); // 添加从节点x到节点y的无向边
        add(y, x); // 添加从节点y到节点x的无向边
    }
    DFS(1); // 从节点1开始深度优先搜索欧拉路径
    while (!ansv.empty()) {
        cout << ansv.top() << " "; // 输出欧拉路径中的节点
        ansv.pop(); // 弹出栈顶节点
    }
    return 0;
}

/*
输入样例：
6 9
1 2
1 3
2 3
3 5
5 4
3 4
4 7
7 6
4 6
输出样例：
1 3 4 6 7 4 5 3 2 1 
*/

