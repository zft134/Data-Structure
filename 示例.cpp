#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[55];
int f[55][55];
int main()
{
	int n;
	scanf("%s",s+1);//���±�Ϊ1��λ������ 
	n=strlen(s+1);
	memset(f,0x7F,sizeof(f));//��������С������Ӧ�ó�ʼ��Ϊ����
	for(int i=1;i<=n;i++)
	{
		f[i][i]=1;//���������ֻ��һ����ĸ��ֻҪͿɫһ�� 
	 }
	 for(int len=2;len<=n;len++)//�о����䳤�� 
	 {
	 	for(int i=1;i+len-1<=n;i++)//�̶����䳤��Ȼ�������ƶ�ֱ���ұߵ��յ� 
	 	{
	 		int j=i+len-1;
	 		if(s[i]==s[j])//���ͷ��β��ͬ 
	 		{
	 			f[i][j]=min(f[i+1][j],f[i][j-1]);//ѡ��ȥͷ����ȥβ�н�С���Ǹ� 
			 }else{
			 	for(int k=i;k+1<=j;k++)//���ͷβ��ͬ�����ÿһ���Ѿ�ȷ���˵����� 
			 	{
			 		f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
				 }
			 }
		 }
	  }
	  printf("%d",f[1][n]); 
	return 0;
}
