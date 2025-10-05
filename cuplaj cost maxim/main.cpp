#include <bits/stdc++.h>
using namespace std;


int cost[1000][1000], F[1000][1000], C[1000][1000],muchie[1000][1000];
int distanta[1000], TT[1000],muchisolutie[1000];
int S, D, N, M, K;
vector<int> G[1000];
int L, Q;
ifstream f("cmcm.in");
ofstream g("cmcm.out");

int bellmanford()
{
    int use[1000];
    for(int i = 1 ; i <= N + 1; i++)
    {
        distanta[i] = INT_MAX;
        TT[i] = -1;
        use[i] = 0;
    }
    distanta[S] = 0;
    use[1] = 1;
    queue <int> q;
    q.push(S);

    while( !q.empty())
    {
        int x = q.front();
        q.pop();
        for(int j = 0; j <G[x].size(); j++)
        {
            int nod = G[x][j];

            if(distanta[x] + cost[x][nod] < distanta[nod] && C[x][nod] - F[x][nod] > 0)
            {
                distanta[nod] = distanta[x] + cost[x][nod];
                TT[nod] = x;

                if(!use[nod])
                {
                    q.push(nod);
                    use[nod] = 1;
                }
            }
        }
        use[x] = 0;
    }

    if(distanta[D] < INT_MAX)
    {

        for(int i =  D; i != S; i = TT[i])
        {
            F[TT[i]][i] += 1;
            F[i][TT[i]] -= 1;
        }

        return distanta[D] ;

    }
    return 0;
}

int flux()
{
    int improve = 1, rez = 0;
    while(improve)
    {
        improve =  bellmanford();
        rez += improve;

    }
    return rez;
}
int main()
{
    f >>L>>Q>> M;
    N = L + Q + 1;
    D = N + 1;
    S = 1;
    for(int i = 1; i <= M ; i++)
    {
        int x, y, c;

        f >>x >>y >>c;

        y += L + 1;
        x++;

        G[x].push_back(y);
        G[y].push_back(x);

        muchie[x][y] = i;

        cost[x][y] = c;
        cost[y][x] = -c;

        C[x][y] = 1;

    }
    for(int i = 2; i <= L + 1; i++)
    {
        G[S].push_back(i);
        G[i].push_back(S);
        C[S][i] = 1;
    }
    for(int i = L + 2; i <= N ; ++i)
    {
        G[D].push_back(i);
        G[i].push_back(D);
        C[i][D] = 1;
    }

    int solutie = flux();

    for(int i = 2; i <= L + 1; i++)
        for(int j = L + 2; j <= N ; j++ )
            if(C[i][j] && F[i][j])
            {
                muchisolutie[++K] = muchie[i][j];
                break;
            }

    g <<K <<" " << solutie <<'\n';
    for(int i = 1; i <= K ; i++)
        g << muchisolutie[i] <<" ";

    return 0;

}
