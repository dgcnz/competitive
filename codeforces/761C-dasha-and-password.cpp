#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const int NMAX = 50 + 11;
const int MMAX = 50 + 11;

int n, m;
int mem[NMAX][3];

int solve(void)
{
    ll ans = 3 * MMAX;

    // Picking all combinations of 3 of different m-strings
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            for (int k = 0; k < n; ++k)
            {
                if (k == j or k == i)
                    continue;
                ans = min(ans, (ll)(mem[i][0] + mem[j][1] + mem[k][2]));
            }
        }
    }

    return ans;
}

int main(void)
{
    string s;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        mem[i][0] = mem[i][1] = mem[i][2] = MMAX;

    for (int i = 0; i < n; ++i)
    {
        cin >> s;

        // Computing the shortest distance to digit, alpha, symbol for every
        // m-string
        for (int j = 0; j < m; ++j)
        {
            if (isdigit(s[j]))
                mem[i][0] = min(mem[i][0], min(j, m - j));
            else if (isalpha(s[j]))
                mem[i][1] = min(mem[i][1], min(j, m - j));
            else
                mem[i][2] = min(mem[i][2], min(j, m - j));
        }
    }

    cout << solve() << endl;

    return 0;
}
