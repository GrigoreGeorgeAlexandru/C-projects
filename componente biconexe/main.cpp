#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;



ifstream f("biconex.in");
ofstream g("biconex.out");

int m,x,y;

int n,nivel[100001],nma[100001],viziat[100001],stiva[100001],counter,nr;
vector <int> vecin[100001],Componente[100001];

void dfs(int nod, int parinte)
{
    viziat[nod]=1;nivel[nod]=nivel[parinte]+1;
    nma[nod]=nivel[nod];
    stiva[++counter]=nod;
    for(auto i : vecin[nod])
    {
        if(i!=parinte)
        if(viziat[i])
            nma[nod]=min(nma[nod],nivel[i]);
        else
        {


            dfs(i,nod);

nma[nod]=min(nma[nod],nma[i]);

            if(nma[i]>=nivel[nod])
            {
                ++nr;
                while(counter && stiva[counter]!=i)
                    Componente[nr].push_back(stiva[counter--]);
                Componente[nr].push_back(stiva[counter--]);
                Componente[nr].push_back(nod);
            }

        }
    }
}

int main()
{

    f>>n>>m;
    for(int i=1; i<=m; i++)
    {
        f>>x>>y;
        vecin[x].push_back(y);
        vecin[y].push_back(x);
    }
    dfs(1,0);
    g<<nr<<"\n";
    for(int i=1; i<=nr; ++i)
    {
        for(auto j : Componente[i]) g<<j<<" ";
        g<<"\n";
    }
    return 0;
}
