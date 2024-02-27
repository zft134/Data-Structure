//01背包板子题 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ti[1005],v[1005];
//存放每种物品耗费的时间和价值 
int f[1005];
int main()
{
	int t,m;
	//t表示总时间，m表示总共的种类 
	scanf("%d %d",&t,&m);
	for(int i=1;i<=m;i++)
	//输入每种物品耗费的时间和价值 
	{
		scanf("%d %d",&ti[i],&v[i]);
	}
	for(int i=1;i<=m;i++)
	//从时间为1到最大开始循环判断 
	{
		for(int j=t;j>=ti[i];j--)
		//每次循环从最大时间倒着遍历，
		//直到整个背包都无法装下信增加的物品 
		//倒着遍历是因为后面的数据要用到前面的数据 
		{
			f[j]=max(f[j],f[j-ti[i]]+v[i]);
		}
	}
	printf("%d",f[t]);
	return 0;
}
