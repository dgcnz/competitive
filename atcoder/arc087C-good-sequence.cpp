#include <iostream>
#include <map>
#include <utility>

using namespace std;

int n;

map<int, int> counter;

int main(void)
{
    int ai, ans = 0, num, times;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        ++counter[ai];
    }

    for (auto num_times : counter)
    {
        num   = num_times.first;
        times = num_times.second;

        if (num == times)
            continue;

        while (times != num and times != 0)
        {
            --times;
            ++ans;
        }
    }

    cout << ans << endl;
}
