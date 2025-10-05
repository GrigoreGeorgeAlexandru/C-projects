#include <bits/stdc++.h>

using namespace std;


int n;
int a[1000][1000];
vector<int> graph[1000];

int cap[1000][1000];
int precedent[1000], visitat[1000];

int total;
ifstream f("croco.in");
ofstream g("croco.out");

void dfs(int node)
{
    visitat[node] = true;
    for(auto next : graph[node])
    {
        if(cap[node][next] && !visitat[next])
        {
            dfs(next);
        }
    }
}
bool bfs(int start, int ending)
{
    for(int i = 1; i <= n; i++)
    {
        precedent[i] = 0;
    }

    queue<int> q;
    precedent[start] = start;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        if(node == ending) return true;

        for(auto &nxt : graph[node])
        {
            if(!precedent[nxt] && cap[node][nxt])
            {
                precedent[nxt] = node;
                q.push(nxt);
            }
        }
    }

    return false;
}

int flow(int start, int ending, int best)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cap[i][j] = a[i][j];
        }
    }

    int maxi = 0;
    while(bfs(start, ending) && maxi < best)
    {
        for(auto x : graph[ending])
        {
            if(precedent[x] != 0 && cap[x][ending])
            {
                precedent[ending] = x;

                int curent = INT_MAX;
                for(int i = ending; i != start && curent != 0; i = precedent[i])
                {
                    curent = min(curent, cap[precedent[i]][i]);
                }
                for(int i = ending; i != start && curent != 0; i = precedent[i])
                {
                    cap[precedent[i]][i] -= curent;
                    cap[i][precedent[i]] += curent;
                }

                maxi += curent;
            }
        }
    }

    return maxi;
}



int taietura()
{
    int ans = INT_MAX;

    for(int i = 2; i <= n; i++)
    {
        int current = flow(1, i, ans);

        if(current < ans)
        {
            ans = current;
            for(int j = 1; j <= n; j++)
            {
                visitat[j] = false;
            }
            dfs(1);
        }
    }

    return ans;
}

int main()
{
    f >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f >> a[i][j];
            total += a[i][j];

            if(a[i][j])
            {
                graph[i].push_back(j);
            }
        }
    }
    total /= 2;

    g << total - taietura() << ' ';

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt += visitat[i];
    }

    g << cnt << '\n';

    for(int i = 1; i <= n; i++)
    {
        if(visitat[i])
        {
            g << i << ' ';
        }
    }
}
