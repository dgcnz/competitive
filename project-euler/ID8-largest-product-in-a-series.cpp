/** @file
 * @date                2020-12-02
 * @url                 https://url.com
 * @tags                math, sorting
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        000
 * @thinking_time       000
 * @coding_time         000
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 *
 *
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

string num =
    "73167176531330624919225119674426574742355349194934969835203127745063262395"
    "78318016984801869478851843858615607891129494954595017379583319528532088055"
    "11125406987471585238630507156932909632952274430435576689664895044524452316"
    "17318564030987111217223831136222989342338030813533627661428280644448664523"
    "87493035890729629049156044077239071381051585930796086670172427121883998797"
    "90879227492190169972088809377665727333001053367881220235421809751254540594"
    "75224352584907711670556013604839586446706324415722155397536978179778461740"
    "64955149290862569321978468622482839722413756570560574902614079729686524145"
    "35100474821663704844031998900088952434506585412275886668811642717147992444"
    "29282308634656748139191231628245861786645835912456652947654568284891288314"
    "26076900422421902267105562632111110937054421750694165896040807198403850962"
    "45544436298123098787992724428490918884580156166097919133875499200524063689"
    "91256071760605886116467109405077541002256983155200055935729725716362695618"
    "82670428252483600823257530420752963450";

int main(void)
{
    using namespace placeholders;
    ios::sync_with_stdio(false), cin.tie(NULL);
    int const N = 13;

    ll ans = 0, cur;
    for (int i = 0, n = isz(num); i < n - N; ++i)
    {
        cur = accumulate(begin(num) + i,
                         begin(num) + i + N,
                         1LL,
                         [](ll acc, char d) { return acc * (d - '0'); });
        if (cur > ans)
            ans = cur;
    }

    cout << ans << endl;
    return 0;
}
