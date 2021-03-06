#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
using vll = vector<ll>;
using ii  = array<ll, 2>;

const ll NMAX = 5e3 + 11;

ll   x[NMAX];
ii   mem[NMAX][NMAX];
bool vis[NMAX][NMAX];

ii dp(ll l, ll r, bool player)
{
    ii &ans  = mem[l][r];
    ll  lval = x[l];
    ll  rval = x[r];

    if (r - l + 1 == 2) // base case
    {
        ans[player]  = max({lval, rval});
        ans[!player] = min({lval, rval});
        return ans;
    }

    if (vis[l][r])
        return ans;

    vis[l][r] = true;

    ii lans = dp(l + 1, r, !player);
    ii rans = dp(l, r - 1, !player);

    lans[player] += lval;
    rans[player] += rval;

    ans = lans[player] > rans[player] ? lans : rans;

    return ans;
}

int main(void)
{
    ll n;
    cin >> n;

    for (ll i = 0; i < n; ++i)
        cin >> x[i];

    cout << dp(0, n - 1, true)[true] << endl;
    return 0;
}
