//��ʽǰ���Ǵ�ͼ+������ȱ��� 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Edge{//�߼����� 
	int to;//�õ���յ� 
	int w;//Ȩֵ 
	int next;//�յ����һ���� 
}e[10005];
int head[105];//�������� 
int v[105];//�ж����� 
int n,m;
int cnt;//�ߵĸ���
//ͷ�巨�ӱ� 
void add(int u,int v,int w)
{//u->v�ӱ� 
	e[cnt].to=v;//�ձ���v 
	e[cnt].w=w;
	//ģ�������ͷ�巨 
	e[cnt].next=head[u]; 
	head[u]=cnt;//x����洢�αߵ��±� 
	cnt++;
}
//����������� 
void DFS(int u)
{
	if(v[u]==1)return;//���������ֱ�ӷ��� 
	//û���������������� 
	printf("%d ",u);
	//���������Ϊ�ѷ��� 
	v[u]=1;
	//�ҵ�һ����Ȼ�����ı߽��з��� 
	for(int i=head[u];i!=-1;i=e[i].next)
	{//i�Ǳߵ��±꣬ͨ��e[i].to�õ��ñ߶�Ӧ�ĵ㣬�Ե��ٽ���DFS 
		int y=e[i].to;
		if(v[y]==0)DFS(y);
	}
}
int main()
{
	int x,y,w;
	cin>>n>>m;
	//�����е��ʼ��Ϊ-1����ʾ�տ�ʼ���е㶼û�б���ʼ�� 
	memset(head,-1,sizeof(head));
	//��ʼ��cntΪ0����ʾ��ʱ��û�б� 
	cnt=0;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>w;
		//����ͼ�ӱ� 
		add(x,y,w);
		add(y,x,w);
	}
	//��ÿһ������������������ 
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)DFS(i);
	}
	return 0;
}
/*
�������ݣ�
4 5
1 2 5
1 4 3
2 3 8
2 4 12
3 4 9 
���Խ����
1 4 3 2 
*/ 
