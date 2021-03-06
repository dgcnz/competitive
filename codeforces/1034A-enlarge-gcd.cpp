/** @file
 * @date                2020-11-21
 * @url                 https://codeforces.com/contest/1034/problem/A
 * @tags                number_theory, erathostenes_sieve, gcd
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           no
 * @reading_time        10
 * @thinking_time       20
 * @coding_time         25
 * @time_complexity     O(n \log(a_{max}))
 * @memory_complexity   O(a_{max})
 * @idea
 *  - Note that any other common factor between the chosen subset of numbers
 * will result in a greater gcd than the global gcd.
 *  - So, the problem reduces to finding the most frequent common factor.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
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

using namespace std;
using ll = long long;
using vi = vector<int>;

int const PMAX = 1.5e7 + 11;
int const NMAX = 3e5 + 11;

int n, a[NMAX];

bitset<PMAX> is_prime;
vi           primes;
vi           factors(PMAX, 0);

void update_factors(int x, int &ans)
{
    for (int const &pf : primes)
    {
        if (pf * pf > x)
            break;
        if (x % pf == 0)
        {
            factors[pf]++;
            ans = max(ans, factors[pf]);
        }
        while (x % pf == 0)
            x = x / pf;
    }
    if (x != 1)
    {
        factors[x]++;
        ans = max(ans, factors[x]);
    }
}
void sieve(int const sieve_size)
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= sieve_size; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= sieve_size; j += i)
                is_prime[j] = 0;
            primes.push_back(i);
        }
    }
}

int solve(void)
{
    int n_gcn = a[0], ans = 0;
    for (int i = 1; i < n; ++i)
        n_gcn = gcd<int, int>(n_gcn, a[i]);
    for (int i = 0; i < n; ++i)
        update_factors(a[i] / n_gcn, ans);
    return ans == 0 ? -1 : n - ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    sieve(PMAX - 1);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << solve() << endl;

    return 0;
}
