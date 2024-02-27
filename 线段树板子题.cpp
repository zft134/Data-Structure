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
}tree[maxn<<2];//������������ 
//�������� 
void build(int num,int l,int r)//num�������±꣬l���������߽磬r��������ұ߽� 
{
	tree[num].left=l; 
	tree[num].right=r;
	if(l==r)//�����߽�����ұ߽� 
	{
		tree[num].sum=a[l];//��ʱ������;��ǵ�ǰ�ڵ���� 
		return;
	}
	int mid=(l+r)>>1;
	//�����±���2k���Һ����±���2k+1 
	build((num<<1),l,mid);//�������� 
	build((num<<1|1),mid+1,r);//�����Һ��� 
	//��ʱ����ڵ������͵������ӵ������+������������� 
	tree[num].sum=tree[num<<1].sum+tree[num<<1|1].sum;
}
//������·����� 
void down(int num)
{
	tree[num<<1].lazy+=tree[num].lazy;//�����Ӽ�������� 
	tree[num<<1].sum+=(tree[num<<1].right-tree[num<<1].left+1)*tree[num].lazy;//���ӵ�sum���ԭ����sum�����������������������ָ������ϱ�ǩ 
	tree[num<<1|1].lazy+=tree[num].lazy;//���Һ��Ӽ�������� 
	tree[num<<1|1].sum+=(tree[num<<1|1].right-tree[num<<1|1].left+1)*tree[num].lazy;//�Һ��ӵ�sum���ԭ����sum�����Һ������������������ָ������ϱ�ǩ 
	tree[num].lazy=0;//��num�ڵ������������ 
}
//�����ֵ���� 
void update(int num,int l,int r,int k)
{
	//�����Ҫ���ʵ�����������������������������ȫ���غϣ���ô���أ��൱�ڼ�֦��
	if((tree[num].right<l)||(tree[num].left>r))return;
	//�����Ҫ���ʵ�����͵�ǰ�������������غϣ���ô��ֱ�Ӱ�lazy��sum���º󷵻أ����������²���
	if((tree[num].right<=r&&tree[num].left>=l))
	{
		tree[num].lazy+=k;//��num�ڵ��������� 
		tree[num].sum+=(tree[num].right-tree[num].left+1)*k;//sum���ԭ����sum�������������ָ������������ 
		return;
	}
	if(tree[num].lazy>0)//�����ǰ�ڵ�����Ǵ���0 
	{
		down(num);//������·Ÿ����� 
	}
	update((num<<1),l,r,k);//�������� 
	update((num<<1|1),l,r,k);//�����Һ��� 
	tree[num].sum=tree[num<<1].sum+tree[num<<1|1].sum;//��ʱnum�ڵ��sum�������ӵ�sum�����Һ��ӵ�sum 
}
//������ͺ���
ll query(int num,int l,int r)
{
	if((tree[num].right<l)||(tree[num].left>r))return 0;//�����Ҫ���ʵ�����������������������������ȫ���غϣ�ֱ�ӷ���0 
	if((tree[num].right<=r&&tree[num].left>=l))//�����Ҫ���ʵ�����͵�ǰ�������������غϣ�ֱ�ӷ���num��sum 
	{
		return tree[num].sum;
	}
	if(tree[num].lazy>0)//�����ǰ�ڵ�����Ǵ���0 
	{
		down(num);//������·Ÿ����� 
	}
	return query((num<<1),l,r)+query((num<<1|1),l,r);//�������Ӳ�ѯ�ĺ�+�Һ��Ӳ�ѯ�ĺ� 
}
int main()
{
	int num,x,y,k;
	scanf("%d %d",&n,&m);//n�Ǹ������ֵĸ�����m�ǲ������ܸ��� 
	for(int i=1;i<=n;i++)//�����ִ��������� 
	{
		scanf("%d",&a[i]);
	}
	build(1,1,n);//����
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&num);
		if(num==1)//����һ 
		{
			scanf("%d %d %d",&x,&y,&k);//x��������߽磬y�������ұ߽磬k��ÿ������Ҫ���ϵ��� 
			update(1,x,y,k);
		}else if(num==2)//����� 
		{
			scanf("%d %d",&x,&y);//x��������߽磬y�������ұ߽� 
			ll int sum;
			sum=query(1,x,y);//������� 
			printf("%lld\n",sum); 
		 } 
	} 
	return 0;
} 

/*
�������ݣ�
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4
���Խ����
11
8
20 
*/ 
