//�༭����(���Զ�̬�滮)
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char a[2005],b[2005]; 
int dp[2005][2005]; // ��̬�滮����

int main()
{
	cin>>a+1>>b+1; // �����ַ���a��b,���±�һ��ʼ�洢�����ǵ���i-1,j-1����0��ʼ���ܻ�Խ�磩 
	n=strlen(a+1); // �����ַ���a�ĳ���
	m=strlen(b+1); // �����ַ���b�ĳ���

	for(int i=1;i<=n;i++)//a�ַ���i���ַ���b�ַ���0���ַ���ֻ��Ҫ��a�е�i���ַ���ȫ��ɾ�� 
		dp[i][0]=i;
	for(int j=1;j<=m;j++)//a�ַ���0���ַ���b�ַ���j���ַ���ֻ��Ҫ��a�����j���ַ� 
		dp[0][j]=j;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]) // ���a�ַ�����i���ַ���b�ַ�����j���ַ���ͬ 
			{
				dp[i][j]=dp[i-1][j-1]; // ��ֱ�Ӽ̳������ 
			}
			else // �����ǰ�ַ���ͬ
			{
				// dp[i][j-1] dp[i-1][j] dp[i-1][j-1]��������С���ټ�һ���ֱ��Ӧ��a����ӣ�a��ɾ����a���滻���Ӷ�����dp[i][j]�� 
				dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
			}
		}
	}
	cout<<dp[n][m]<<endl; // dp[n][m]��Ϊ��� 
	return 0;
}

/*
���룺
sfdqxbw
gfdgw
�����
4 
*/

