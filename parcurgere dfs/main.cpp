#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <int> vecin[100001];
int vizitat[100001];
int nr=1;
void dfs(int a)
{
    vizitat[a]=1;
    for(int i=0;i<vecin[a].size();i++)
        if(vizitat[vecin[a][i]]==0)
        dfs(vecin[a][i]);




}




int main()
{ int n,m;int c=0;
ifstream f("dfs.in");
ofstream g("dfs.out");
    f>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {f>>x>>y;
    vecin[x].push_back(y);
    vecin[y].push_back(x);
  }
    for(int i=1;i<=n;i++)
        if(vizitat[i]==0)
        {c++;


            dfs(i);
        }




g<<c;
return 0;

}
