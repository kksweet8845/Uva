#include <cstdio>
#include <vector>
using namespace std;

int Root[100010];
vector<int> Set[100010];

void Set_Initial(int N);
void Union(int x, int y);

int main()
{
    int N, M, Command;
    int x , y;
    while (scanf("%d %d", &N, &M) != EOF) {
        Set_Initial(N);
        while (M--) {
            scanf("%d", &Command);
            if (Command == 1) {
                scanf("%d %d", &x, &y);
                Union(x, y);
            }
            else if (Command == 2) {
                scanf("%d %d", &x, &y);
                if (Root[x] == Root[y]) continue;

                auto iter = Set[Root[x]].begin();
                while (*iter != x) ++iter;
                Set[Root[x]].erase(iter);

                Set[Root[y]].push_back(x);
                Root[x] = Root[y];
            }
            else if (Command == 3) {
                scanf("%d", &x);
                int Sum = 0;
                for (int &n : Set[Root[x]])
                    Sum += n;
                printf("%d %d\n", Set[Root[x]].size(), Sum);
            }
        }
    }
}
void Set_Initial(int N)
{
    for (int i = 1; i <= N; ++i) {
        Root[i] = i;
        Set[i].clear();
        Set[i].push_back(i);
    }
}
void Union(int x, int y)
{
    x = Root[x];
    y = Root[y];
    if (x == y) return;

    if (Set[x].size() >= Set[y].size()) {
        for (int &n : Set[y]) {
            Set[x].push_back(n);
            Root[n] = x;
        }
        Set[y].clear();
    }
    else {
        for (int &n : Set[x]) {
            Set[y].push_back(n);
            Root[n] = y;
        }
        Set[x].clear();
    }
}
