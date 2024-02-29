// SPFA�㷨
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;

const int N = 150010;

// dist[i]��ʾ��i�������Դ��ľ���
int dist[N];

// ��������
int head[N];

struct Edge {
    int to;    // �ߵ�Ŀ�궥��
    int w;     // �ߵ�Ȩֵ
    int next;  // ָ����һ���ߵ�����
} e[N];

// st[i]���ж϶����Ƿ��ڶ����� 
bool st[N];

// cnt��ʾ����
int cnt = 0;

// n�ǵ�����m�Ǳ�����s��Դ��
int n, m, s;

// ��ʽǰ���Ǽӱ�
void add(int x, int y, int w) {
    // ��ʱ�Ĺ�ϵ��e[cnt].w �� x-->y �ϵ�Ȩֵ
    e[cnt].to = y; // x-->y
    e[cnt].w = w;
    // ģ������ͷ�巨
    e[cnt].next = head[x];
    head[x] = cnt;
    cnt++;
}

// SPFA�㷨ʵ��
void SPFA()
{
    memset(dist, 0x3f, sizeof dist);  // �����������ʼ��Ϊ�����
    dist[s] = 0;                      // Դ�㵽����ľ���Ϊ0
    queue<int> q;
    st[s] = 1;                        // ���Դ���Ѿ��ڶ�����
    q.push(s);                        // ��Դ�����
    while (!q.empty())				  //ֻҪ���зǿ� 
    {
        int u = q.front();            // ȡ��β����
        q.pop();
        st[u] = 0;                    // ���Ϊ���ڶ�����
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;           // �ߵ�Ŀ�궥��
            if (st[v] == 0 && dist[v] > e[i].w + dist[u])
            {
                dist[v] = dist[u] + e[i].w;
                q.push(v);              // ��Ŀ�궥�����
                st[v] = 1;              // ���Ŀ�궥���ڶ�����
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    // ���������������е��ʼ��Ϊ-1����ʾ���еĵ㶼��û�б���ʼ��
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
����������
4 5 1
1 2 1
1 4 1
2 3 2
4 3 2
1 3 6
��������
0 1 3 1 
*/

