#include<iostream>
#include<cstdio>
#define INF 65535
using namespace std;
int g[105][105];  // 邻接矩阵表示图
int nv, ne, v;    // 顶点数、边数、源点
int dist[105], path[105];  // 存储最短路径长度和路径
int ch[105];  // 记录节点是否已经加入最短路径
int a[105];//用来存储最后的输出顺序的 
// Dijkstra算法实现，计算源点v到其他各点的最短路径
void dijkstra()
{
    for(int i = 0; i < ne; i++)
    {
        dist[i] = g[v][i];  // 初始化距离为源点v到各点的直接距离
        if(g[v][i] != INF)//若与源点的距离不为INF说明该点与源点直接相连 
        {
            path[i] = v;  // 若有直接路径，记录路径中的前驱节点为源点v
        }
    }
    int minn;  // 最小的dist值
    int k;     // 最小dist值对应的节点
    for(int i = 1; i < nv; i++)
    {
        minn = INF;
        for(int j = 0; j < nv; j++)  // 找最小的dist
        {
            if(ch[j] == 0 && dist[j] < minn)//如果这个点没有被标定且dist值比已知的还要小 
            { 
                minn = dist[j];
                k = j;
            }
        }
        ch[k] = 1;  // 将距离最小的节点加入最短路径
        for(int j = 0; j < nv; j++)
        {//更新这个点k周围直接相连的点的距离最小值 
            if(ch[j] == 0 && dist[k] + g[k][j] < dist[j])
            {
                dist[j] = dist[k] + g[k][j];  // 更新距离值
                path[j] = k;  // 更新路径中的前驱节点
            }
        }
    }
}

int main()
{
    int x, y, w;
    cin >> nv >> ne;

    // 初始化邻接矩阵
    for(int i = 0; i < nv; i++)
    {
        for(int j = 0; j < nv; j++)
        {
            if(i == j)
                g[i][j] = g[j][i] = 0;  // 对角线上的元素为0
            else
                g[i][j] = g[j][i] = INF;  // 其他元素初始化为INF（无穷大）
        }
    }

    // 构建邻接矩阵 
    for(int i = 0; i < ne; i++)
    {
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = w;  // 有边的地方更新为对应的权值
    }

    cin >> v;  // 输入起点

    // 初始化dist、path、ch数组
    for(int i = 0; i < nv; i++)
    {
        dist[i] = INF;  // 初始化距离为无穷大
        ch[i] = 0;  // 节点未加入最短路径
    }
    dist[v] = 0;  // 源点到自身的距离为0
    ch[v] = 1;  // 将源点加入最短路径
    path[v] = v;  // 源点的前驱节点为自身

    dijkstra();  // 调用Dijkstra算法计算最短路径

    // 输出最短路径长度和路径
    for(int i = 0; i < nv; i++)
	{
    	cout << "源点" << v << "到" << i << "的最短路径长度是：" << dist[i] << "----";
    	// 倒序保存最短路径
    	int j = i;
    	int k=0;
		a[k++]=i;//保存当前节点 
    	while(path[j] != j)//path[j]=j说明已经到源点了 
    	{
			a[k++]=path[j];// 保存路径中的前驱节点
        	j = path[j];  // 移动到前驱节点，准备输出前驱节点的前驱节点
    	}
    	//倒序输出倒序保存的最短路径，最终得到正序的最短路径 
    	for(int m=k-1;m>=0;m--)
    	{
    		cout<<a[m]<<"->"; 
		}
    	cout << endl;  // 输出一条路径结束
	}


    return 0;
}
/*
9 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
0
*/
