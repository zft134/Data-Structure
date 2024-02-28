// ����ͼ��Dijkstra�㷨�Ż�
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;

// first: ���룬�� dist[second]��second����ʾ�ڵ���
typedef pair<int, int> PII;

const int N = 150010;

// dist[i]��ʾ��i�������Դ��ľ���
int dist[N];

// ��������
int head[N];

struct Edge {
    int to;
    int w;
    int next;
} e[N];

// st[i]���ж��Ƿ���i�����·
bool st[N];

// С���ѣ�����dist[]����
priority_queue<PII, vector<PII>, greater<PII>> q;

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

void dijkstra() {
    // ��ʼ���������飬��Դ�㵽����ľ�������Ϊ����� 
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;

    // ��Դ��������ȶ��У�����Ϊ0
    q.push({0, s});

    // ��ʼDijkstra�㷨
    while (q.size()) {//ֻҪ���зǿ� 
        // ȡ����ǰ������С�Ľڵ㣨��ȡ���㣩 
        PII t = q.top();
        //��������� 
        q.pop();
        //u��Ÿõ�ı�ţ�d��Ÿõ㵽Դ��ľ��� 
        int u = t.second, d = t.first;

        // ����ýڵ��Ѿ������Ϊ���·����������
        if (st[u] == 1) continue;

        // ��Ǹýڵ�Ϊ�Ѿ�ȷ�����·��
        st[u] = 1;

        // �����Խڵ�uΪ�������б�
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].to;

            // ����ڵ�vδ�����Ϊ���·����ͨ���ڵ�u����ڵ�v�ľ������
            if (st[v] == 0 && e[i].w + dist[u] < dist[v]) {
                // ���´�Դ�㵽�ڵ�v�ľ���
                dist[v] = dist[u] + e[i].w;

                // ���µľ���ͽڵ�v�������ȶ���
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    // ���������������е��ʼ��Ϊ-1����ʾ���еĵ㶼��û�б���ʼ��
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
����������
4 5
1 2 1
1 4 1
2 3 2
4 3 2
1 3 6
1
��������
0 1 3 1 
*/

