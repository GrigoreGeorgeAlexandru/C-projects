#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int n,m,k;
char labyrinth[1001][1001];
int cost[1001][1001];
queue<pair<int, int> > current;


int check(int x,int y)
{


    if(x<=n&&x>=1&&y<=m&&y>=1&&labyrinth[x][y]=='.')
    {
        return 1;
    }
    return 0;

}


void  bfs()
{
    while (!current.empty())
    {
        int x=current.front().first;
        int y=current.front().second;


        if(check(x+1,y))
        {
            cost[x+1][y]=cost[x][y]+1;
            labyrinth[x+1][y]='#';
            current.push({x+1,y});

        }
        if(check(x-1,y))
        {
            cost[x-1][y]=cost[x][y]+1;
            labyrinth[x-1][y]='#';

            current.push({x-1,y});

        }
        if(check(x,y+1))
        {
            cost[x][y+1]=cost[x][y]+1;
            labyrinth[x][y+1]='#';

            current.push({x,y+1});

        }
        if(check(x,y-1))
        {
             cost[x][y-1]=cost[x][y]+1;
            labyrinth[x][y-1]='#';

            current.push({x,y-1});

        }

        current.pop();




    }

}

int main()
{
    ifstream f("date.in");

    f>>n>>m>>k;


    for(int i=1; i<=n; i++)
    {

        for(int j=1; j<=m; j++)
        {
            f>>labyrinth[i][j];

        }
    }
    int x,y;

    while(k--)
    {
        f>>x>>y;
        labyrinth[x][y]='#';
        current.push({x,y});

    }


    bfs();


    int sum=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
                sum+=cost[i][j];

//    for(int i=1; i<=n; i++)
//        {for(int j=1; j<=m; j++)
//        cout<<labyrinth[i][j]<<" ";
//        cout<<endl;
//
//
//        }

    cout<<sum;
    return 0;
}
