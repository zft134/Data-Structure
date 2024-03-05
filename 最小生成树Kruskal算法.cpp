//最小生成树Kruskal算法 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 65535 //定义无穷大 
/*找最小生成树---->选出n-1条边：
 
1.选出n-1条权值尽量小的边： 每次都选新的最小的边E---基于贪心 
2. 其中不能出现环 ：   采用并查集，判断一下 E的两个端点是不是属于同一个连通集合：(1)yes,说明E不能选  (2)no, 说明要选E 

Kruskal的思路 ---贪心（贪婪）思想 ：趋利避害   目光短浅 

时间复杂度：在并查集采用路径压缩的基础上 O(eloge) ----适合 稀疏图 
*/ 
using namespace std;
int g[105][105];//邻接矩阵存图 
int nv,ne;//nv个点，ne条边 
struct  Edge{//x-->y 
	int x;
	int y;
	int w;
}e[5005];//边集数组 
bool cmp(struct Edge a,struct Edge b){//结构体升序排序 
	return a.w < b . w;
}
//选择排序 
//void sorte(int l,int r)
//{
//	//选择
//	int minn;
//	Edge tmp;
//	for(int i=l;i<r;i++)
//	{
//		minn=i;
//		for(int j=i+1;j<r;j++)
//		{
//			if(e[minn].w >e[j].w )
//			{
//				minn=j;
//			}
//			
//		 } 
//		tmp=e[i];
//		e[i]=e[minn];
//		e[minn]=tmp;
//	 } 
//	 //输出排序之后的结果；
//	 printf("按权值升序排列：\n");
//	 for(int i=0;i<r;i++)
//	 {
//	 	printf("(%d %d) %d\n",e[i].x,e[i].y,e[i].w);
//	  }  
//}
int find(int f[],int z)//查找父亲函数 
{
	while(z!=f[z])//如果z不等于z的父亲 
	{
		z=f[z];//就把父亲的值赋给z 
	}
	return z;
}
void Kruskal()
{
	int f[105];//定义父亲数组 
	for(int i=0;i<nv;i++)
	{
		f[i]=i;//刚开始定义自己的父亲是自己 
	}
	cout<<"以下是最小生成树的边："<<endl;
	for(int i=0;i<ne;i++)
	{
		//分别查找x和y的父亲 
		int fu=find(f,e[i].x);
		int fv=find(f,e[i].y);
		if(fu!=fv)//如果父亲不等 说明没有成环 
		{
			f[fv]=fu;//fu变成fv的父亲 
			cout<<"("<<e[i].x<<" "<<e[i].y<<")"<<" "<<e[i].w<<endl;
		}
	}
}
int main()
{
	cin>>nv>>ne;
	for(int i=0;i<nv;i++)//初始化邻接矩阵 
	{
		for(int j=0;j<ne;j++)
		{
			if(i==j)g[i][j]=g[j][i]=0;//如果i==j说明是同一个点，则初始化距离为0 
			else g[i][j]=g[j][i]=INF;//否则初始化为无穷大 
		}
	}
	int x,y,w;
	for(int i=0;i<ne;i++)
	{
		cin>>x>>y>>w;//输入点，边，权值 
		g[x][y]=g[y][x]=w;//无向边，则两条边都要赋值 
		e[i].x=x;
		e[i].y=y;
		e[i].w=w;
	}
	sort(e,e+ne,cmp);//调用快速排序来降序排序 
	Kruskal();//调用Kruskal算法 
	return 0;
}
/*
测试用例：讲义上的图 
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
输出结果：

按权值升序排列：
(7 4) 1
(2 8) 2
(0 1) 3
(0 5) 4
(1 8) 5
(3 7) 6
(1 6) 6
(6 5) 7
(1 2) 8
(6 7) 9
(3 4) 10
(8 3) 11
(2 3) 12
(6 3) 14
(5 4) 18
以下是最小生成树的边：
(7 4) 1
(2 8) 2
(0 1) 3
(0 5) 4
(1 8) 5
(3 7) 6
(1 6) 6
(6 7) 9 
*/ 

