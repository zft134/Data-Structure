//��ȫ���������� 
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=1e4+5,M=1e7+5;
ll n,m,w[N],v[N],f[M];//v�����ż�ֵ��w�����źķѵ�ʱ�䣬f�����Ų�ͬ��Ʒѡ���µ����Ž� 
int main()
{
	scanf("%lld %lld",&m,&n);//m��ʾ��ʱ�䣬n��ʾ��ҩ������Ŀ 
	for(int i=1;i<=n;i++)//����ÿ�ֲ�ҩ�ķѵ�ʱ��ͼ�ֵ 
	{
		scanf("%lld %lld",&w[i],&v[i]);
	}
	for(int i=1;i<=n;i++)//��0����Ʒѡ�������� 
	{
		for(int j=w[i];j<=m;j++)//��������������װ���µ���Ʒ������ 
		{//״̬ת�Ʒ��̣�ѡ��Ż��ǲ��� 
			f[j]=max(f[j],f[j-w[i]]+v[i]); 
		}
	}
	printf("%lld",f[m]);
	return 0;
} 
