//��״���������޸ģ�������� 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int Maxn=1e6+5;
int a[500005];//�������� 
ll c[Maxn];//��״����,ͬʱҲ�ǲ������ 
int n,m;
int lowbit(int x)//lowbit���������������䷶Χ  
{
	return x&(-x);
 } 
void update(int pos,int k)//������״������е��� 
{
	for(int i=pos;i<=n;i+=lowbit(i))//���µ�ǰ�±������±겢�Ҹ����丸���ǵ���ֵ 
	{
		c[i]+=k;
	}
}
ll ask_qujian(int pos)//��ָ������� 
{
	ll ans=0;
	for(int i=pos;i>0;i-=lowbit(i))//�������ǰ��� 
	{
		ans+=c[i];//c[i]��ʾ������[c[i]-lowbit(i),c[i]]�������
	}
	return ans;
}
int main()
{
	memset(c,0,sizeof(c));
	scanf("%d %d",&n,&m);//n������m�β��� 
	a[0]=0;//���������һ������ֵΪ0�����±�1λ�ÿ�ʼ��ʽ��ֵ 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(i,a[i]-a[i-1]);//�����޸���״�����е�ֵ 
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	int choice,x,y,k;
	 	scanf("%d",&choice);//ѡ�� 
	 	if(choice==1)//�����޸� 
	 	{
	 		scanf("%d %d %d",&x,&y,&k);
	 		//���ڲ���������������䣨x,y��ͬʱ��ÿ�����޸�һ��ֵ 
		 	update(x,k);//ֻ��Ҫ��xλ�ü��� 
	 	 	update(y+1,-k);//��y+1λ���ټ�ȥ	 		
		 }else{
		 	scanf("%d",&x);
		 	//������״�����д�ŵ��ǲ�֣�������ĳ�����ֵ�����������1������±�ĺ� 
		 	printf("%lld\n",ask_qujian(x));
		 }
	 }
	return 0;
}
/*
��Դ�����p3368[ģ��]��״����2 
���ݣ�
5 5
1 5 4 2 3
1 2 4 2
2 3
1 1 5 -1
1 3 5 7
2 4
�����
6
10 
*/ 
