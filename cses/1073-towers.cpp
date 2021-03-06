#include <bits/stdc++.h>

using namespace std;
using si = multiset<int>;

int main(void)
{
    int n, ki;
    cin >> n;

    si frontier;
    for (int i = 0; i < n; ++i)
    {
        cin >> ki;
        if (auto it = frontier.upper_bound(ki); it != frontier.end())
        {
            frontier.erase(it);
            frontier.insert(ki);
        }
        else
            frontier.insert(ki);
    }
    cout << frontier.size() << endl;

    return 0;
}
