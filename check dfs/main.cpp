#include <iostream>
#include <vector>
#include <fstream>
#include<algorithm>
using namespace std;

vector <int>  solution;
int visited[100001];int positions[100001];
vector <int> neighbours[100001];
int check(int nr1,int nr2)
{
    return positions[nr1]<positions[nr2];
}

void dfs(int node)
{solution.push_back(node);
visited[node]=1;
for(auto n:neighbours[node])
    if(visited[n]==0)
    dfs(n);

}


int main()
{
    ifstream f("date.in");

    int n,m;
    f>>n>>m;

    int a1,a2;
    int nodes[n+1];


    for(int i=1; i<=n; i++)
    {

        f>>nodes[i];
        positions[nodes[i]]=i;

    }



    for(int i=1; i<=m; i++)
    {
        f>>a1>>a2;
        neighbours[a1].push_back(a2);
        neighbours[a2].push_back(a1);
    }
for(int i=1; i<=n; i++)
sort(neighbours[i].begin(),neighbours[i].end(),check);
dfs(nodes[1]);

//for(int i=1; i<=n; i++)cout<<nodes[i]<<" "<<solution[i-1]<<endl;



    for(int i=1; i<=n; i++)
    {
        if(nodes[i]!=solution[i-1])

        {


            cout<<0;
            return 0;
        }



    }
    cout<<1;
    return 0;


}
