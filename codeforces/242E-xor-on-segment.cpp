/** @file
 * @date                2020-12-22
 * @url                 https://codeforces.com/contest/242/problem/E
 * @tags                data_structures, lazy, segment_tree, bitmask
 * @status              AC
 * @score               4
 * @difficulty          4
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       20
 * @coding_time         20
 * @time_complexity     O(q \log^2{n})
 * @memory_complexity   O(n \log{n})
 * @idea
 * [Editorial](https://codeforces.com/blog/entry/5837).
 *
 * Let the ith Segment Tree maintain information on the ith bit of all numbers
 * in the array $A$.
 *
 * The sum query would be the same as counting the set bits for all bits and
 * then adding them together (with it's corresponding $2^i$ factor).
 *
 * The update query would be the same as swapping all numbers on the ith bit if
 * such bit is set on $x$.
 *
 * I'm trying AtCoder's [Lazy Segment
 * Tree](https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html).
 *
 * Let's define the structure's parameters.
 *
 * - `S`: A pair of integers, `n` and `cnt_set` (the number of elements in that
 * range and the number of set bits ($1$s) in that range.
 * - `op`: Standard pair addition
 * - `e` : $(0, 0)$
 * - `F` : The set of functions $F$ is uniquely determined by a boolean value.
 * $F= (f_0, f_1)$.
 * - `mapping`: $f_1(S) \to S$ means applying xor to all the bits denoted by
 * node $S$. This is equal to `n - cnt_set`. Note that $f_0$ doesn't change
 * anything.
 * - `composition`: $f_j(f_i(S)) = (i \oplus j) \oplus S $
 * - `id`: $f_0$
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <atcoder/lazysegtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct S
{
    int n, cnt_set;
};

using F = bool;

S op(S l, S r) { return {l.n + r.n, l.cnt_set + r.cnt_set}; }

S e() { return {0, 0}; }

S mapping(F l, S r) { return (l ? S{r.n, r.n - r.cnt_set} : r); }

F composition(F l, F r) { return l ^ r; }

F id() { return 0; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n;

    array<vector<S>, 20> a;
    for_each(all(a), [n](auto &v) { v.resize(n); });
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 20; ++j)
            a[j][i] = {1, (x >> j) & 1};
    }

    using lazy_segtree =
        atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

    array<lazy_segtree, 20> st;
    for (int i = 0; i < 20; ++i)
        st[i] = lazy_segtree(a[i]);

    cin >> m;
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r, l--, r--;

            ll ans = 0;
            for (int i = 0; i < 20; ++i)
            {
                auto cur = st[i].prod(l, r + 1);
                ans += (1LL << i) * cur.cnt_set;
            }
            cout << ans << endl;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x, l--, r--;

            for (int i = 0; i < 20; ++i)
                st[i].apply(l, r + 1, (x >> i) & 1LL);
        }
    }

    return 0;
}
