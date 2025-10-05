#include <bits/stdc++.h>

using namespace std;
ifstream in("disconnect.in");
ofstream out("disconnect.out");
int n,m;
vector<int> graf[100005];
int nivel[100005], parinte[100005],vizitat[100005];

void dfs(int x, int i)
{
    nivel[x] = i;
    vizitat[x] = 1;
    for (auto it:graf[x]){
        if (!vizitat[it])
        {
            parinte[it] = x;
            dfs(it,i+1);
        }
    }
}
int radacina(int x)
{
    while (parinte[x] != -1)
        x = parinte[x];
    return x;
}
bool query(int x, int y)
{
    x--;y--;
    if (radacina(x) == radacina(y))
        return true;
    return false;
}
void removeEdge(int x, int y)
{
    x--;y--;
    if (nivel[x] < nivel[y])
        parinte[y] = -1;
    else
        parinte[x] = -1;
}
int main()
{
    in>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        in>>a>>b;
        a--;b--;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int V = 0;
    memset(vizitat,0,sizeof(vizitat));
    dfs(0,0);
    parinte[0] = -1;
    for (int i = 0; i < m; ++i) {
        int type, x, y;
        in >> type >> x >> y;

        int a = x ^ V;
        int b = y ^ V;

        if (type == 1) {
            removeEdge(a, b);
        } else
            if (query(a, b)) {
                out << "YES\n";
                V = a;
            } else {
                out << "NO\n";
                V = b;
            }
    }
    return 0;
}
