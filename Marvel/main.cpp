#include <bits/stdc++.h>

using namespace std;



bool vizitat[100002];
int d[100002], v[100002], frec[100002], val[100002], nr[100002];
int p, l, n;
vector <int> lista[100002], sol;
 ifstream f("marvel.in");
ofstream g("marvel.out");
void dfs(int nod)
{
    vizitat[nod] = 1;

    for(auto vecin : lista[nod])
        if(!vizitat[vecin])
            dfs(vecin);

    frec[++ l] = nod;
}

int main()
{
    int x, y, m, i, k;

    f >> n >> m >> k >> p;
    for(i = 1; i <= n; i ++)
        f >> val[i];
    for(i = 1; i <= p; i ++)
        f >> nr[i];

    while(m--)
    {
        f >> x >> y; //!
        lista[x].push_back(y);
    }

    for(i = 1; i <= n; i ++)
        if(!vizitat[i])
            dfs(i);

    for(i = n; i>0; --i)
    {
        int flag;
        if (val[frec[i]] == nr[1])
            flag = 1;
        else flag = 0;

        d[frec[i]] = max(d[frec[i]], flag);

        for(auto vecin : lista[frec[i]])
            if(val[vecin] == nr[d[frec[i]] + 1])
                d[vecin] = max(d[vecin], d[frec[i]] + 1);

            else d[vecin] = max(d[vecin], d[frec[i]]);
    }

    for(i = 1; i <= n; i ++)
        if(d[i] >= p)
            sol.push_back(i);

    g << sol.size()<<"\n";

    for(auto it : sol) g << it << " ";

    return 0;
}
