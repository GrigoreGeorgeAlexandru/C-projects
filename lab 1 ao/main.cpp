#include <iostream>
#include <fstream>

using namespace std;
int dp[100][100];
int ales[100]={0};
int main()
{
    fstream f("date.in");
    int g,val[100],w[100];
    f>>g;
    int q;
    f>>q;
    for(int i=1; i<=q; i++)
    {
        f>>val[i];

    }
    for(int i=1; i<=q; i++)
    {
        f>>w[i];

    }




    for(int i=1; i<=q; i++)
    {
        for(int j=1; j<=g; j++)
            if(j-w[i]>=0)
            {
                dp[i][j]=max(dp[i-1][j],(val[i]+dp[i-1][j-w[i]]));

            }
            else dp[i][j]=dp[i-1][j];
    }

//for(int i=1;i<=q;i++)
//    {for(int j=1;j<=g;j++)
//  cout<<dp[i][j]<<" ";
//  cout<<endl;
//    cout<<endl;
//
//    }

    int ans=dp[q][g];


    for(int i=q;i>0;i--)
    {
        if(ans!=dp[i-1][g])
        {
            ales[i]=1;
            ans -= val[i];
            g -= w[i];
        }


    }

    for(int i=1; i<=q; i++)
        cout<<ales[i]<<" ";

    return 0;

}
