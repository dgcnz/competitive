#include <bits/stdc++.h>

using namespace std;
using ll   = long long;
using vll  = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;

ll solve(ll n)
{
    ll target;
    target = (n * (n + 1)) / 2;
    if (target % 2 != 0)
        return 0;

    target /= 2;

    vvll dp(n + 1, vll(target + 1, 0));

    dp[0][0] = 1;

    for (ll x = 1; x <= n; ++x)
    {
        for (ll sum = 1; sum <= target; ++sum)
        {
            ll &ans = dp[x][sum];
            ans     = dp[x - 1][sum];
            if (sum - x >= 0)
                ans = (ans + dp[x - 1][sum - x] % MOD) % MOD;
        }
    }

    return dp[n][target];
}

int main(void)
{
    ll n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}
