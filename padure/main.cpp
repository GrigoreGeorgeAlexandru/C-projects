#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

int d1[4] = {-1, 0, 1, 0};
int d2[4] = {0, 1, 0, -1};
int padure[1001][1001];
int cost[1001][1001];
deque <pair<int, int> > current;

void bfs()
{
    while(!current.empty())
    {
        int x=current.front().first;
        int y=current.front().second;
        current.pop_front();
        for(int i=0; i<4; i++)
        {
            int  a=x+d1[i];
            int  b=y+d2[i];

//            cout<<x<<" "<<y<<endl;
//cout<<a<<" "<<b<<endl;
            if(padure[x][y]==padure[a][b]&&cost[x][y]<cost[a][b])
            {
                cost[a][b]=cost[x][y];

                current.push_front({a,b});
            }

            else if(padure[x][y]!=padure[a][b]&&cost[x][y]+1<cost[a][b])
            {
                cost[a][b]=cost[x][y]+1;
                current.push_back({a,b});

            }
//            cout<<x<<" "<<y<<endl;
//cout<<a<<" "<<b<<endl;
        }
    }
}


int main()
{
    ifstream f("padure.in");
    ofstream g("padure.out");
    int n,m,pl,pc,cl,cc;
    f>>n>>m>>pl>>pc>>cl>>cc;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            f>>padure[i][j];
            cost[i][j]=1001;
        }
    current.push_front({pl,pc});
    cost[pl][pc]=0;
    bfs();
    g<<cost[cl][cc];
}
