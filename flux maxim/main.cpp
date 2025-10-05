#include <iostream>
#include <fstream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
int intra[100],iese[100];
int graf[100][100];ifstream f("retea.in");
   ofstream g("retea.out");
int graff[100][100]; int v;

bool bfs(int graf2[100][100], int s, int t, int parent[])
{
//    for (int i = 1; i <=v; i++)
//        {for (int j = 1; j <=v; j++)
//
//        cout<<graf2[i][j]<<" ";
//        cout<<endl;
//        }

    bool visited[100];
    memset(visited, 0, sizeof(visited));


    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
     //  cout<<endl;
//cout<<u<<" ";
        for (int i=1; i<=v; i++)
        {
            if (visited[i]==false && (graf2[u][i] != 0))
            {
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }


    return (visited[t] == true);
}

void dfs(int graf2[100][100], int s, bool visited[])
{//cout<<s<<endl;
    visited[s] = true;
    for (int i = 1; i <=v; i++)
       if (graf2[s][i] && !visited[i])
           dfs(graf2, i, visited);
}

void fordFulkerson( int s, int t)
{
    int i, j;

    int graf2[100][100];
    for (i = 1; i <=v; i++)
        for (j = 1; j <=v; j++)
          {graf2[i][j] = graf[i][j];

          }

for (i = 1; i <=v; i++)
        for (j = 1; j <=v; j++)
          {graf2[i][j] -= graff[i][j];
            graf2[i][j] += graff[i][j];
          }



    int parent[100];
    while (bfs(graf2, s, t, parent))
    {
//         for (i = 1; i <=v; i++)
//    cout<<parent[i]<<" ";
//    cout<<endl;

        int flow = INT_MAX;
        for (int i=t; i!=s; i=parent[i])
        {
            j= parent[i];
            flow = min(flow, graf2[j][i]);
        }


        for (int i=t; i!=s; i=parent[i])
        {
            j = parent[i];

            graf2[j][i] -= flow;

            graf2[i][j] += flow;
        }

//cout<<endl;

    }

bool visited[v];
    memset(visited, false, sizeof(visited));
    dfs(graf2, s, visited);
    for (i = 1; i <=v; i++)
        for (j = 1; j <=v; j++)
            if(graf[i][j]>0)
            g<<i<<" "<<j<<" "<<graf2[j][i]<<endl;
int sum=0;
          for (int i = 1; i <=v; i++)
      for (int j = 1; j <=v; j++)
         if (visited[i] && !visited[j] && graf[i][j])
            sum+=graf[i][j];
g<<sum<<endl;
          for (int i = 1; i <=v; i++)
      for (int j = 1; j <=v; j++)
         if (visited[i] && !visited[j] && graf[i][j])
              g<<i<<"  "<<j<<endl;

}


int main()
{


  f>>v;
   int s,t;f>>s>>t;
   int m;f>>m;
   int init ,fin,cap,flux;
   for(int i=1;i<=m;i++)
   { f>>init>>fin>>cap>>flux;
   graf[init][fin]=cap;
    graff[init][fin]=flux;
       if(cap<flux)
        {
        g<<"NU";return 0;}


       intra[fin]+=flux;
       iese[init]+=flux;

   }



   for(int i=2;i<=v-1;i++)
    if(intra[i]!=iese[i])
    {

     g<<"NU";return 0;}
if(intra[v]!=iese[1])
{
    g<<"NU";return 0;
}

    g<<"DA";
g<<endl;


   fordFulkerson(s, t);
   return 0;

}
