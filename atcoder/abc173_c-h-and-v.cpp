#include <bits/stdc++.h>

using namespace std;

int count_black(
    const vector<string> &color, int mask_h, int mask_w, int h, int w)
{
    int ans = 0;
    for (int r = 0; r < h; ++r)
    {

        for (int c = 0; c < w; ++c)
        {
            if (((mask_h >> r) & 1) or (mask_w >> c) & 1)
                continue;
            if (color[r][c] == '#')
                ans++;
        }
    }
    return ans;
}

int main(void)
{
    int            h, w, k, ans = 0;
    vector<string> c;

    cin >> h >> w >> k;
    c.resize(h);
    for_each(c.begin(), c.end(), [](string &row) { cin >> row; });

    for (int mask_h = 0; mask_h < (1 << h); ++mask_h)
    {
        for (int mask_w = 0; mask_w < (1 << w); ++mask_w)
        {
            if (auto cur = count_black(c, mask_h, mask_w, h, w); cur == k)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
