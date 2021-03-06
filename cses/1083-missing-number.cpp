#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n;
    vector<bool> is_present(n + 1, false);

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> x;
        is_present[x] = true;
    }

    for (int i = 1; i <= n; ++i)
        if (not is_present[i])
            cout << i << endl;
    return 0;
}
