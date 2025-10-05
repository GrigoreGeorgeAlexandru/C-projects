#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
#include <math.h>

using namespace std;

typedef  pair<int,int> pereche;
int cx[1000];int N,E,C;
 int    cy[1000];
float total;int vizitat[1000];
struct Graf
{
    int n,m;
    vector< pair<float, pereche> > muchii;


    Graf(int n, int m)
    {
        this->n=n;
        this->m=m;
    }


    void adaugamuchie(int u,int v,int w)
    {
        muchii.push_back({w, {u, v}});
    }


    void kruskal();
};

struct Componente
{
    int *parent, *rnk;
    int n;

    Componente(int n)
    {

        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];


        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};



void Graf::kruskal()
{

    sort(muchii.begin(), muchii.end());
//for(int i=0;i<C;i++)
//{
//   cout<<muchii[i].second.first<<" "<<muchii[i].second.second<<" "<<muchii[i].first<<endl;
//}
   Componente ds(n);
  cout << "muchiile sunt:\n";
int countnr=0;
    for (int i=0;i<C;i++)
    {
        int u = muchii[i].second.first;
        int v =muchii[i].second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if(vizitat[u]==0||vizitat[v]==0)
        if (set_u != set_v)
        {total+=muchii[i].first;
            cout << u << " - " << v << endl;
            ds.merge(set_u, set_v);
            countnr++;
            vizitat[u]=1;vizitat[v]=1;
        }
    if(countnr==E)
        break;

    }


}
int dist (int i, int j)
{
    return  sqrt((cx[i]-cx[j])*(cx[i]-cx[j])+(cy[i]-cy[j])*(cy[i]-cy[j]));
}


int main()
{

       ifstream f("retea2.in");

    f>>N>>E>>C;

    Graf g(N+E, C);
    for(int i=1;i<=N+E;i++)
f>>cx[i]>>cy[i];
int x,y;
for(int i=1;i<=C;i++)
{
    f>>x>>y;
    g.adaugamuchie(x, y, dist(x,y));
//cout<<x<<" "<<y<<" "<<dist(x,y)<<endl;
}
cout<<endl;
g.kruskal();
cout<<"cost: "<<total;

    return 0;
}
