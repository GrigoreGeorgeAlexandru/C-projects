#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
using namespace std;

typedef  pair<int,int> pereche;


struct Graf
{
    int n,m;
    vector< pair<int, pereche> > muchii;


    Graf(int n, int m)
    {
        this->n=n;
        this->m=m;
    }


    void adaugamuchie(int u,int v,int w)
    {
        muchii.push_back({w, {u, v}});
    }


    int kruskal();
};

struct Componente
{
    int *parent, *rnk;
    int n;

    Componente(int n)
    {

        this->n = n;
        rnk = new int[n+1];


        for (int i = 0; i <= n; i++)
        {
            rnk[i] = i;


        }
    }

    int find(int u)
    {

        return rnk[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        for(int i=1;i<=n;i++)
        if(rnk[i]==y)
        rnk[i]=x;

    }
};



int Graf::kruskal()
{

    sort(muchii.begin(), muchii.end());

    Componente ds(n);
  cout << "muchiile sunt:\n";
    vector< pair<int, pereche> >::iterator it;
    for (it=muchii.begin(); it!=muchii.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v)
        {
            cout << u << " - " << v << endl;
            ds.merge(set_u, set_v);
        }
    }


}


int main()
{

       ifstream f("grafpond.in");
    int n,m;
    f>>n>>m;
    Graf g(n, m);
int x,y,w;
for(int i=1;i<=m;i++)
{
    f>>x>>y>>w;
    g.adaugamuchie(x, y, w);
}

g.kruskal();


    return 0;
}
