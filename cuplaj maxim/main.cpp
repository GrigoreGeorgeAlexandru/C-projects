#include <iostream>
#include <fstream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
int intra[100],iese[100];
int graf[100][100];
ifstream f("retea.in");
ofstream g("retea.out");
int graff[100][100];
int v;

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



void fordFulkerson( int s, int t)
{
    int i, j;

    int graf2[100][100];
    for (i = 1; i <=v; i++)
        for (j = 1; j <=v; j++)
        {
            graf2[i][j] = graf[i][j];

        }




    int parent[100];
    while (bfs(graf2, s, t, parent))
    {
//         for (i = 1; i <=v; i++)
//    cout<<parent[i]<<" ";
//    cout<<endl;


        for (int i=t; i!=s; i=parent[i])
        {
            j = parent[i];

            graf2[j][i] -= 1;

            graf2[i][j] += 1;
        }

//cout<<endl;

    }


    for (i = 2; i <=v; i++)
        for (j = 1; j <=v-1; j++)
            if(graf[i][j]>0&&graf2[j][i]>0)
                cout<<i<<" "<<j<<" "<<graf2[j][i]<<endl;


}


int main()
{


    f>>v;
    v+=2;
    int m;
    f>>m;
    int init,fin,cap,flux;
    for(int i=1; i<=m; i++)
    {
        f>>init>>fin;
        graf[init+1][fin+1]=1;
    }

//   for(int i=2;i<=v-1;i++)
//    {for(int j=2;j<=v-1;j++)
//     cout<<graf[i][j];
//   cout<<endl;}


    int colorArr[v];
    for (int i = 2; i <=v-1; ++i)
        colorArr[i] = -1;

    for (int w = 2; w <=v-1; ++w)
        if(colorArr[w] == -1)
        {

            colorArr[w] = 1;

            queue <int> q;
            q.push(w);

            while (!q.empty())
            {
                int u = q.front();
                q.pop();



                for (int i = 2; i <=v-1; ++i)
                {

                    if ((graf[u][i] ||graf[i][u] )&& colorArr[i] == -1)
                    {
                        colorArr[i] = 1 - colorArr[u];
                        q.push(i);
                    }

                }
            }
        }
//for (int i = 2; i <=v-1; ++i)
//cout<<colorArr[i]<<" ";
//cout<<endl;

    for (int i = 2; i <=v-1; ++i)
        if(colorArr[i]==1)
            graf[1][i]=1;
        else
            graf[i][v]=1;


    fordFulkerson(1, v);
    return 0;

}
