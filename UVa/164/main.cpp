// TODO: DP
// 原本不採DP是對的，但是測資不採計
/**********************
 *作者: P.Y.Snow      *
 **********************/

/* 常用設定 -------------------------------------- */
#pragma GCC optimize("Ofast")

#include <immintrin.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace plus_plus {
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
/* 定義用函式 ------------------------------------ */
#define isOdd(a) ((a & 1) ? true : false)
#define FIA(a) for (auto &i : a)
#define FJA(a) for (auto &j : a)
#define FI(a) for (int i = 0; i < a; i++)
#define FJ(a) for (int j = 0; j < a; j++)
#define FK(a) for (int k = 0; k < a; k++)
#define cer(args...)                                                 \
    cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << "(" << #args \
         << ") = " << args << endl

/* 定義用名詞 ------------------------------------ */
#define Be return
#define Interesting 0
#define CASE   \
    int _T;    \
    cin >> _T; \
    for (int tt = 0; tt < _T; tt++)
#define all(a) std::begin(a), std::end(a)
#define sum(a) (accumulate(all(a), 0ll))
#define mine(a) (*min_element(all(a)))
#define maxe(a) (*max_element(all(a)))
#define mini(a) (min_element(all(a)) - (a).begin())
#define maxi(a) (max_element(all(a)) - (a).begin())
#define lowb(a, x) (lower_bound(all(a), (x)) - (a).begin())
#define uppb(a, x) (upper_bound(all(a), (x)) - (a).begin())
#define bMod(a, b) (bool)(a % b)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define st first
#define nd second
#define endl '\n'

/* 定義用型態 ------------------------------------ */
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

// ^ <-> !=
/* 常用函式 -------------------------------------- */
#define TT1 template <class T>
#define TT1T2 template <class T1, class T2>
/*TT1 inline void swap(T &a, T &b) {
    a = a ^ b, b = a ^ b, a = a ^ b;
}*/
/*-pair-*/
#define PT1T2 pair<T1, T2>
TT1T2 inline PT1T2 operator+(const PT1T2 &p1, const PT1T2 &p2) {
    return PT1T2(p1.first + p2.first, p1.second + p2.second);
}
TT1T2 inline PT1T2 &operator+=(PT1T2 &p1, const PT1T2 &p2) {
    p1.first += p2.first, p1.second += p2.second;
    return p1;
}
TT1T2 inline PT1T2 operator-(const PT1T2 &p1, const PT1T2 &p2) {
    return PT1T2(p1.first - p2.first, p1.second - p2.second);
}
TT1T2 inline PT1T2 &operator-=(PT1T2 &p1, const PT1T2 &p2) {
    p1.first -= p2.first, p1.second -= p2.second;
    return p1;
}
TT1T2 inline istream &operator>>(istream &is, PT1T2 &p) {
    is >> p.first >> p.second;
    return is;
}
TT1T2 inline ostream &operator<<(ostream &os, const PT1T2 &p) {
    os << p.first << p.second;
    return os;
}
#undef PT1T2
/*-vector-*/
#define VT1 vector<T>
TT1 inline VT1 &operator--(VT1 &v) {
    FIA(v) { i--; }
    return v;
}
TT1 inline VT1 &operator++(VT1 &v) {
    FIA(v) { i++; }
    return v;
}
TT1 inline istream &operator>>(istream &is, VT1 &v) {
    FIA(v) { is >> i; }
    return is;
}
TT1 inline ostream &operator<<(ostream &os, const VT1 &v) {
    FI(v.size()) { os << v[i] << " "; }
    return os;
}
#undef VT1
#undef TT1
#undef TT1T2
}  // namespace plus_plus
using namespace std;
using namespace plus_plus;

/* 程式碼 ---------------------------------------- */
/*-函式-*/

/*-主程式-*/
int InSolving();
#define _TEST
int main() {
    // args
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
#ifdef _TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  //_TEST
    Be InSolving();
}

int InSolving() {
    string a, b;
    while (cin >> a) {
        if (a == "#") return 0;

        string ans;
        cin >> b;
        int i = 1;
        // cerr << "err: " << min(a.size(), b.size()) << endl;
        for (; i <= min(a.size(), b.size()); i++) {
            int posi = i - 1;
            if (a[posi] == b[posi]) continue;
            ans = ans + "C" + b[posi] + (char)(i / 10 + '0') +
                  (char)(i % 10 + '0');
            //cerr << "err: " << ans << endl;
        }
        //cerr << "err: -----" << endl;
        for (; i < a.size() + 1; i++)  // a exceed
        {
            int posi = i - 1;
            ans = ans + "D" + a[posi] + (char)(i / 10 + '0') +
                  (char)(i % 10 + '0');
            //cerr << "err: " << ans << endl;
        }
        //cerr << "err: -----" << endl;
        for (; i < b.size() + 1; i++) {  // b exceed
            int posi = i - 1;
            ans = ans + "I" + b[posi] + (char)(i / 10 + '0') +
                  (char)(i % 10 + '0');
            // cerr << "err: " << ans << endl;
        }
        ans = ans + "E";
        cout << ans << endl;
    }
    return Interesting;  // end of code
}
