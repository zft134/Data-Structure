// ��������֮DFS
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

const int maxn = 5e3 + 5; // ��󶥵���
const int inf = 0x7fffffff; // �����ֵ�����ڳ�ʼ��
int cnt; // �߼�����
struct edge // ����ߵĽṹ�壬���ڴ洢ͼ�ı���Ϣ
{
    int v; // �ߵ�Ŀ�궥��
    int next; // ��һ���ߵ�����
} e[2 * maxn]; // �������С
int head[maxn]; // ÿ�����������ͷ�����ڴ洢ͼ�Ľṹ
int vis[maxn]; // ��¼����ķ���״̬��0��ʾδ���ʣ�1��ʾ���ڷ��ʣ�2��ʾ����ɷ���
int n, m; // �������ͱ���
stack<int> s; // ���ڴ洢������������ջ
bool flag = false; // ����Ƿ���ڻ�

// ��ӱߵ�ͼ�еĺ���
void add(int x, int y)
{//x-->y
    cnt++; // ������һ
    e[cnt].v = y; // Ŀ�궥��Ϊy
    e[cnt].next = head[x]; // ���߲��뵽x������ͷ
    head[x] = cnt;
}

// �����������������������ĺ���
void dfs(int u)
{
    int v;
    vis[u] = 1; // ��ǵ�ǰ����Ϊ���ڷ���״̬
    for(int i = head[u]; i != -1; i = e[i].next)//��ʽǰ���Ǳ����ڱ� 
    {
        v = e[i].v; // ȡ�ڽӶ���
        if(vis[v] == 1) // ����ڽӶ����Ѿ������ʹ�����˵�����ڻ�
        {
            flag = true; // ��Ǵ��ڻ�
            return;
        }
        else if(vis[v] == 0) // ����ڽӶ���δ�����ʹ�������еݹ����
        {
            dfs(v);
            if(flag) return; // ����ڵݹ�����з��ִ��ڻ�����ֱ�ӽ����ݹ�
        }
    }
    vis[u] = 2; // ��ǵ�ǰ����Ϊ����ɷ���״̬
    s.push(u); // ����ǰ������ջ
}

int main()
{
    cin >> n >> m; // ���붥�����ͱ���
    memset(head, -1, sizeof(head)); // ��ÿ�����������ͷ��ʼ��Ϊ-1
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y; // ��������ߵ������յ�
        add(x, y); // �������� x -> y ��ͼ��
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) // �������δ�����ʹ�������������������
        {
            dfs(i);
        }
    }
    if(flag == false) // ��������ڻ������������������
    {
        while(!s.empty())
        {
            cout << s.top() << " "; // ���ջ��Ԫ�أ�������������
            s.pop(); // ����ջ��Ԫ��
        }
    }
    else // ������ڻ����������ʾ��Ϣ
    {
        cout << "����" << endl;
    }
    return 0;
}

/*
����������
5 5
1 2
2 4
3 2
3 4
4 5
��������
3 1 2 4 5 
*/

