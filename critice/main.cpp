#include <bits/stdc++.h>

using namespace std;

vector<int> vec[10001];
int c[10001][10001];
int f[10001][10001];
int qu[10001];
int is[2][10001];
int sol[100001];
int visited[10001];
int st[100001];
int dr[100001];
int t[10001];
int N,M;

int bfs()
{
    int i,x,y,inc,sf;

    memset(t, 0, sizeof(t));
    inc = sf = 0;
    qu[0] = 1;
    while(inc <= sf)
    {
        x = qu[inc++];
        for(i = 0; i < vec[x].size(); ++i)
        {
            y = vec[x][i];
            if(!t[y] && f[x][y] < c[x][y])
            {
                qu[++sf] = y;
                t[y] = x;
            }
        }
    }

    return t[N];
}

void cale(int S, int l)
{
    int i,x,y,inc,sf,sgn=1;

    memset(visited, 0, sizeof(visited));
    if(l) sgn = -1;
    is[l][S] = 1;
    inc = sf = 0;
    qu[0] = S;
    while(inc <= sf)
    {
        x = qu[inc++];
        for(i = 0; i < vec[x].size(); ++i)
        {
            y = vec[x][i];
            if(!visited[y] && sgn * f[x][y] >= 0 && abs(f[x][y]) < c[x][y])
            {
                is[l][y] = visited[y] = 1;
                qu[++sf] = y;
            }
        }
    }
}

int main(){

 ifstream fin("critice.in");
 ofstream gout("critice.out");
    int i,j,x,y,z,r,cnt=0;

   fin>>N>>M;
    for(i = 1; i <= M; ++i)
    {
      fin>>x>>y>>z;
        st[i] = x; dr[i] = y;
        c[x][y] = c[y][x] = z;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    while(bfs())
        for(i = 0; i < vec[N].size(); ++i)
        {
            x = vec[N][i];
            if(!t[x] || c[x][N] == f[x][N]) continue;

            r = c[x][N] - f[x][N];
            for(j = x; j > 1; j = t[j]) r = min(r, c[ t[j] ][j] - f[ t[j] ][j]);
            if(!r) continue;

            f[x][N] += r;
            f[N][x] -= r;
            for(j = x; j > 1; j = t[j])
            {
                f[ t[j] ][j] += r;
                f[j][ t[j] ] -= r;
            }
        }

    cale(1,0);
    cale(N,1);
    for(i = 1; i <= M; ++i)
    {
        x = st[i];
        y = dr[i];
        if(f[x][y] < 0) swap(x,y);
        if(f[x][y] == c[x][y])
            if(is[0][x] && is[1][y]) ++cnt, sol[i] = 1;
    }
gout<<cnt<<"\n";

    for(i = 1; i <= M; ++i)
        if(sol[i])gout<<i<<"\n";


    return 0;
}
