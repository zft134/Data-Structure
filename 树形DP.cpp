//����DP 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 6005
using namespace std;
int h[MAXN];//�洢ÿ���ڵ��Ȩ�� 
int v[MAXN];//�ж�ÿ���ڵ��Ƿ��и��׽ڵ㣬����Ѱ�Ҹ��ڵ� 
vector<int> tree[MAXN];//�ڽӱ��ͼ 
int f[MAXN][2];//״̬����,f[x][0]��ʾx�ڵ㲻�μӣ�f[x][1]��ʾx�ڵ�μ� 
void dfs(int x)//��ȱ������� 
{
	f[x][0]=0;//��ǰ�ڵ㲻�μ� 
	f[x][1]=h[x];//��ǰ�ڵ�μ� 
	for(int i=0;i<tree[x].size();i++)//������ǰ�ڵ������ 
	{
		int y=tree[x][i];
		dfs(y);//�ҵ�һ���ӽڵ�֮����������ӽڵ������ 
		f[x][0]+=max(f[y][0],f[y][1]);//��ǰ�ڵ�Ĳμӵ����ֵ���ӽڵ�μӺͲ��μ��нϴ�� 
		f[x][1]+=f[y][0]; //��ǰ�ڵ�μӵ����ֵ���ӽڵ㲻�μӵ� 
	}
}
int main()
{
	int n;//�ڵ�ĸ��� 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	for(int i=1;i<n;i++)//��ϵ�ĸ����Ƚڵ�����1����Ϊ���ڵ�û�и��׽ڵ㣩 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		tree[y].push_back(x);//������ϵ����ʽǰ���Ǵ�ͼ 
		v[x]=1;//���x�и��� 
	}
	int root;
	for(int i=1;i<=n;i++)//Ѱ�Ҹ��ڵ� 
	{
		if(!v[i])//û�и��׽ڵ���Ǹ��ڵ� 
		{
			root=i;
			break;
		}
	}
	//�ҵ����ڵ�֮��Ը��ڵ������ȱ��� 
	dfs(root);
	printf("%d\n",max(f[root][0],f[root][1])); //���Ǹ��ڵ�μӺͲ��μ��нϴ�� 
	return 0;
}
/*
�������� 
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

���Խ����
5 
*/
