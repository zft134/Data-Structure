// �����������֮���Զ�̬�滮���
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e3+5; // ���������С
int n; // ��������г���
int a[N],dp[N]; // ԭʼ���м���̬�滮����
int main()
{
	cin>>n; // �������г���
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; // ��������Ԫ��
		dp[i]=1; // ��ʼ����̬�滮����
	}
	int ans=0; // ���մ�
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)//���д������ڲ�ѭ�������ڱ��������е�ǰλ��i֮ǰ��Ԫ�أ���Ѱ���ܹ������Ե�ǰλ��i��β������������еĿ��ܵ�ǰ׺���С� 
		{
			if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+1); // ״̬ת�Ʒ���
		}
		ans=max(ans,dp[i]); // ��������������г���
	}
	cout<<ans; // ������
	return 0;
} 
/*
����������
6
1 2 4 1 3 4
���������
4 
*/

