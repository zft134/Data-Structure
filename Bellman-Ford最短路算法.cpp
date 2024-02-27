//Bellman-Ford�㷨
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
const int N=100,M=100;
//n�ǵ�����m�Ǳ��� 
int n,m;
//dis���飬��¼�ϴ�״̬��dis���� 
int dis[N];
//�洢�ߵĽṹ������ 
struct Edge{
	int a;
	int b;
	int w; 
}edges[M];
void bellmanford()
{
	//��ʼ��dist���� 
	memset(dis,0x3f,sizeof(dis));
	//��1���������ΪԴ�� 
	dis[1]=0;
	//����n-1���ɳ�
	/*
	�����б߽���һ���ɳڲ������������Դ�㵽���е㣬�����ı������Ϊ1�����·
	�����б߽��������ɳڲ������������Դ�㵽���е㣬�����ı������Ϊ2�����·
	......
	�����б߽���n-1���ɳڲ������������Դ�㵽���е㣬�����ı������Ϊn-1�����· 
	*/ 
	for(int i=1;i<n;i++)
	{
		//�������б� 
		for(int j=0;j<m;j++)
		{
			int a=edges[j].a,b=edges[j].b,w=edges[j].w;
			if(dis[a]!=0x3f3f3f3f&&dis[b]>dis[a]+w)//�ɳڲ��� 
			{
				dis[b]=dis[a]+w;
			}
		}
	}
}
int main()
{
	//������������� 
	cin>>n>>m;
	//����ߣ�ʹ�ñ߼������ͼ 
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edges[i].a=a;
		edges[i].b=b;
		edges[i].w=w; 
	}
	//����bellman-ford�㷨 
	bellmanford();
	//��ӡdis���� 
	for(int i=1;i<=n;i++)
	{
		cout<<dis[i]<<" ";
	}
	cout<<endl;
}
/*
�������
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
�������
0 -3 -1 2 4
*/
