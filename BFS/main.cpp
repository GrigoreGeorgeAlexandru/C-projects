#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int vizitat[100001];
queue <int> q;
vector <int> vecin[100001];
int sol[100001];
void bfs()
{
while(!q.empty())
{int x=q.front();

q.pop();
for(auto i:vecin[x])
    if(!vizitat[i])
        {
            vizitat[i]=1;
            sol[i]=sol[x]+1;
            q.push(i);
        }
}
}







int main()
{
    ifstream f("bfs.in");
    ofstream g("bfs.out");
    int n,m,s;
    f>>n>>m>>s;
    int x,y;
    for(int i=1;i<=n;i++)
        sol[i]=-1;
    for(int i=1;i<=m;i++)
    {
        f>>x>>y;
        vecin[x].push_back(y);
    }
 q.push(s);
 vizitat[s]=1;
sol[s]=0;
    bfs();

for(int i=1;i<=n;i++)
        g<<sol[i]<<" ";

}
