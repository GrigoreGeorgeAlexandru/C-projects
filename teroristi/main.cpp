#include <bits/stdc++.h>



using namespace std;

ifstream f("teroristi.in");
ofstream g("teroristi.out");
vector<long> t, cr;
string cuvant;

long n, m, S, D, c[1000][1000], a[1000][1000], litere[1000], ind[1000][20000];

bool bfs()
{
    queue<long> Q;
    vector<int> s(D+1);
    t.assign(D+1, 0);
    cr.assign(D+1, 0);
    s[S] = 1;
    cr[S] = INT_MAX;
    Q.push(S);
    while (!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        for (int j = S; j <= D; ++j)
        {
            if (s[j])
            {
                continue;
            }
            if (c[i][j] > a[i][j])
            {
                cr[j] = min(cr[i], c[i][j] - a[i][j]);
                s[j] = true;
                t[j] = i;
                Q.push(j);
                if (j == D)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    f >> n >> m;
    f >> cuvant;
    for (int i = 0; i < cuvant.size(); ++i)
        litere[cuvant[i]-'a'+1]++;
    char lit1, lit2;
    int x, y;
    for (int i = 1; i <= m; ++i)
    {
        f >> lit1 >> lit2;
        x = lit1-'a'+ 1;
        y = lit2-'a'+ 1;
        if (y < x) swap(x,y);
        int nod = x*26 + y;
        litere[nod]++;
        ind[nod][litere[nod]] = i;
        c[x][nod] = INT_MAX;
        c[y][nod] = INT_MAX;
    }

    S = 0;
    D = 703;
    for (int i = 1; i <= 26; ++i)
        c[S][i] = litere[i];
    for (int i = 27; i <= 702; ++i)
        c[i][D] = litere[i];

    while (bfs())
    {
        int o, p;
        p = D;
        while (p != S)
        {
            o = t[p];
            a[o][p] += cr[D];
            a[p][o] -= cr[D];
            p = o;
        }
    }

    for (int i = 0; i < cuvant.size(); ++i)
    {
        int poz = cuvant[i] - 'a' + 1;
        for (int j = 27; j <= 702; ++j)
            if (a[poz][j])
            {
                g << ind[j][litere[j]] << ' ';

                litere[j]--;
                a[poz][j]--;

                break;
            }
    }

    return 0;
}
