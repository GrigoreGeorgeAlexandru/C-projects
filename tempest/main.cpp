#include <bits/stdc++.h>


using namespace std;

ifstream f("tempest.in");
ofstream g("tempest.out");

vector<pair<int, int>> vecin[100010];
long long d[100010], ma;
int indice[200010];
vector<int> puncte_plecare;
priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > Coada;

void Dijkstra(int i)
{

    d[i] = 0;
    Coada.push(make_pair(0, i));

    int varf;
    while (!Coada.empty())
    {
        varf = Coada.top().second;



        Coada.pop();

        for (pair<int, int> e : vecin[varf])
        {
            int vecin = e.first;
            int c = e.second;

            if (d[varf] + c < d[vecin])
            {
                d[vecin] = d[varf] + c;
                Coada.push(make_pair(d[vecin], vecin));
            }


        }
    }
}

int main()
{
    int t, x, y, time;
    int N, M, S, D, K;

    f >> t;
    for (int i = 1; i <= t; i++)
    {

        f >> N >> M >> S >> D;
        for (int i = 1; i <= N; i++)
            vecin[i].clear();

        for (int i = 1; i <= M; i++)
        {

            f >> x >> y >> time;
            vecin[x].push_back(make_pair(y, time));
            vecin[y].push_back(make_pair(x, time));
            indice[i] = time;

        }

        f >> K;
        ma = 0;

        for (int i = 1; i <= K; i++)
        {
            f >> x;
            ma += 1LL * indice[x];
        }

        for (int i = 1; i <= N; i++)
        {
            d[i] = 1LL * 1 << 61;
        }

        Dijkstra(D);

        for (int i = 1; i <= N; i++)
        {
            if (d[i] <= ma)
                puncte_plecare.push_back(i);
        }

        g << puncte_plecare.size() << "\n";

        for (auto i : puncte_plecare)
        {
            g << i << " ";
        }
        g << "\n";
        puncte_plecare.clear();




    }
    return 0;
}
