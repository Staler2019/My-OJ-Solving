//
/**********************
 *作者: P.Y.Snow      *
 **********************/
//#define _TEST
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

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
/* 定義用函式 ------------------------------------ */
#define isOdd(a) ((a & 1) ? true : false)
#define FIA(a) for (auto &i : a)
#define FJA(a) for (auto &j : a)
#define FI(n) for (int i = 0; i < n; i++)
#define FJ(n) for (int j = 0; j < n; j++)
#define FK(n) for (int k = 0; k < n; k++)

/* 定義用名詞 ------------------------------------ */
#define Be return
#define Interesting 0
#define CASE   \
    int _T;    \
    cin >> _T; \
    for (int tt = 0; tt < _T; tt++)
#define all(a) (std::begin(a), std::end(a))
#define sum(a) (accumulate((a).begin(), (a).end(), 0ll))
#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define mini(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a) (max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) (lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) (upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define pb push_back
#define mp make_pair

/* 定義用型態 ------------------------------------ */
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#define TT1 template <class T>
#define TT1T2 template <class T1, class T2>

// ^ <-> !=
/* 常用函式 -------------------------------------- */
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

/* 程式碼 ---------------------------------------- */
/*-函式-*/

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
    CASE {
        int n;
        string s;
        cin >> n >> s;
        bool all0 = false;
        if (n >= s.size()) {
            cout << s << endl;
        } else {
            string ans;
            FI(n) { ans.pb('0'); }
            FI(s.size() - n + 1) {
                string tmp =
                    s.substr(i, n);  // can't use stack because it doesn't have
                                     // iterator cerr << tmp << endl;
                FJ(tmp.size()) {
                    ans[j] = 48 + (int)((tmp[j] - 48) | (ans[j] - 48));
                    // cerr << " " << ans[j] << " ";
                }
                // cerr << endl;
            }
            cout << ans << endl;
        }
    }
    return Interesting;  // end of code
}
