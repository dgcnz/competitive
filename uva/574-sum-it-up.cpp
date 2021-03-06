#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

const int NMAX = 12 + 8;

int t, n;
int x[NMAX];

void print_ans(vi ans)
{
    for (auto &elem : ans)
    {
        if (&elem != &ans.front())
            cout << "+";

        cout << elem;
    }

    cout << endl;
}

bool backtrack(int pos, int sum, vi cur_ans)
{
    bool found = false;

    if (sum == t)
    {
        print_ans(cur_ans);
        return true;
    }

    if (sum > t or pos > n)
        return false;

    for (int i = pos; i < n; ++i)
    {
        if (i != pos and
            x[i] == x[i - 1]) // Only the first occurrence of a number can try
                              // adding following same numbers
            continue;
        cur_ans.push_back(x[i]);
        found |= backtrack(i + 1, sum + x[i], cur_ans);
        cur_ans.pop_back();
    }

    return found;
}

int main(void)
{

    while (cin >> t >> n and n != 0)
    {
        for (int i = 0; i < n; ++i)
            cin >> x[i];

        cout << "Sums of " << t << ":" << endl;

        if (not backtrack(0, 0, vi()))
            cout << "NONE" << endl;
    }

    return 0;
}
