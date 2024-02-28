#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[55];
int f[55][55];
int main()
{
	int n;
	scanf("%s",s+1);//从下标为1的位置输入 
	n=strlen(s+1);
	memset(f,0x7F,sizeof(f));//由于求最小，于是应该初始化为大数
	for(int i=1;i<=n;i++)
	{
		f[i][i]=1;//如果区间内只有一个字母则只要涂色一次 
	 }
	 for(int len=2;len<=n;len++)//列举区间长度 
	 {
	 	for(int i=1;i+len-1<=n;i++)//固定区间长度然后向右移动直到右边到终点 
	 	{
	 		int j=i+len-1;
	 		if(s[i]==s[j])//如果头和尾相同 
	 		{
	 			f[i][j]=min(f[i+1][j],f[i][j-1]);//选择去头或者去尾中较小的那个 
			 }else{
			 	for(int k=i;k+1<=j;k++)//如果头尾不同则遍历每一次已经确定了的区间 
			 	{
			 		f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
				 }
			 }
		 }
	  }
	  printf("%d",f[1][n]); 
	return 0;
}
