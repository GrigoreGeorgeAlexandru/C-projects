#include <bits/stdc++.h>

using namespace std;

int mn, i, j, n, mx, d[5010], v[5010], viz[5010], x[50100];

void dijkstra()
{
    int i, j, m, mini;
    for (i = 1; i <= mn; i++)
	{
        m = 2000000000;
        for (j = 0; j < mn; j++)
        {
			if (d[j] < m && viz[j] == 0)
			{
                m = d[j];
                mini = j;
            }
		}
        viz[mini] = 1;
        for (j = 1; j <= n; j++)
		{
			if (d[mini] + v[j] < d[(mini + v[j]) % mn])
			{
				d[(mini + v[j]) % mn] = d[mini] + v[j];
			}
		}
    }
}

int main()
{
    ifstream f("banuti.in");
    ofstream g("banuti.out");

    f>>n;
    mn = 2000000000;
    for (i = 1; i <= n; i++)
	{
        f>>x[i];
        if (x[i] < mn)
        {
			mn = x[i];
		}
    }

    for (i = 1; i <= n; i++)
    {
		if (d[x[i] % mn] == 0 || x[i] < d[x[i] % mn])
        {
			d[x[i] % mn] = x[i];
		}
    }

    n = 0;
    for (i = 0; i < mn; i++)
        if (d[i])
            v[++n] = d[i];
        else
            d[i] = 2000000000;

    dijkstra();

    mx = 0;
    for (i = 0; i < mn; i++)
	{
        if (d[i] > mx)
        {
			mx = d[i];
		}
    }

    if (mx == 2000000000)
    {
		g<<-1<<"\n";
	}
    else
    {
		g<< mx - mn;
	}

    return 0;
}
