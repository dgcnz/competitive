#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using vi = vector<int>;

int const NMAX = 10;

int    n, m, diff[NMAX];
string a[NMAX], ans;

bool backtrack(int i)
{
    if (i == m)
        return true;

    vector<bool> visited(26, false);
    for (int j = 0; j < n; ++j)
    {
        char c  = a[j][i];
        bool ok = true;

        if (visited[c - 'a'])
            continue;
        visited[c - 'a'] = true;
        for (int k = 0; k < n; ++k)
        {
            diff[k] += (a[j][i] != a[k][i]);
            if (diff[k] > 1)
                ok = false;
        }

        ans[i] = c;
        if (ok and backtrack(i + 1))
            return true;

        ans[i] = ' ';
        for (int k = 0; k < n; ++k)
            diff[k] -= (a[j][i] != a[k][i]);
    }

    return false;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        ans.resize(m, ' ');
        fill(diff, diff + NMAX, 0);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        if (backtrack(0))
            cout << ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
