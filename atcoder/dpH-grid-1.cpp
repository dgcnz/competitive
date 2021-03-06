#include <iostream>

using namespace std;

const int NMAX = 1e3 + 11;
const int MOD  = 1e9 + 7;

int  h, w, mem[NMAX][NMAX];
bool wall[NMAX][NMAX];

int paths(void)
{
    for (int row = h - 1; row >= 0; --row)
    {
        for (int col = w - 1; col >= 0; --col)
        {
            if (wall[row][col])
                continue;
            if (row == h - 1 and col == w - 1)
                mem[row][col] = 1;
            else
                mem[row][col] = (mem[row + 1][col] + mem[row][col + 1]) % MOD;
        }
    }

    return mem[0][0];
}

int main(void)
{
    char c;
    cin >> h >> w;

    for (int row = 0; row < h; ++row)
    {
        for (int col = 0; col < w; ++col)
        {
            cin >> c;
            wall[row][col] = (c == '#');
        }
    }

    cout << paths() << endl;

    return 0;
}
