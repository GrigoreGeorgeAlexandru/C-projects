#include <iostream>
#include <fstream>
#include <limits.h>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m;int k;
int crit[1000];
int parent[1000];
int minDistance(int dist[], bool visited[])
{

    int min = INT_MAX, min_index;

    for (int v = 1; v <=n ; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
int search(int i)
{
    for(int q=1;q<=k;q++)
        if(i==crit[q])
        return 1;
    return 0;
}

void Solution(int dist[])
{
    int mini=INT_MAX;
    int nr;
     vector <int> vect;
     for (int i = 1; i <=n; i++)
        if (dist[i]<mini&&search(i))
            mini=dist[i],nr=i;

        while(nr!=0)
        {vect.push_back(nr);
        nr=parent[nr];

        }

    for (auto it = vect.end()-1;
         it >= vect.begin(); it--)
        cout << *it<<" ";



}


void dijkstra(int graph[100][100], int src)
{
    int dist[n];

    bool visited[n];


    for (int i = 1; i <=n; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[src] = 0;
    for (int i = 1; i <=n - 1; i++) {

        int u = minDistance(dist, visited);


        visited[u] = true;


        for (int v = 1; v <=n; v++)


            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
               {

               dist[v] = dist[u] + graph[u][v];
               parent[v]=u;
               }
    }


    Solution(dist);
}


int main()
{
   ifstream f("grafpond.in");

    f>>n>>m;
    int graph[100][100]={0};
int x,y,w;
for(int i=1;i<=m;i++)
{
    f>>x>>y>>w;
    graph[x][y]=w;
    graph[y][x]=w;
}

f>>k;
int v;
for(int i=1;i<=k;i++)
f>>crit[i];
f>>v;

    dijkstra(graph, v);

    return 0;
}
