//��״���鵥���޸ģ������������ 
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
int const maxn=500005;
int n,m,k,x,y;
ll a,c[maxn];
int lowbit(int x)//lowbit���������������䷶Χ 
{
	return x&(-x);
}
void add(int u,int v)//��uλ��add��v���Ӹ�ֵ�������޸�u+lowbit(u) 
{
	for(int i=u;i<=n;i+=lowbit(i))
	{
		c[i]+=v;
	}
}
ll sum(int u)//��ӵ�һ������͵�ָ���±� 
{
	int ans=0;
	for(int i=u;i>0;i-=lowbit(i)) 
	{
		ans+=c[i];//c[i]��ʾ������[c[i]-lowbit(i),c[i]]�������
	}
	return ans;
}
int main()
{
	scanf("%d %d",&n,&m);//n������m������ 
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);//����ÿ������ 
		add(i,a);//���뵽��a��״����i�±��λ�ã�����add�����޸�i�±길���ǵ�ֵ�����׽ڵ���±�Ҳ������i+lowbit��i�� 
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&k,&x,&y); 
		if(k==1) 
		{
			add(x,y);
		}
		if(k==2)
		{
			printf("%lld\n",sum(y)-sum(x-1));//������������������ 
		}
	}
	return 0;
} 
/*
��Ŀ��Դ��
���P3374[ģ��]��״����1
�������ݣ�
5 5
1 5 4 2 3
1 1 3
2 2 5
1 3 -1
1 4 2
2 1 4
���Խ����
14
16 
*/
