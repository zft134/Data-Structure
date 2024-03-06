//��С������֮prime�㷨 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 5005;  // �������ڵ���
const int inf = 0x7fffffff;  // ���������ֵ

int cnt;  // ����������¼�ߵ�����
int n, m;  // �ڵ����ͱ���
struct edge {
    int to;  // �ߵ�Ŀ��ڵ�
    int w;   // �ߵ�Ȩ��
    int next;  // ��������һ���ߵ�����
} e[2 * maxn];  // �洢����Ϣ�Ľṹ������
int head[maxn];  // �洢ÿ���ڵ�����ͷ������
int dis[maxn];  // �洢�ڵ㵽��С�������ľ���
bool vis[maxn];  // ��¼�ڵ��Ƿ��Ѿ�������С������

// ��ʽǰ���Ǽӵ�
void add(int x, int y, int w) {
    cnt++;  // ��������һ����ʾ�¼���һ����
    e[cnt].to = y;  // �ߵ�Ŀ��ڵ�Ϊy
    e[cnt].w = w;   // �ߵ�Ȩ��Ϊw
    e[cnt].next = head[x];  // ���±߲��뵽�ڵ�x������ͷ��
    head[x] = cnt;  // ���½ڵ�x������ͷΪ�¼���ߵ�����

    /*
    ���磬���ԭ������ṹ�ǣ�
    head[x] -> a -> b -> c

    ����add(x, y, w)�󣬸��º������ṹΪ��
    head[x] -> �±� -> a -> b -> c
    */
}

// Prim�㷨
void prim() {
    // ��ʼ����������Ϊ�����
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[0] = 0;
    vis[0] = 1;

    int now = 0; // now���������±�

    // ��������ʼ�ڵ����ڵĽڵ�ľ���
    for (int i = head[now]; i; i = e[i].next) {
        int u = e[i].to;
        dis[u] = min(dis[u], e[i].w);
    }

    int mindis;

    // ���μ�����С�������Ľڵ�
    for (int i = 1; i <= n; i++) {
        now = -1;
        mindis = inf;

        // �Ҿ�����С��δ���ʽڵ�
        for (int j = 1; j <= n; j++) {
            if (vis[j] == 0 && dis[j] < mindis) {
                now = j;
                mindis = dis[j];
            }
        }

        // ����Ҳ���δ���ʵĽڵ㣬�˳�ѭ��
        if (now == -1) return;

        // ������μ�����С�������Ľڵ���Ϣ
        cout << "���ΰѵ� " << now << " ͨ����ȨΪ " << mindis << " �ı߼��뵽��������" << endl;
        vis[now] = 1;

        // �����¼���ڵ�����ڽڵ�ľ���
        for (int j = head[now]; j; j = e[j].next) {
            int u = e[j].to;
            dis[u] = min(dis[u], e[j].w);
        }
    }
}

int main() {
    // ����ڵ����ͱ���
    cin >> n >> m;

    // ����ÿ���ߵ���㡢�յ��Ȩ�أ�����ͼ
    for (int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, w);
    }

    // ִ��Prim�㷨�������С�������Ĺ�����Ϣ
    prim();

    return 0;
}

/*
����������
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
��������
���ΰѵ� 1 ͨ����ȨΪ 3 �ı߼��뵽��������
���ΰѵ� 5 ͨ����ȨΪ 4 �ı߼��뵽��������
���ΰѵ� 8 ͨ����ȨΪ 5 �ı߼��뵽��������
���ΰѵ� 2 ͨ����ȨΪ 2 �ı߼��뵽��������
���ΰѵ� 6 ͨ����ȨΪ 6 �ı߼��뵽��������
���ΰѵ� 7 ͨ����ȨΪ 9 �ı߼��뵽��������
���ΰѵ� 4 ͨ����ȨΪ 1 �ı߼��뵽��������
���ΰѵ� 3 ͨ����ȨΪ 6 �ı߼��뵽�������� 
*/  

