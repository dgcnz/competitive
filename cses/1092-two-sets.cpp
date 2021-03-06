#include <iostream>

using namespace std;
using ll = long long;

const int NMAX = 1e6 + 11;

bool taken[NMAX];
int  ntaken;

bool possible(int n, ll sum)
{
    if (sum % 2 == 1)
        return false;

    sum /= 2;
    for (int i = n; i >= 1 and sum > 0; --i)
    {
        if (sum - i >= 0)
        {
            ++ntaken;
            taken[i] = true;
            sum -= i;
        }
    }

    return true;
}

int main(void)
{
    int n;
    ll  sum = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        sum += i;

    if (possible(n, sum))
    {
        cout << "YES" << endl;
        cout << ntaken << endl;
        for (int i = 1; i <= n; ++i)
            if (taken[i])
                cout << i << " ";
        cout << endl;
        cout << n - ntaken << endl;
        for (int i = 1; i <= n; ++i)
            if (not taken[i])
                cout << i << " ";
    }
    else
        cout << "NO" << endl;

    return 0;
}
