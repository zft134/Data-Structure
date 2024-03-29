//树状数组单点修改，区间求和问题 
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
int const maxn=500005;
int n,m,k,x,y;
ll a,c[maxn];
int lowbit(int x)//lowbit函数是用来求区间范围 
{
	return x&(-x);
}
void add(int u,int v)//在u位置add上v，从赋值处往上修改u+lowbit(u) 
{
	for(int i=u;i<=n;i+=lowbit(i))
	{
		c[i]+=v;
	}
}
ll sum(int u)//求从第一个数求和到指定下标 
{
	int ans=0;
	for(int i=u;i>0;i-=lowbit(i)) 
	{
		ans+=c[i];//c[i]表示的区间[c[i]-lowbit(i),c[i]]的区间和
	}
	return ans;
}
int main()
{
	scanf("%d %d",&n,&m);//n个数，m个操作 
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);//输入每个数字 
		add(i,a);//将入到树a加状数组i下标的位置，并且add还会修改i下标父亲们的值，父亲节点的下标也正好是i+lowbit（i） 
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&k,&x,&y); 
		if(k==1) 
		{
			add(x,y);
		}
		if(k==2)
		{
			printf("%lld\n",sum(y)-sum(x-1));//区间和是求两次区间和 
		}
	}
	return 0;
} 
/*
题目来源：
洛谷P3374[模板]树状数组1
测试数据：
5 5
1 5 4 2 3
1 1 3
2 2 5
1 3 -1
1 4 2
2 1 4
测试结果：
14
16 
*/
