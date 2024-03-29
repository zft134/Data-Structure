//树形DP 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 6005
using namespace std;
int h[MAXN];//存储每个节点的权重 
int v[MAXN];//判断每个节点是否有父亲节点，便于寻找根节点 
vector<int> tree[MAXN];//邻接表存图 
int f[MAXN][2];//状态数组,f[x][0]表示x节点不参加，f[x][1]表示x节点参加 
void dfs(int x)//深度遍历函数 
{
	f[x][0]=0;//当前节点不参加 
	f[x][1]=h[x];//当前节点参加 
	for(int i=0;i<tree[x].size();i++)//遍历当前节点的子树 
	{
		int y=tree[x][i];
		dfs(y);//找到一个子节点之后继续遍历子节点的子树 
		f[x][0]+=max(f[y][0],f[y][1]);//当前节点的参加的最大值是子节点参加和不参加中较大的 
		f[x][1]+=f[y][0]; //当前节点参加的最大值是子节点不参加的 
	}
}
int main()
{
	int n;//节点的个数 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	for(int i=1;i<n;i++)//关系的个数比节点数少1（因为根节点没有父亲节点） 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		tree[y].push_back(x);//建立关系，链式前向星存图 
		v[x]=1;//标记x有父亲 
	}
	int root;
	for(int i=1;i<=n;i++)//寻找根节点 
	{
		if(!v[i])//没有父亲节点的是根节点 
		{
			root=i;
			break;
		}
	}
	//找到根节点之后对根节点进行深度遍历 
	dfs(root);
	printf("%d\n",max(f[root][0],f[root][1])); //答案是根节点参加和不参加中较大的 
	return 0;
}
/*
测试样例 
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5

测试结果：
5 
*/
