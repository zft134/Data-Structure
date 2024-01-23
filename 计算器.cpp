//高精度运算器
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int a[505],b[505],c[1010];
int init(int a[],string &s)//初始化函数 
{
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)//数字储存在a数组中 
	{
		a[i]=s[len-i-1]-'0';//字符转数字 
	}
	return len;//返回的是长度 
}
void init_div(int a[])//除法用来初始化的函数 
{
	string s;
	cin>>s;
	a[0]=s.size();//首位用来存放字符串长度
	for(int i=a[0];i>0;i--)
	{
		a[i]=s[a[0]-i]-'0';
	} 
}
void numcpy(int a[],int b[],int n)
{
	a[0]=b[0]+n;
	//确定temp的位数
	for(int i=a[0];i>=a[0]-b[0]+1;i--)
	{
		a[i]=b[i-n];
		//将b右移n位 
	 } 
}
bool check(int a[], int t[])
{//判断a和t的大小，a>=temp返回1，反之返回0 
	if(a[0]>t[0])return 1;
	else if(a[0]<t[0])return 0;
	//先进行位数比较，来减少循环 
	for(int i=a[0];i>0;i--){
		//由高位到低位进行检查，在不等的情况下就可以直接判断 
		if(t[i]>a[i])return 0;
		else if(a[i]>t[i])return 1;
	}
	//说明两个数完全相等，所以返回1 
	return 1;
}
void print(int lenc)//输出函数 
{
	while(c[lenc]==0&&lenc>0)//如果前面有0 
	{
		lenc--;
	 }
	for(int i=lenc;i>=0;i--)//倒着输出 
	{
		printf("%d",c[i]);
	 }
	printf("\n");
}
void sub(int a[],int b[])
{
	for(int i=1;i<=a[0];i++)
	{
		if(a[i]<b[i])
		{
			a[i+1]--;
			a[i]+=10;
		}
		a[i]-=b[i];
	}
	int i=a[0];
	while(a[i]==0)
	{
		a[0]--;
		i--;
	}
 } 
void subtraction()
{
	string s1,s2;
	printf("请输入第一位数：\n");
	int lena=init(a,s1);
	printf("请输入第二位数：\n"); 
	int lenb=init(b,s2);
	int lenc=max(lena,lenb);
	if(lena<lenb||(lena==lenb&&s1<s2))//如果前面的数字位数小于后面或者位数相等但前面的小于后面 
	{
		swap(a,b);
		printf("-"); 
	}
	for(int i=0;i<lenc;i++)
	{
		c[i]+=a[i]-b[i];
		if(c[i]<0)
		{
			c[i+1]--;
			c[i]+=10;
		}
	}
	while(c[lenc]==0&&lenc>0)
	{
		lenc--;
	 }
	 printf("减法结果为：");
	  print(lenc);
}
void add()//加法器 
{
	string s1,s2;
	printf("请输入第一位数：\n"); 
	int lena=init(a,s1);
	printf("请输入第二位数：\n"); 
	int lenb=init(b,s2);
	int lenc=max(lena,lenb);
	for(int i=0;i<lenc;i++)//加法过程 
	{
		c[i]+=a[i]+b[i];
		if(c[i]>=10)
		{
			c[i+1]++;
			c[i]%=10;
		}
	 }
	 printf("加法结果为：");
	 print(lenc);
}
void multiplication()//乘法器 
{
	string s1,s2;
	printf("请输入第一位数：\n"); 
	int lena=init(a,s1);
	printf("请输入第二位数：\n"); 
	int lenb=init(b,s2);
	int lenc=lena+lenb;
	for(int i=0;i<lena;i++)//乘法过程 
	{
		for(int j=0;j<lenb;j++)
		{
			c[i+j]+=a[i]*b[j];
		}
	 }
	 for(int i=0;i<lenc;i++)
	 {
	 	if(c[i]>=10)
	 	{
	 		c[i+1]+=c[i]/10;
	 		c[i]%=10;
		 }
	 }
	 while(c[lenc]==0&&lenc>0)
	 {
	 	lenc--;
	  }
	  printf("乘法结果为：");
	  print(lenc);
 }
 void division()
 {
 	printf("请输入第一位数：\n"); 
 	init_div(a);
 	printf("请输入第二位数：\n"); 
	init_div(b);
	c[0]=a[0]-b[0]+1;//两个数相除之后的商的长度
	if(c[0]<0)
	{
		printf("0\n");
		return;
	 }
	for(int i=c[0];i>0;i--)
	{
		int temp[10000]={0};
		
		numcpy(temp,b,i-1);
		
		while(check(a,temp))
		{
			sub(a,temp);
			c[i]++;
		}
	 }
	 printf("除法结果为："); 
	 for(int i=c[0];i>0;i--)
	 {
	 	if(i==c[0]&&c[c[0]]==0)continue;
	 	printf("%d",c[i]);
	  }
	  printf("\n"); 
 } 
int main()
{
	printf("请输入要选择的操作：\n1.加法   2.减法\n3.乘法   4.除法\n");
	int x;
	scanf("%d",&x);
	if(x==1)
	{
		add();
	 }else if(x==2)
	 {
	 	subtraction();
	  }else if(x==3)
	  {
	  	multiplication();
	   }else if(x==4)
	   {
	   	division();
		} 
	return 0;
}
