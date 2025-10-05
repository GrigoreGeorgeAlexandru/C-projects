#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm>
#include <string.h>

using namespace std;
typedef  pair<int,int> pereche;  string cuvinte[1000];int nr;int k;int vizitat[1000];int q;
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

int distanta(string *s1, string *s2){
int n1=(*s1).length(); int n2=(*s2).length();
int *ci1=new int[n2+1]; int *ci=new int[n2+1];
for(int j=0;j<=n2;j++) ci1[j]=j;
for(int i=1;i<=n1;i++){
ci[0]=i;
for(int j=1;j<=n2;j++)
if(s1[i-1]==s2[j-1]) ci[j]=ci1[j-1];
else ci[j]=1+min(min(ci1[j],ci[j-1]),ci1[j-1]) ;
for(int j=0;j<=n2;j++) ci1[j]=ci[j];
}
return ci[n2];
}

int Graf::kruskal()
{

    sort(muchii.begin(), muchii.end());

    Componente ds(n);
  cout << "clasele sunt:\n";
    vector< pair<int, pereche> >::iterator it;
    for (int i=1;i<=nr-k;i++)
    {
        int u = muchii[i].second.first;
        int v = muchii[i].second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v)
        {

//cout << cuvinte[u] << " - " << cuvinte[v] << endl;

            ds.merge(set_u, set_v);



        }


    }


for(int i=1;i<n;i++)
{if(vizitat[i]==1)
   continue;

   cout<<cuvinte[i]<<" ";
   vizitat[i]=1;


    for(int j=i+1;j<=n;j++)
   {
       if(vizitat[j]==1)
   continue;
   if(ds.find(i)==ds.find(j))
       {

       cout<<cuvinte[j]<<" ";
   vizitat[j]=1;
       }


       }
        cout<<endl;
}
 for (int i=nr-k+1;i<=nr;i++)
    {
        int u = muchii[i].second.first;
        int v = muchii[i].second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v)
        {
cout<<muchii[i].first<<endl;
break;

        }

    }


}








int main()
{

       ifstream f("cuvinte.in");
cin>>k;
    int n=0;
    while(!f.eof())
    {
        n++;
        f>>cuvinte[n];
        //cout<<cuvinte[n]<<endl;
    }

nr=n;
    Graf g(n, n*(n+1)/2);

for(int i=1;i<=n-1;i++)
for(int j=i+1;j<=n;j++)
{
    g.adaugamuchie(i, j, distanta(&cuvinte[i],&cuvinte[j]));
}

g.kruskal();


    return 0;

}
