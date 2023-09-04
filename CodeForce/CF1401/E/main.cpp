// TODO:https://codeforces.com/contest/1401/problem/E
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
#define FJA(a) for (auto &J : a)
#define FI(a) for (int i = 0; i < a; i++)
#define FJ(a) for (int j = 0; j < a; j++)
#define FK(a) for (int k = 0; k < a; k++)

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
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define st first
#define nd second

/* 定義用型態 ------------------------------------ */
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

// ^ <-> !=
/* 常用函式 -------------------------------------- */
#define TT1 template <class T>
#define TT1T2 template <class T1, class T2>
/*TT1 inline void swap(T &a, T &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
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
// bool v[1000007][1000007]{};//x y posiChanges
// vector<vector<pair<bool, int>>> v;
vector<pair<int, pair<int, int>>> v;
/*-主程式-*/
int InSolving();
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
    int n, m, p, s, e, ans = 1;
    cin >> n >> m;
    for (; n > 0; n--) {
        cin >> p >> s >> e;  // p at y
        v.pb(mp(p, mp(s, e)));
        if (s == 0 && e == 1000000) ans++;
    }
    // cerr << ans << endl;
    sort(all(v));
    for (; m > 0; m--) {
        cin >> p >> s >> e;  // p at x
        if (s == 0 && e == 1000000) ans++;
        FI(v.size()) {
            // cerr << "//" <<  v[i].first << " " << s << " " << e<< endl;
            if (v[i].first < s) continue;
            if (v[i].first > e) break;
            if (v[i].second.first <= p && v[i].second.second >= p) {
                ans++;
            }
        }
        // cerr << ans << endl;
    }
    cout << ans << endl;
    return Interesting;  // end of code
}
