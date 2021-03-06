#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size();

using namespace std;
using ll = long long;
using vi = vector<int>;

int const NMAX = 1e5 + 11;

int n;
ll  val[NMAX];
vi  g[NMAX];

array<ll, 2> dfs(int u, int p)
{
    // 0 : increase, 1 : decrease
    array<ll, 2> ans = {0, 0};
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        auto cur = dfs(v, u);
        ans      = {max(ans[0], cur[0]), max(ans[1], cur[1])};
    }

    val[u] += ans[0] - ans[1];
    ans[val[u] >= 0] += abs(val[u]);
    val[u] = 0;
    return ans;
}

int main(void)
{
    int u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        cin >> val[i];

    auto ans = dfs(1, -1);
    cout << accumulate(all(ans), 0LL) << endl;

    return 0;
}
