#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n,m;
const int maxn=1e6+5;
int a[maxn];
struct node
{
	ll int left;
	ll int right;
	ll int sum;
	ll int lazy;
}tree[maxn<<2];//用数组来存树 
//建树函数 
void build(int num,int l,int r)//num是数组下标，l是区间的左边界，r是区间的右边界 
{
	tree[num].left=l; 
	tree[num].right=r;
	if(l==r)//如果左边界等于右边界 
	{
		tree[num].sum=a[l];//此时的区间和就是当前节点的数 
		return;
	}
	int mid=(l+r)>>1;
	//左孩子下标是2k，右孩子下标是2k+1 
	build((num<<1),l,mid);//创建左孩子 
	build((num<<1|1),mid+1,r);//创建右孩子 
	//此时这个节点的区间和等于左孩子的区间和+右子树的区间和 
	tree[num].sum=tree[num<<1].sum+tree[num<<1|1].sum;
}
//懒标记下方函数 
void down(int num)
{
	tree[num<<1].lazy+=tree[num].lazy;//给左孩子加上懒标记 
	tree[num<<1].sum+=(tree[num<<1].right-tree[num<<1].left+1)*tree[num].lazy;//左孩子的sum变成原来的sum加上左孩子所包含的区间数字个数乘上标签 
	tree[num<<1|1].lazy+=tree[num].lazy;//给右孩子加上懒标记 
	tree[num<<1|1].sum+=(tree[num<<1|1].right-tree[num<<1|1].left+1)*tree[num].lazy;//右孩子的sum变成原来的sum加上右孩子所包含的区间数字个数乘上标签 
	tree[num].lazy=0;//给num节点消除掉懒标记 
}
//区间加值函数 
void update(int num,int l,int r,int k)
{
	//如果需要访问的区间和现在所遍历到的这个区间完全不重合，那么返回，相当于剪枝。
	if((tree[num].right<l)||(tree[num].left>r))return;
	//如果需要访问的区间和当前遍历到的区间重合，那么就直接把lazy和sum更新后返回，无需再向下查找
	if((tree[num].right<=r&&tree[num].left>=l))
	{
		tree[num].lazy+=k;//给num节点加上懒标记 
		tree[num].sum+=(tree[num].right-tree[num].left+1)*k;//sum变成原来的sum加上区间内数字个数乘上懒标记 
		return;
	}
	if(tree[num].lazy>0)//如果当前节点懒标记大于0 
	{
		down(num);//懒标记下放给孩子 
	}
	update((num<<1),l,r,k);//更新左孩子 
	update((num<<1|1),l,r,k);//更新右孩子 
	tree[num].sum=tree[num<<1].sum+tree[num<<1|1].sum;//此时num节点的sum就是左孩子的sum加上右孩子的sum 
}
//区间求和函数
ll query(int num,int l,int r)
{
	if((tree[num].right<l)||(tree[num].left>r))return 0;//如果需要访问的区间和现在所遍历到的这个区间完全不重合，直接返回0 
	if((tree[num].right<=r&&tree[num].left>=l))//如果需要访问的区间和当前遍历到的区间重合，直接返回num的sum 
	{
		return tree[num].sum;
	}
	if(tree[num].lazy>0)//如果当前节点懒标记大于0 
	{
		down(num);//懒标记下放给孩子 
	}
	return query((num<<1),l,r)+query((num<<1|1),l,r);//返回左孩子查询的和+右孩子查询的和 
}
int main()
{
	int num,x,y,k;
	scanf("%d %d",&n,&m);//n是该列数字的个数，m是操作的总个数 
	for(int i=1;i<=n;i++)//将数字存入数组中 
	{
		scanf("%d",&a[i]);
	}
	build(1,1,n);//建树
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&num);
		if(num==1)//问题一 
		{
			scanf("%d %d %d",&x,&y,&k);//x是区间左边界，y是区间右边界，k是每个数字要加上的数 
			update(1,x,y,k);
		}else if(num==2)//问题二 
		{
			scanf("%d %d",&x,&y);//x是区间左边界，y是区间右边界 
			ll int sum;
			sum=query(1,x,y);//区间求和 
			printf("%lld\n",sum); 
		 } 
	} 
	return 0;
} 

/*
测试数据：
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4
测试结果：
11
8
20 
*/ 
