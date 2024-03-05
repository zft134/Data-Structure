//��С������Kruskal�㷨 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 65535 //��������� 
/*����С������---->ѡ��n-1���ߣ�
 
1.ѡ��n-1��Ȩֵ����С�ıߣ� ÿ�ζ�ѡ�µ���С�ı�E---����̰�� 
2. ���в��ܳ��ֻ� ��   ���ò��鼯���ж�һ�� E�������˵��ǲ�������ͬһ����ͨ���ϣ�(1)yes,˵��E����ѡ  (2)no, ˵��ҪѡE 

Kruskal��˼· ---̰�ģ�̰����˼�� �������ܺ�   Ŀ���ǳ 

ʱ�临�Ӷȣ��ڲ��鼯����·��ѹ���Ļ����� O(eloge) ----�ʺ� ϡ��ͼ 
*/ 
using namespace std;
int g[105][105];//�ڽӾ����ͼ 
int nv,ne;//nv���㣬ne���� 
struct  Edge{//x-->y 
	int x;
	int y;
	int w;
}e[5005];//�߼����� 
bool cmp(struct Edge a,struct Edge b){//�ṹ���������� 
	return a.w < b . w;
}
//ѡ������ 
//void sorte(int l,int r)
//{
//	//ѡ��
//	int minn;
//	Edge tmp;
//	for(int i=l;i<r;i++)
//	{
//		minn=i;
//		for(int j=i+1;j<r;j++)
//		{
//			if(e[minn].w >e[j].w )
//			{
//				minn=j;
//			}
//			
//		 } 
//		tmp=e[i];
//		e[i]=e[minn];
//		e[minn]=tmp;
//	 } 
//	 //�������֮��Ľ����
//	 printf("��Ȩֵ�������У�\n");
//	 for(int i=0;i<r;i++)
//	 {
//	 	printf("(%d %d) %d\n",e[i].x,e[i].y,e[i].w);
//	  }  
//}
int find(int f[],int z)//���Ҹ��׺��� 
{
	while(z!=f[z])//���z������z�ĸ��� 
	{
		z=f[z];//�ͰѸ��׵�ֵ����z 
	}
	return z;
}
void Kruskal()
{
	int f[105];//���常������ 
	for(int i=0;i<nv;i++)
	{
		f[i]=i;//�տ�ʼ�����Լ��ĸ������Լ� 
	}
	cout<<"��������С�������ıߣ�"<<endl;
	for(int i=0;i<ne;i++)
	{
		//�ֱ����x��y�ĸ��� 
		int fu=find(f,e[i].x);
		int fv=find(f,e[i].y);
		if(fu!=fv)//������ײ��� ˵��û�гɻ� 
		{
			f[fv]=fu;//fu���fv�ĸ��� 
			cout<<"("<<e[i].x<<" "<<e[i].y<<")"<<" "<<e[i].w<<endl;
		}
	}
}
int main()
{
	cin>>nv>>ne;
	for(int i=0;i<nv;i++)//��ʼ���ڽӾ��� 
	{
		for(int j=0;j<ne;j++)
		{
			if(i==j)g[i][j]=g[j][i]=0;//���i==j˵����ͬһ���㣬���ʼ������Ϊ0 
			else g[i][j]=g[j][i]=INF;//�����ʼ��Ϊ����� 
		}
	}
	int x,y,w;
	for(int i=0;i<ne;i++)
	{
		cin>>x>>y>>w;//����㣬�ߣ�Ȩֵ 
		g[x][y]=g[y][x]=w;//����ߣ��������߶�Ҫ��ֵ 
		e[i].x=x;
		e[i].y=y;
		e[i].w=w;
	}
	sort(e,e+ne,cmp);//���ÿ����������������� 
	Kruskal();//����Kruskal�㷨 
	return 0;
}
/*
���������������ϵ�ͼ 
9 15
0 1 3
0 5 4
1 6 6
6 5 7
1 2 8
1 8 5
2 8 2
2 3 12
8 3 11
6 3 14
6 7 9
5 4 18
3 7 6
7 4 1
3 4 10
��������

��Ȩֵ�������У�
(7 4) 1
(2 8) 2
(0 1) 3
(0 5) 4
(1 8) 5
(3 7) 6
(1 6) 6
(6 5) 7
(1 2) 8
(6 7) 9
(3 4) 10
(8 3) 11
(2 3) 12
(6 3) 14
(5 4) 18
��������С�������ıߣ�
(7 4) 1
(2 8) 2
(0 1) 3
(0 5) 4
(1 8) 5
(3 7) 6
(1 6) 6
(6 7) 9 
*/ 

