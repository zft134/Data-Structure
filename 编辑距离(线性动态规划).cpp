//编辑距离(线性动态规划)
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char a[2005],b[2005]; 
int dp[2005][2005]; // 动态规划数组

int main()
{
	cin>>a+1>>b+1; // 输入字符串a和b,从下标一开始存储（考虑到有i-1,j-1，从0开始可能会越界） 
	n=strlen(a+1); // 计算字符串a的长度
	m=strlen(b+1); // 计算字符串b的长度

	for(int i=1;i<=n;i++)//a字符串i个字符而b字符串0个字符，只需要把a中的i个字符串全部删掉 
		dp[i][0]=i;
	for(int j=1;j<=m;j++)//a字符串0个字符而b字符串j个字符，只需要在a中添加j个字符 
		dp[0][j]=j;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]) // 如果a字符串第i个字符和b字符串第j个字符相同 
			{
				dp[i][j]=dp[i-1][j-1]; // 则直接继承上面的 
			}
			else // 如果当前字符不同
			{
				// dp[i][j-1] dp[i-1][j] dp[i-1][j-1]三者中最小的再加一（分别对应着a的添加，a的删除，a的替换，从而到达dp[i][j]） 
				dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
			}
		}
	}
	cout<<dp[n][m]<<endl; // dp[n][m]即为结果 
	return 0;
}

/*
输入：
sfdqxbw
gfdgw
输出：
4 
*/

