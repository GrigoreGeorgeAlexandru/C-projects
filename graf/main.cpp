#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


vector<int> vecin[14001], sol;
int distantax[14001], distantay[14001], frecventa[14001];
int n, m, n1, n2;
queue<int> q;
void bfs(int nod,int distanta[])
{

    distanta[nod]=0;
    q.push(nod);
    while (!q.empty())
    {
        int nod_curent=q.front();
        q.pop();
        for (auto i : vecin[nod_curent])
        {

            if (distanta[i]==-1)
            {
                distanta[i] = distanta[nod_curent] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ifstream f("graf.in");
    ofstream g("graf.out");
    int i, j, x, y;
    f>>n>>m>>x>>y;
    for (i=1; i<=m; i++)
    {
        f>>n1>>n2;
        vecin[n1].push_back(n2);
        vecin[n2].push_back(n1);
    }
for (i =1; i<=n; i++)
    {distantax[i]=-1;

    distantay[i]=-1;
}
    bfs(x, distantax);
    bfs(y, distantay);

    for (i=1; i<=n; i++)
        if (distantax[i]+distantay[i]==distantax[y])
            frecventa[distantax[i]]++;



    for (i =1; i<=n; i++)

        if (distantax[i]+distantay[i]==distantax[y]&&frecventa[distantax[i]]==1)
            sol.push_back(i);
    g <<sol.size()<< endl;
    for (i =0; i<sol.size(); i++)
    {
        g <<sol[i]<<" ";
    }

    return 0;
}
