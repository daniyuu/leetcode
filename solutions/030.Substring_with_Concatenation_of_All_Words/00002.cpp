#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <limits.h>
#include <string>
#define M 100
#define N 100
using namespace std;

typedef struct node
{
    int **matrix;      //邻接矩阵
    int n;                 //顶点数
    int e;                 //边数
}MGraph;

int n,m;

void DijkstraPath(MGraph g,int *dist,int *path,int v0)   //v0表示源顶点
{
    int i,j,k;
    bool *visited=(bool *)malloc(sizeof(bool)*g.n);
    for(i=0;i<g.n;i++)     //初始化
    {
        if(g.matrix[v0][i]>0&&i!=v0)
        {
            dist[i]=g.matrix[v0][i];
            path[i]=v0;     //path记录最短路径上从v0到i的前一个顶点
        }
        else
        {
            dist[i]=INT_MAX;    //若i不与v0直接相邻，则权值置为无穷大
            path[i]=-1;
        }
        visited[i]=false;
        path[v0]=v0;
        dist[v0]=0;
    }
    visited[v0]=true;
    for(i=1;i<g.n;i++)     //循环扩展n-1次
    {
        int min=INT_MAX;
        int u = 0;
        for(j=0;j<g.n;j++)    //寻找未被扩展的权值最小的顶点
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        visited[u]=true;
        for(k=0;k<g.n;k++)   //更新dist数组的值和路径的值
        {
            if(visited[k]==false&&g.matrix[u][k]>0&&min+g.matrix[u][k]<dist[k])
            {
                dist[k]=min+g.matrix[u][k];
                path[k]=u;
            }
        }
    }
}




void modify(MGraph g, int *dist, int *path ,int v0){
    DijkstraPath(g,dist,path,v0);

    for (int i = 0; i < n; ++i)
    {
        /* code */
    }
}

int query(MGraph g, int *dist ,int *path){
    int total = 0;
    
    for (int i = 0; i < n; ++i) {
        modify(g, dist, path, i);
        
//        for (int i = 0; i < n; ++i) {
//            cout << dist[i] << " " ;
//        }
//        
//        cout <<  endl;
        
        for (int j = i + 1; j < n; ++j) {
            total += dist[j];
        }
    }

    return total;
}

void edit(MGraph &g, int *dist, int *path){
    int u,v,k;
    cin >> u >> v >> k;
    g.matrix[u - 1][v -1] = k;
    g.matrix[v - 1][u -1] = k;
}


int main(){
    cin >> n >> m;
    
    MGraph g;
    
    g.matrix = new int*[n];
    for (int i = 0; i < n; i++){
        g.matrix[i] = new int[n];
    }
    
    int *dist=(int *)malloc(sizeof(int)*n);
    int *path=(int *)malloc(sizeof(int)*n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n;j++){
            g.matrix[i][j] = 0;
            g.matrix[j][i] = 0;
        }
    }
    
    g.n = n;
    g.e = n - 1;
    for(int i = 0 ;i < g.e;i++){
        int u,v,k;
        cin >> u >> v >> k;
        g.matrix[u - 1][v - 1] = k;
        g.matrix[v - 1][u - 1] = k;
        
    }
    
    while (m--) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "QUERY") {
            cout << query(g, dist,path) << endl;
        }else if(cmd == "EDIT"){
            edit(g, dist, path);
        }
    }
    
    
}