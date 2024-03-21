// 最长上升子序列之线性动态规划求解
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e3+5; // 定义数组大小
int n; // 输入的序列长度
int a[N],dp[N]; // 原始序列及动态规划数组
int main()
{
	cin>>n; // 输入序列长度
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; // 输入序列元素
		dp[i]=1; // 初始化动态规划数组
	}
	int ans=0; // 最终答案
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)//这行代码是内层循环，用于遍历序列中当前位置i之前的元素，以寻找能够构成以当前位置i结尾的最长上升子序列的可能的前缀序列。 
		{
			if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1); // 状态转移方程
		}
		ans=max(ans,dp[i]); // 更新最长上升子序列长度
	}
	cout<<ans; // 输出结果
	return 0;
} 
/*
输入样例：
6
1 2 4 1 3 4
输出样例：
4 
*/

