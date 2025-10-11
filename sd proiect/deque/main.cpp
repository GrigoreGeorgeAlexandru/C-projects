#include<fstream>
#include<stack>
#define N 5000013
using namespace std;
ifstream fin("deque.in");
ofstream fout("deque.out");
int dq[N];
int v[N];
int main(){
    int n, k, i, ul = 0, pr = 1;
    long long suma = 0;
    fin >> n >> k;
    for (i = 1; i <= n; i++)fin >> v[i];

    for (i = 1; i <= n; i++) {
        while (pr <= ul && v[i] <= v[dq[ul]])ul--;//cautam la fiecare pas cel mai mic element, prin urmare le baza dq va fi minimul
        dq[++ul] = i;
        if (dq[pr] == i - k)
            pr++;
        if (i >= k)suma += v[dq[pr]];
    }
    fout << suma;
    return 0;
}
