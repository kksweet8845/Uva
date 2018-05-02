#include <cstdio>
using namespace std;
#define Inf 9999999

struct Edge{
    int P;
    int Q;
}E[10005];
int nOfE;
int Dis[101];

void Initial(const int &N, const int &S);
void Input();
void BellmanFord(const int &N);
void Relax(const Edge &E);
void Find_Longest_Path(const int &N, int &Min, int &pos);

int main()
{
    int N, S, Case = 1;
    while (scanf("%d", &N) && N)
    {
        scanf("%d", &S);
        nOfE = 0;
        Initial(N, S);

        Input();

        BellmanFord(N);

        int Min = 0, pos;
        Find_Longest_Path(N, Min, pos);

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
               Case++, S, -Min, pos);
    }
}
void Initial(const int &N, const int &S)
{
    for (int i = 1; i <= N; ++i)
        Dis[i] = Inf;
    Dis[S] = 0;
}
void Input()
{
    while (scanf("%d %d", &E[nOfE].P, &E[nOfE].Q)) {
        if (E[nOfE].P == 0 && E[nOfE].Q == 0)
            break;
        ++nOfE;
    }
}
void BellmanFord(const int &N)
{
    for (int time = 0; time < N - 1; ++time)
        for (int i = 0; i < nOfE; ++i)
            Relax(E[i]);
}
void Relax(const Edge &E)
{
    int p = E.P;
    int q = E.Q;
    if (Dis[p] - 1 < Dis[q])
        Dis[q] = Dis[p] - 1;
}
void Find_Longest_Path(const int &N, int &Min, int &pos)
{
    for (int i = 1; i <= N; ++i)
    if (Dis[i] < Min) {
        Min = Dis[i];
        pos = i;
    }
}
