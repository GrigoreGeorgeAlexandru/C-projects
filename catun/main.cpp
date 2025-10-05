#include <fstream>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

ifstream fin ("catun.in");


int n, d[1000], fort[1000];
vector <pair <int, int>> G[1000];
priority_queue <pair <int, int>> q;

void Dijkstra()
{
    while(!q.empty())
    {
        int nod = q.top().second;
       // cout<<nod<<" ";
       // cout<<endl;
        q.pop();

        for(int i = 0; i < G[nod].size(); ++i)
        {
            int next = G[nod][i].first;
            int cost = G[nod][i].second;
            if(d[nod]+cost<d[next])
            {
                d[next]=d[nod]+cost;
                q.push(make_pair(-d[next], next));
                fort[next]=fort[nod];
            }
            else if(d[nod]+cost==d[next]&&fort[next]>fort[nod])

                fort[next]=fort[nod];
        }
    }
}

int main()
{
    int m, k,x;
    fin>>n>>m>>k;
    for(int i=1; i<=n;++i)
        d[i]=INT_MAX;
    for(int i=1;i<=k; ++i)
    {
        fin>>x;
        q.push(make_pair(0, x));
        fort[x] = x;
        d[x] = 0;
    }
    int y,c;
    for(int i=1;i<=m;++i)
    {
        fin>>x>>y>>c;
        G[x].push_back(make_pair(y, c));
        G[y].push_back(make_pair(x, c));
    }

    Dijkstra();

    for(int i = 1; i <= n; ++i)
        if(fort[i] == 0 || fort[i] == i) cout << "0 ";
        else cout << fort[i] << " ";

    return 0;
}
