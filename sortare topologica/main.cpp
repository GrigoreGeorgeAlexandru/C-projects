#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <int> vecin[50002];
int vizitat[50002];
int nr=1;
int sol[50002];
void dfs(int a)
{
    vizitat[a]=1;
    for(int i=0;i<vecin[a].size();i++)
        if(vizitat[vecin[a][i]]==0)
        dfs(vecin[a][i]);

sol[nr]=a;
nr++;



}




int main()
{ int n,m;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
    f>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {f>>x>>y;
    vecin[x].push_back(y);
  }
    for(int i=1;i<=n;i++)
        if(vizitat[i]==0)
        dfs(i);





for(int i=n;i>0;i--)
    g<<sol[i]<<" ";
return 0;

}
