//数的范围（二分） 
#include<iostream>
#include<cstdio>
using namespace std;
int q[100005];
int n;
int m;
int mid;
int main()
{
	cin>>n>>m;//n个数和m个查询的数字
	for(int i=0;i<n;i++)cin>>q[i];
	for(int i=0;i<m;i++)
	{
		int x;//要查询的数 
		cin>>x;
		//二分查找
		int l=-1,r=n;//查找左端点,即查找第一个大于等于x的值,l是最后一个小于x的数，则r是第一个大于x的数 
		while(l+1!=r)
		{
			mid=(l+r)/2;
			if(q[mid]>=x)r=mid;
			else l=mid;
		}
		if(q[r]!=x)cout<<"-1 -1"<<endl;//如果不存在
		else {//如果存在则输出左端点 
			cout<<r<<" ";
			int ll=-1,rr=n;
			while(ll+1!=rr)//查找右端点，即查找最后一个小于等于x的值，rr是第一个大于x的数，ll是第一个小于x的数 
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
输入样例：
6 3
1 2 2 3 3 4
3
4
5
输出样例：
3 4
5 5
-1 -1 
*/ 
