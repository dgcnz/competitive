#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using vii = vector<ii>;

const int NMAX = 1e5 + 11;

int n, root, t[NMAX], sz[NMAX], dist[NMAX];
ll  tsum[NMAX], ans[NMAX];
vii g[NMAX];

void precompute(int u, int p)
{
    sz[u]   = 1;
    tsum[u] = t[u];

    for (auto [v, w] : g[u])
    {
        if (v == p)
            continue;

        dist[v] = dist[u] + w;
        precompute(v, u);
        sz[u] += sz[v];
        tsum[u] += tsum[v];
    }
}

void calc_reroot(int u, int p, ll dist_sum, ll tax_dist_sum)
{
    ans[u] = t[u] * dist_sum + tax_dist_sum;
    for (auto [v, w] : g[u])
    {
        if (v == p)
            continue;
        calc_reroot(v,
                    u,
                    dist_sum + w * (n - 2 * sz[v]),
                    tax_dist_sum + w * (tsum[root] - 2 * tsum[v]));
    }
}

int main(void)
{
    int u, v, w;
    ll  dist_sum, tax_dist_sum;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];

    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    root = 1;
    precompute(root, 0);

    tax_dist_sum = dist_sum = 0;
    for (int u = 1; u <= n; ++u)
    {
        dist_sum += dist[u];
        tax_dist_sum += (ll)t[u] * dist[u];
    }

    calc_reroot(root, 0, dist_sum, tax_dist_sum);

    for (int u = 1; u <= n; ++u)
        cout << ans[u] << endl;

    return 0;
}
