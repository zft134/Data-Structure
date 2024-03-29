//完全背包板子题 
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=1e4+5,M=1e7+5;
ll n,m,w[N],v[N],f[M];//v数组存放价值，w数组存放耗费的时间，f数组存放不同物品选择下的最优解 
int main()
{
	scanf("%lld %lld",&m,&n);//m表示总时间，n表示草药的总数目 
	for(int i=1;i<=n;i++)//输入每种草药耗费的时间和价值 
	{
		scanf("%lld %lld",&w[i],&v[i]);
	}
	for(int i=1;i<=n;i++)//从0种物品选择往后走 
	{
		for(int j=w[i];j<=m;j++)//从整个背包可以装下新的物品往后走 
		{//状态转移方程，选择放还是不放 
			f[j]=max(f[j],f[j-w[i]]+v[i]); 
		}
	}
	printf("%lld",f[m]);
	return 0;
} 
