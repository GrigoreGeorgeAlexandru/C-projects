#include <iostream>
#include <fstream>
#include <queue>

using namespace std;



int romeo[102][102],julieta[102][102];

int p1[8] = {-1,0,1,-1,1,-1,0,1};
int p2[8] = {-1,-1,-1,0,0,1,1,1};

queue<pair<int,int>> q;
int n,m,rx,ry,jx,jy;

void bfs(int mx[102][102],int a,int b)
{
    int x2,y2,i;
    q.push({a, b});
    while (!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for (i = 0; i<8; i++)
        {
            x2=x+p1[i];
            y2=y+p2[i];

            if (x2>=1&&x2<=n&&y2>=1&&y2<=m)
                if (mx[x2][y2]==0)
                {
                    mx[x2][y2]=mx[x][y]+1;
                    q.push({x2, y2});
                }
        }
    }
}
int main()
{
    ifstream f("rj.in");
    ofstream g("rj.out");

    char harta[101];
    f>>n>>m;
    f.get();
    int i,j;
    for(i=1; i<=n; i++)
    {
        f.getline(harta,101);
        for (j=0; j<m; j++)
        {
            if (harta[j]=='R')
            {
                romeo[i][j+1]=1;
                rx=i;
                ry=j+1;
            }
            else if (harta[j]=='J')
            {
                julieta[i][j+1]=1;
                jx=i;
                jy=j+1;
            }
            else if (harta[j]=='X')
            {
                romeo[i][j+1]=-1;
                julieta[i][j+1]=-1;
            }
        }
    }

    bfs(romeo, rx, ry);
    bfs(julieta, jx, jy);
    int sol=10001;
    int fx=0,fy=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            if (romeo[i][j]==julieta[i][j]&&julieta[i][j]<sol&&julieta[i][j]>0)
            {
                sol=romeo[i][j];
                fx=i;
                fy=j;
            }
        }
    g<<sol<<" "<<fx<<" "<<fy;
    return 0;
}
