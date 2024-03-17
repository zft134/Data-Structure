// Kahn�㷨������������
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int maxn = 5e3 + 5; // ��󶥵���
const int inf = 0x7fffffff; // �����ֵ�����ڳ�ʼ��
int cnt; // �߼�����
struct edge // ����ߵĽṹ�壬������ʽǰ���Ǳ�ʾͼ�еı�
{
    int v; // �ߵ�Ŀ�궥��
    int next; // ��һ���ߵ�����
} e[2 * maxn]; // �������С
int head[maxn]; // ÿ�����������ͷ��������ʽǰ���Ǵ洢ͼ
int n, m; // �������ͱ���
int ind[maxn]; // ÿ����������
int topo[maxn], k = 0; // ���������Ķ�������

// ��ʽǰ���Ǽӱ� 
void add(int x, int y)
{
    cnt++; // ������һ
    e[cnt].v = y; // Ŀ�궥��Ϊy
    e[cnt].next = head[x]; // ���߲��뵽x������ͷ
    head[x] = cnt;
}

// ʹ��Kahn�㷨������������ĺ���
bool kahn()
{
    int u, v; // ��ǰ����Ķ�������ڽӶ���
    queue<int> q; // ����BFS�Ķ���
    
    // �����Ϊ0�Ķ���������
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    
    // ����BFS
    while (!q.empty())
    {
        u = q.front(); // ȡ���׶���
        q.pop();
        k++; // ����������ż�һ
        topo[k] = u; // ����ǰ�������������������
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            v = e[i].v; // ȡ�ڽӶ���
            ind[v]--; // ���ڶ������ȼ�һ
            if (ind[v] == 0) // ������ڶ������Ϊ0�������
            {
                q.push(v);
            }
        }
    }
    
    // ������ж��㶼�����ʵ��ˣ�����true�����򷵻�false����ʾ���ڻ���
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
    cin >> n >> m; // ���붥�����ͱ���
    memset(head, -1, sizeof(head)); // ��ÿ�����������ͷ��ʼ��Ϊ-1
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y; // ��������ߵ������յ�
        add(x, y); // �������� x -> y ��ͼ��
        ind[y]++; // ���Ӷ��� y �����
    }
    
    // ������������
    if (kahn())
    {
        // ������������Ķ�������
        for (int i = 1; i <= n; i++)
        {
            cout << topo[i] << " ";
        }
    }
    else
    {
        cout << "����" << endl; // ������ڻ�����ʾ��Ϣ
    }
    
    return 0;
}

/*
��������:
5 5
1 2
2 4
3 2
3 4
4 5 

���:
1 3 2 4 5 
*/

