#include<iostream>
#include<cstring>
using namespace std;
 
const int N = 100, M = 100;
 
//读入点数 和 边数
int n, m;
//dis数组， 记录上次状态的dis数组
int dis[N];
 
//存储边的结构体数组
struct Edge {
    int a, b, w;
}edges[M];
 
bool bellmanford() {
    //初始化dist数组
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;// 1是源点
    //经过 n - 1次松驰
    //对所有边进行一次松弛操作，就求出了源点到所有点，经过的边数最多为1的最短路
	//对所有边进行两次松弛操作，就求出了源点到所有点，经过的边数最多为2的最短路
	//....
	//对所有边进行n- 1次松弛操作，就求出了源点到所有点，经过的边数最多为n - 1的最短路
	bool flag=0;
	//如果执行到第n次循环，则说明有负环 
    for(int i = 1; i <=n; i++) {
        //遍历所有边
        flag=0; 
        for(int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if(dis[a] != 0x3f3f3f3f && dis[b] > dis[a] + w) //松弛操作
            {
				dis[b] = dis[a] + w;
				flag=1;
			}
                
        }
        if(flag==0)
        {
        	break;
		}
    }
    return flag;  
}
int main() {
    //读入点数，边数
    cin >> n >> m;
    //读入边
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
 
    //调用 bellman - ford算法
    bool f=bellmanford();
    if(f)
    {
    	printf("含有负环"); 
	}
    else
    {
    	//打印dis数组
    for(int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    
	}
    cout << endl;

    return 0;
}
/*
输出样例
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
输出样例
0 -3 -1 2 4
*/
