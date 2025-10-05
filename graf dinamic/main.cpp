#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
using namespace std;

typedef  pair<int,int> pereche;
vector <int>  solution;
int visited[100001];int positions[100001];
vector <int> neighbours1[100001];
vector <int> neighbours2[100001];
vector<int> graph[100001];
vector<int> cycles;
int nr;
int total,total1,total2;
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
Graf apcm(100,100);
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
        {apcm.adaugamuchie(u,v,it->first);
        neighbours2[u].push_back(v); neighbours2[v].push_back(u);nr++;
            cout << u << " - " << v << endl;
            ds.merge(set_u, set_v);
          total+= it->first;
        }
    }


}



void dfs_cycle(int u, int p, int color[],
               int mark[], int par[], int& cyclenumber)
{


    if (color[u] == 2) {
        return;
    }


    if (color[u] == 1) {

        cyclenumber++;
        int current = p;
        mark[current] = cyclenumber;
        while (current != u) {
            current = par[current];
            mark[current] = cyclenumber;
        }
        return;
    }
    par[u] = p;


    color[u] = 1;


    for (int v : neighbours2[u]) {

        if (v == par[u]) {
            continue;
        }
       // cout<<u<<" "<<v<<endl;
        dfs_cycle(v, u, color, mark, par, cyclenumber);
    }


    color[u] = 2;
}


int main()
{

       ifstream f("grafpond.in");
    int n,m;
    f>>n>>m;
    Graf g(n+1, m+1);
int x,y,w;
int mx,my,mw;
for(int i=1;i<=m;i++)
{
    f>>x>>y>>w;
    g.adaugamuchie(x, y, w);
    neighbours1[x].push_back(y); neighbours1[y].push_back(x);
}g.kruskal();

cout<<"cost "<<total<<endl;
total1=total;
total=0;
f>>mx>>my>>mw;
g.adaugamuchie(mx, my, mw);
neighbours1[mx].push_back(my); neighbours1[my].push_back(mx);



apcm.adaugamuchie(mx, my, mw);neighbours2[mx].push_back(my); neighbours2[my].push_back(mx);
int color[100001];
    int par[100001];


    int mark[100001];


    int cyclenumber = 0;
    int edges = nr+1;


    dfs_cycle(mx, 0, color, mark, par, cyclenumber);

int len=0;
     for (int i = 1; i <= edges; i++) {
        if (mark[i] != 0)
{
cycles.push_back(i);}
len++;
     }

int maxi=0;
   int i=1;


while(i!=len-1)
{  vector< pair<int, pereche> >::iterator it;
    for (it=g.muchii.begin(); it!=g.muchii.end(); it++)
        for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
        if(it->second.first==cycles[i]&&it->second.second==cycles[j])
if(maxi<it->first)
    maxi=it->first;



i++;
}
cout<<"muchie cost max din ciclu:";
cout<<maxi<<endl;
g.kruskal();
cout<<"cost "<<total<<endl;
total2=total;
total=0;


    return 0;
}
