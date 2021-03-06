// dfs to look for back edges
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vb = vector<bool>;

const int NMAX = 1e5 + 11;

int n, m;
vi  g[NMAX], ans;

bool dfs(int u, vi &tin, int &cur_time, int start_time)
{
    if (tin[u] > start_time)
    {
        ans.push_back(u);
        return true;
    }
    tin[u] = ++cur_time;

    for (auto v : g[u])
    {
        if (dfs(v, tin, cur_time, start_time))
        {
            if (tin[u] >= tin[ans.front()])
                ans.push_back(u);
            return true;
        }
    }
    tin[u] = start_time;
    return false;
}

bool has_cycle(void)
{
    vi  tin(n + 1, 0);
    int cur_time, start_time = 1;

    for (int u = 1; u <= n; ++u)
    {
        cur_time = start_time;
        if (tin[u] == 0 and dfs(u, tin, cur_time, start_time))
            return true;
        start_time = cur_time;
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int u, v;

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    if (has_cycle())
    {
        cout << ans.size() << endl;
        for_each(ans.rbegin(), ans.rend(), [](int x) { cout << x << " "; }),
            cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
