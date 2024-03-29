//树状数组区间修改，单点求和 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int Maxn=1e6+5;
int a[500005];//基础数组 
ll c[Maxn];//树状数组,同时也是差分数组 
int n,m;
int lowbit(int x)//lowbit函数是用来求区间范围  
{
	return x&(-x);
 } 
void update(int pos,int k)//更新树状数组的中的数 
{
	for(int i=pos;i<=n;i+=lowbit(i))//更新当前下标数的下标并且更新其父亲们的数值 
	{
		c[i]+=k;
	}
}
ll ask_qujian(int pos)//求指定区间和 
{
	ll ans=0;
	for(int i=pos;i>0;i-=lowbit(i))//从最后往前求和 
	{
		ans+=c[i];//c[i]表示的区间[c[i]-lowbit(i),c[i]]的区间和
	}
	return ans;
}
int main()
{
	memset(c,0,sizeof(c));
	scanf("%d %d",&n,&m);//n个数，m次操作 
	a[0]=0;//基础数组第一个数赋值为0，从下标1位置开始正式赋值 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(i,a[i]-a[i-1]);//单点修改树状数组中的值 
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	int choice,x,y,k;
	 	scanf("%d",&choice);//选择 
	 	if(choice==1)//区间修改 
	 	{
	 		scanf("%d %d %d",&x,&y,&k);
	 		//对于差分数组在数组区间（x,y）同时给每个数修改一个值 
		 	update(x,k);//只需要在x位置加上 
	 	 	update(y+1,-k);//在y+1位置再减去	 		
		 }else{
		 	scanf("%d",&x);
		 	//由于树状数组中存放的是差分，所以求某个点的值即求差分数组从1到这个下标的和 
		 	printf("%lld\n",ask_qujian(x));
		 }
	 }
	return 0;
}
/*
来源：洛谷p3368[模板]树状数组2 
数据：
5 5
1 5 4 2 3
1 2 4 2
2 3
1 1 5 -1
1 3 5 7
2 4
结果：
6
10 
*/ 
