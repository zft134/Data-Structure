//01���������� 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ti[1005],v[1005];
//���ÿ����Ʒ�ķѵ�ʱ��ͼ�ֵ 
int f[1005];
int main()
{
	int t,m;
	//t��ʾ��ʱ�䣬m��ʾ�ܹ������� 
	scanf("%d %d",&t,&m);
	for(int i=1;i<=m;i++)
	//����ÿ����Ʒ�ķѵ�ʱ��ͼ�ֵ 
	{
		scanf("%d %d",&ti[i],&v[i]);
	}
	for(int i=1;i<=m;i++)
	//��ʱ��Ϊ1�����ʼѭ���ж� 
	{
		for(int j=t;j>=ti[i];j--)
		//ÿ��ѭ�������ʱ�䵹�ű�����
		//ֱ�������������޷�װ�������ӵ���Ʒ 
		//���ű�������Ϊ���������Ҫ�õ�ǰ������� 
		{
			f[j]=max(f[j],f[j-ti[i]]+v[i]);
		}
	}
	printf("%d",f[t]);
	return 0;
}
