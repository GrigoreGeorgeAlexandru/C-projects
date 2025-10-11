
#include<fstream>

using namespace std;

ifstream fin("curatenie.in");
ofstream fout("curatenie.out");

int i, n, nr, p[500001], a[500001], l[500001], r[500001];

void build(int nod, int x, int y)
{
    int poz = p[nod];
    if(poz > x)
    {
        l[nod] = a[++nr];
        build(l[nod], x, poz-1);
    }
    if(poz < y)
    {
        r[nod] = a[++nr];
        build(r[nod], poz+1, y);
    }
}
int main()
{int x;
    fin>>n;
    for(i=1;i<=n;++i)
    {
        fin>>x;
        p[x] = i;
    }

    for(i=1;i<=n;++i)
        fin>>a[i];

    build(a[1], 1, n);

    for(i=1;i<=n;++i)
        fout<<l[i]<<' '<<r[i]<<'\n';

    return 0;
}
