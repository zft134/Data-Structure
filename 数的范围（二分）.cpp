//���ķ�Χ�����֣� 
#include<iostream>
#include<cstdio>
using namespace std;
int q[100005];
int n;
int m;
int mid;
int main()
{
	cin>>n>>m;//n������m����ѯ������
	for(int i=0;i<n;i++)cin>>q[i];
	for(int i=0;i<m;i++)
	{
		int x;//Ҫ��ѯ���� 
		cin>>x;
		//���ֲ���
		int l=-1,r=n;//������˵�,�����ҵ�һ�����ڵ���x��ֵ,l�����һ��С��x��������r�ǵ�һ������x���� 
		while(l+1!=r)
		{
			mid=(l+r)/2;
			if(q[mid]>=x)r=mid;
			else l=mid;
		}
		if(q[r]!=x)cout<<"-1 -1"<<endl;//���������
		else {//��������������˵� 
			cout<<r<<" ";
			int ll=-1,rr=n;
			while(ll+1!=rr)//�����Ҷ˵㣬���������һ��С�ڵ���x��ֵ��rr�ǵ�һ������x������ll�ǵ�һ��С��x���� 
			{
				mid=(ll+rr)/2;
				if(q[mid]<=x)ll=mid;
				else rr=mid; 
		 	}
			cout<<ll<<endl; 
		}
	}
    return 0;
}
/*
����������
6 3
1 2 2 3 3 4
3
4
5
���������
3 4
5 5
-1 -1 
*/ 
