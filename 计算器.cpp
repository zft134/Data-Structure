//�߾���������
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int a[505],b[505],c[1010];
int init(int a[],string &s)//��ʼ������ 
{
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)//���ִ�����a������ 
	{
		a[i]=s[len-i-1]-'0';//�ַ�ת���� 
	}
	return len;//���ص��ǳ��� 
}
void init_div(int a[])//����������ʼ���ĺ��� 
{
	string s;
	cin>>s;
	a[0]=s.size();//��λ��������ַ�������
	for(int i=a[0];i>0;i--)
	{
		a[i]=s[a[0]-i]-'0';
	} 
}
void numcpy(int a[],int b[],int n)
{
	a[0]=b[0]+n;
	//ȷ��temp��λ��
	for(int i=a[0];i>=a[0]-b[0]+1;i--)
	{
		a[i]=b[i-n];
		//��b����nλ 
	 } 
}
bool check(int a[], int t[])
{//�ж�a��t�Ĵ�С��a>=temp����1����֮����0 
	if(a[0]>t[0])return 1;
	else if(a[0]<t[0])return 0;
	//�Ƚ���λ���Ƚϣ�������ѭ�� 
	for(int i=a[0];i>0;i--){
		//�ɸ�λ����λ���м�飬�ڲ��ȵ�����¾Ϳ���ֱ���ж� 
		if(t[i]>a[i])return 0;
		else if(a[i]>t[i])return 1;
	}
	//˵����������ȫ��ȣ����Է���1 
	return 1;
}
void print(int lenc)//������� 
{
	while(c[lenc]==0&&lenc>0)//���ǰ����0 
	{
		lenc--;
	 }
	for(int i=lenc;i>=0;i--)//������� 
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
	printf("�������һλ����\n");
	int lena=init(a,s1);
	printf("������ڶ�λ����\n"); 
	int lenb=init(b,s2);
	int lenc=max(lena,lenb);
	if(lena<lenb||(lena==lenb&&s1<s2))//���ǰ�������λ��С�ں������λ����ȵ�ǰ���С�ں��� 
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
	 printf("�������Ϊ��");
	  print(lenc);
}
void add()//�ӷ��� 
{
	string s1,s2;
	printf("�������һλ����\n"); 
	int lena=init(a,s1);
	printf("������ڶ�λ����\n"); 
	int lenb=init(b,s2);
	int lenc=max(lena,lenb);
	for(int i=0;i<lenc;i++)//�ӷ����� 
	{
		c[i]+=a[i]+b[i];
		if(c[i]>=10)
		{
			c[i+1]++;
			c[i]%=10;
		}
	 }
	 printf("�ӷ����Ϊ��");
	 print(lenc);
}
void multiplication()//�˷��� 
{
	string s1,s2;
	printf("�������һλ����\n"); 
	int lena=init(a,s1);
	printf("������ڶ�λ����\n"); 
	int lenb=init(b,s2);
	int lenc=lena+lenb;
	for(int i=0;i<lena;i++)//�˷����� 
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
	  printf("�˷����Ϊ��");
	  print(lenc);
 }
 void division()
 {
 	printf("�������һλ����\n"); 
 	init_div(a);
 	printf("������ڶ�λ����\n"); 
	init_div(b);
	c[0]=a[0]-b[0]+1;//���������֮����̵ĳ���
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
	 printf("�������Ϊ��"); 
	 for(int i=c[0];i>0;i--)
	 {
	 	if(i==c[0]&&c[c[0]]==0)continue;
	 	printf("%d",c[i]);
	  }
	  printf("\n"); 
 } 
int main()
{
	printf("������Ҫѡ��Ĳ�����\n1.�ӷ�   2.����\n3.�˷�   4.����\n");
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
