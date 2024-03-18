// ŷ��·��֮��Ȧ��

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int n, m, cnt; // n��ʾ�ڵ�������m��ʾ�ߵ�������cnt���ڼ�¼�ߵ�����
const int maxn = 1e3 + 5; // �������ڵ�����

// ����߽ṹ��
struct edge {
    int v; // Ŀ��ڵ�
    int next; // ��һ���ߵ�����
    bool del; // ��ǵ�ǰ���Ƿ���ɾ��
} e[maxn];

int head[maxn]; // ��¼ÿ���ڵ�ĵ�һ���ߵ�����
stack<int> ansv; // �洢ŷ��·��

// ��ӱߵĺ���
void add(int x, int y) {
    e[cnt].v = y; // ��Ŀ��ڵ����߽ṹ��
    e[cnt].del = false; // ��ʼ���ߵ�ɾ�����Ϊfalse����ʾ�ñ�δ��ɾ��
    e[cnt].next = head[x]; // ����ǰ�ڵ�x�ĵ�һ����ָ�����һ���߸���Ϊԭ��ָ��ĵ�һ����
    head[x] = cnt; // ���µ�ǰ�ڵ�x�ĵ�һ����Ϊ����ӵı�
    cnt++; // ���±ߵ�����
}

// �����������ŷ��·���ĺ���
void DFS(int u) {
    // ������ǰ�ڵ�u�����б�
    for (int i = head[u]; i != -1; i = e[i].next) {//��ʽǰ���Ǳ����ڱ� 
        if (e[i].del == true) { // �����ǰ���ѱ�ɾ�����������ñ�
            head[u] = e[i].next; // ���µ�ǰ�ڵ�u�ĵ�һ����Ϊ��һ���ߣ���ҪĿ���������Ѿ�ɾ���ı� 
            continue;
        }
        e[i].del = e[i ^ 1].del = true; // ��ǵ�ǰ�߼����Ӧ�ķ����Ϊ��ɾ��
        DFS(e[i].v); // �ݹ������ӵ�ǰ��ָ��Ľڵ������ŷ��·��
    }
    ansv.push(u); // ����ǰ�ڵ�uѹ��ջ�У���ʾŷ��·���е�һ���ڵ�
}

int main() {
    int x = 0, y = 0;
    cin >> n >> m; // ����ڵ������ͱߵ�����
    memset(head, -1, sizeof head); // ��ʼ��ͷָ�����飬���нڵ�ĵ�һ����������ʼ��Ϊ-1����ʾ�ޱ�
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        add(x, y); // ��Ӵӽڵ�x���ڵ�y�������
        add(y, x); // ��Ӵӽڵ�y���ڵ�x�������
    }
    DFS(1); // �ӽڵ�1��ʼ�����������ŷ��·��
    while (!ansv.empty()) {
        cout << ansv.top() << " "; // ���ŷ��·���еĽڵ�
        ansv.pop(); // ����ջ���ڵ�
    }
    return 0;
}

/*
����������
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
���������
1 3 4 6 7 4 5 3 2 1 
*/

