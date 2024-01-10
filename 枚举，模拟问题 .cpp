//枚举，模拟问题 
#include<iostream>
#include<cstdio>
using namespace std;
int n,sx,sy;
int a[100005],b[100005],x[100005],y[100005];//a，b数组分别存放地毯的(x,y)坐标，x,y数组分别存放地毯在x,y轴上的长度 
int main()
{
	scanf("%d",&n);//n个数 
	for(int i=1;i<=n;i++)//输入n个地毯的参数 
	{
		scanf("%d %d %d %d",&a[i],&b[i],&x[i],&y[i]);
	}
	scanf("%d %d",&sx,&sy);//输入所求的点的坐标 
	int ans=-1;//先初始化结果为-1(对于要考虑可能没有找到的情况，一开始初始化就要假设是没找到的情况) 
	for(int i=n;i>=1;i--)//从后往前找地毯 
	{
		if(sx>=a[i]&&sx<=a[i]+x[i]&&sy>=b[i]&&sy<=b[i]+y[i])
		{
			ans=i;//找到就赋值并推出循环 
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
 } 
/*
题目来源：
洛谷P1003：铺地毯 
输入数据1：
3
1 0 2 3
0 2 3 3
2 1 3 3
2 2
输出结果1：
3

输入数据2：
3
1 0 2 3
0 2 3 3
2 1 3 3
4 5
输出结果2：
-1
*/ 
