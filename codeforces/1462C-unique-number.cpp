/** @file
 * @date                2020-12-15
 * @url                 https://codeforces.com/contest/1462/problem/C
 * @tags                greedy
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       7
 * @coding_time         4
 * @time_complexity     O(1)
 * @memory_complexity   O(1)
 * @idea
 * First note that the maximum sum of digits that can be made is $45$, we'll
 * assume that $x$ is less than that from now on. Note that with the previous
 * assumption it is always possible to sum $x$.
 *
 * To build our desired number $y$, our greedy strategy will then be to fit the
 * biggest possible digits to the least significant digits of $y$. This will
 * reduce the total amount of digits used and at the same time reserve the
 * smaller digits for the most significant digits of $y$.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

int solve(int x)
{
    if (x > 45)
        return -1;

    int ans = 0, n = 1;
    for (int d = 9; d >= 1; --d)
    {
        if (x - d >= 0)
        {
            x -= d;
            ans += n * d;
            n *= 10;
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}
