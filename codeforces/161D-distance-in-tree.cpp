#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using vi = vector<int>;

int const NMAX = 5e4 + 11;
int const KMAX = 5e2 + 11;

int n, k, dp[NMAX][KMAX], cnt;
vi  g[NMAX];

void dfs(int u, int p = -1)
{
    dp[u][0] = 1;
    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
            for (int i = 1; i <= k; i++)
                cnt += dp[v][i - 1] * dp[u][k - i];
            for (int i = 1; i <= k; i++)
                dp[u][i] += dp[v][i - 1];
        }
    }
}

int main(void)
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << cnt << endl;
    return 0;
}
