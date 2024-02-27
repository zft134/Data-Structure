#include<iostream>
#include<cstdio>
#define INF 65535
using namespace std;
int g[105][105];  // �ڽӾ����ʾͼ
int nv, ne, v;    // ��������������Դ��
int dist[105], path[105];  // �洢���·�����Ⱥ�·��
int ch[105];  // ��¼�ڵ��Ƿ��Ѿ��������·��
int a[105];//�����洢�������˳��� 
// Dijkstra�㷨ʵ�֣�����Դ��v��������������·��
void dijkstra()
{
    for(int i = 0; i < ne; i++)
    {
        dist[i] = g[v][i];  // ��ʼ������ΪԴ��v�������ֱ�Ӿ���
        if(g[v][i] != INF)//����Դ��ľ��벻ΪINF˵���õ���Դ��ֱ������ 
        {
            path[i] = v;  // ����ֱ��·������¼·���е�ǰ���ڵ�ΪԴ��v
        }
    }
    int minn;  // ��С��distֵ
    int k;     // ��Сdistֵ��Ӧ�Ľڵ�
    for(int i = 1; i < nv; i++)
    {
        minn = INF;
        for(int j = 0; j < nv; j++)  // ����С��dist
        {
            if(ch[j] == 0 && dist[j] < minn)//��������û�б��궨��distֵ����֪�Ļ�ҪС 
            { 
                minn = dist[j];
                k = j;
            }
        }
        ch[k] = 1;  // ��������С�Ľڵ�������·��
        for(int j = 0; j < nv; j++)
        {//���������k��Χֱ�������ĵ�ľ�����Сֵ 
            if(ch[j] == 0 && dist[k] + g[k][j] < dist[j])
            {
                dist[j] = dist[k] + g[k][j];  // ���¾���ֵ
                path[j] = k;  // ����·���е�ǰ���ڵ�
            }
        }
    }
}

int main()
{
    int x, y, w;
    cin >> nv >> ne;

    // ��ʼ���ڽӾ���
    for(int i = 0; i < nv; i++)
    {
        for(int j = 0; j < nv; j++)
        {
            if(i == j)
                g[i][j] = g[j][i] = 0;  // �Խ����ϵ�Ԫ��Ϊ0
            else
                g[i][j] = g[j][i] = INF;  // ����Ԫ�س�ʼ��ΪINF�������
        }
    }

    // �����ڽӾ��� 
    for(int i = 0; i < ne; i++)
    {
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = w;  // �бߵĵط�����Ϊ��Ӧ��Ȩֵ
    }

    cin >> v;  // �������

    // ��ʼ��dist��path��ch����
    for(int i = 0; i < nv; i++)
    {
        dist[i] = INF;  // ��ʼ������Ϊ�����
        ch[i] = 0;  // �ڵ�δ�������·��
    }
    dist[v] = 0;  // Դ�㵽����ľ���Ϊ0
    ch[v] = 1;  // ��Դ��������·��
    path[v] = v;  // Դ���ǰ���ڵ�Ϊ����

    dijkstra();  // ����Dijkstra�㷨�������·��

    // ������·�����Ⱥ�·��
    for(int i = 0; i < nv; i++)
	{
    	cout << "Դ��" << v << "��" << i << "�����·�������ǣ�" << dist[i] << "----";
    	// ���򱣴����·��
    	int j = i;
    	int k=0;
		a[k++]=i;//���浱ǰ�ڵ� 
    	while(path[j] != j)//path[j]=j˵���Ѿ���Դ���� 
    	{
			a[k++]=path[j];// ����·���е�ǰ���ڵ�
        	j = path[j];  // �ƶ���ǰ���ڵ㣬׼�����ǰ���ڵ��ǰ���ڵ�
    	}
    	//����������򱣴�����·�������յõ���������·�� 
    	for(int m=k-1;m>=0;m--)
    	{
    		cout<<a[m]<<"->"; 
		}
    	cout << endl;  // ���һ��·������
	}


    return 0;
}
/*
9 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
0
*/
