#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int NMAX = 1e5 + 11;
const int AMAX = 10;

struct segtree
{
    int        n;
    vector<vi> t;

    segtree() {}
    segtree(int n) : n(n) { t.resize(4 * n); }

    void build(vi a[]) { build_util(a, 1, 0, n - 1); }
    void build_util(vi a[], int v, int tl, int tr)
    {
        if (tl == tr)
        {
            sort(a[tl].begin(), a[tl].end());
            t[v] = a[tl];
            if (AMAX < (int)t[v].size())
                t[v].resize(10);
        }
        else
        {
            int tm = (tl + tr) >> 1;
            build_util(a, v << 1, tl, tm);
            build_util(a, (v << 1) + 1, tm + 1, tr);

            t[v].resize(t[v << 1].size() + t[(v << 1) + 1].size());
            merge(t[v << 1].begin(),
                  t[v << 1].end(),
                  t[(v << 1) + 1].begin(),
                  t[(v << 1) + 1].end(),
                  t[v].begin());
            if (AMAX < (int)t[v].size())
                t[v].resize(10);
        }
    }

    vi query(int u, int v) { return query_util(1, 0, n - 1, u, v); }

    vi query_util(int v, int tl, int tr, int ql, int qr)
    {
        if (ql > qr)
            return vi();
        if (tl == ql and tr == qr)
            return t[v];

        int tm   = (tl + tr) >> 1;
        vi  lans = query_util(v << 1, tl, tm, ql, min(tm, qr));
        vi  rans = query_util((v << 1) + 1, tm + 1, tr, max(tm + 1, ql), qr);

        vi ans(lans.size() + rans.size());

        merge(lans.begin(), lans.end(), rans.begin(), rans.end(), ans.begin());

        return ans;
    }
} st;

vi  g[NMAX];
vi  population[NMAX];
int parent[NMAX], depth[NMAX];
int heavy[NMAX], pos[NMAX], head[NMAX], hldcnt;

int dfs(int u)
{
    int usz, vsz, msz;
    usz = 1;
    msz = 0;

    for (auto v : g[u])
    {
        if (parent[u] == v)
            continue;

        parent[v] = u;
        depth[v]  = depth[u] + 1;
        vsz       = dfs(v);
        usz += vsz;

        if (vsz > msz)
        {
            heavy[u] = v;
            msz      = vsz;
        }
    }

    return usz;
}

void decompose(int u, int h)
{
    head[u] = h;
    pos[u]  = hldcnt++;

    if (heavy[u] != -1)
        decompose(heavy[u], h);
    for (auto v : g[u])
    {
        if (parent[u] != v and heavy[u] != v)
            decompose(v, v);
    }
}

void query(int u, int v, int a)
{
    int n;
    vi  ans, cur;

    while (head[u] != head[v])
    {
        if (depth[head[u]] > depth[head[v]])
            swap(u, v);

        cur = st.query(pos[head[v]], pos[v]);
        v   = parent[head[v]];

        n = ans.size();
        ans.resize(n + cur.size());
        copy(cur.begin(), cur.end(), ans.begin() + n);
        inplace_merge(ans.begin(), ans.begin() + n, ans.end());
    }

    if (depth[u] > depth[v])
        swap(u, v);

    cur = st.query(pos[u], pos[v]);
    n   = ans.size();
    ans.resize(n + cur.size());
    copy(cur.begin(), cur.end(), ans.begin() + n);
    inplace_merge(ans.begin(), ans.begin() + n, ans.end());

    int k = min(a, (int)ans.size());

    cout << k << " ";

    for (int i = 0; i < k; ++i)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}

void reset(void)
{
    hldcnt = 0;
    memset(heavy, -1, NMAX * sizeof(*heavy));
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, u, v, ci, a;

    cin >> n >> m >> q;

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    reset();
    dfs(0);
    decompose(0, 0);

    for (int i = 0; i < m; ++i)
    {
        cin >> ci;
        population[pos[ci - 1]].push_back(i);
    }

    st = segtree(n);
    st.build(population);

    while (q--)
    {
        cin >> u >> v >> a;
        query(u - 1, v - 1, a);
    }

    return 0;
}
