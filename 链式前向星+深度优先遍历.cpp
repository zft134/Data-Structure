//链式前向星存图+深度优先遍历 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Edge{//边集数组 
	int to;//该点的终点 
	int w;//权值 
	int next;//终点的下一个点 
}e[10005];
int head[105];//顶点数组 
int v[105];//判断数组 
int n,m;
int cnt;//边的个数
//头插法加边 
void add(int u,int v,int w)
{//u->v加边 
	e[cnt].to=v;//终边是v 
	e[cnt].w=w;
	//模仿链表的头插法 
	e[cnt].next=head[u]; 
	head[u]=cnt;//x顶点存储次边的下标 
	cnt++;
}
//深度优先搜索 
void DFS(int u)
{
	if(v[u]==1)return;//如果搜索过直接返回 
	//没有搜索过输出这个点 
	printf("%d ",u);
	//将这个点标记为已访问 
	v[u]=1;
	//找到一个点然后对其的边进行访问 
	for(int i=head[u];i!=-1;i=e[i].next)
	{//i是边的下标，通过e[i].to得到该边对应的点，对点再进行DFS 
		int y=e[i].to;
		if(v[y]==0)DFS(y);
	}
}
int main()
{
	int x,y,w;
	cin>>n>>m;
	//将所有点初始化为-1，表示刚开始所有点都没有被初始化 
	memset(head,-1,sizeof(head));
	//初始化cnt为0，表示此时还没有边 
	cnt=0;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>w;
		//无向图加边 
		add(x,y,w);
		add(y,x,w);
	}
	//对每一个点进行深度优先搜索 
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)DFS(i);
	}
	return 0;
}
/*
测试数据：
4 5
1 2 5
1 4 3
2 3 8
2 4 12
3 4 9 
测试结果：
1 4 3 2 
*/ 
