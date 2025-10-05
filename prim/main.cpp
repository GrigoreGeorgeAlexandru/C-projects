
#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
using namespace std;


int V,E,g[10000][10000];


int minKey(int key[], bool mstSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


void printMST(int parent[], int graph[10000][10000])
{
    cout<<"Edge \tWeight\n";

    for (int i = 1; i < V; i++)
        cout<<parent[i]+1<<" - "<<i+1<<" \t"<<graph[i][parent[i]]<<" \n";
}


void primMST(int graph[10000][10000])
{

    int parent[V];

    int key[V];


    bool mstSet[V];


    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;


    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < V - 1; i++)
    {

        int u = minKey(key, mstSet);


        mstSet[u] = true;


        for (int v = 0; v < V; v++)


            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }


    printMST(parent, graph);
}


int main()
{

       ifstream f("grafpond");
       f>>V>>E;
    int x,y,w;

       for(int i=1;i<=E;i++)
{
     f>>x>>y>>w;
     g[x-1][y-1]=w;
      g[y-1][x-1]=w;
}
// for(int i=1;i<=V;i++)
// {for(int j=1;j<=V;j++)
// cout<<g[i][j]<<" ";
// cout<<endl;
// }

    primMST(g);

    return 0;
}
