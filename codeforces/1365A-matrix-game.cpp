#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int  t, n, m;
    bool aij;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        bool row_marked;

        int          free_rows = n;
        int          free_cols = m;
        vector<bool> cols_marked(m, false);
        for (int row = 0; row < n; ++row)
        {
            row_marked = false;
            for (int col = 0; col < m; ++col)
            {
                cin >> aij;
                cols_marked[col] = cols_marked[col] | aij;
                row_marked |= aij;
            }
            free_rows -= row_marked;
        }
        for (int col = 0; col < m; ++col)
            free_cols -= cols_marked[col];

        int x = min(free_rows, free_cols);
        if (x % 2 == 0)
            cout << "Vivek" << endl;
        else
            cout << "Ashish" << endl;
    }
    return 0;
}
