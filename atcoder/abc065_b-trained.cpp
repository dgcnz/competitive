#include <bits/stdc++.h>

using namespace std;

int const NMAX = 1e5 + 11;

int  n, succ[NMAX];
bool vis[NMAX];

int dfs(int u)
{
    if (u == 1)
        return 0;
    int ans = -1;
    int v   = succ[u];

    vis[u] = true;
    if (not vis[v])
        ans = dfs(v);
    if (ans != -1)
        ++ans;

    return ans;
}

int main(void)
{
    int n;

    cin >> n;

    for (int u = 0; u < n; ++u)
        cin >> succ[u], --succ[u];

    cout << dfs(0) << endl;
    return 0;
}
