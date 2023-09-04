// https://zerojudge.tw/ShowProblem?problemid=c204
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
#define CASE            \
    int _T;             \
    cin >> _T;          \
    cerr << _T << endl; \
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
#define MAX (ll)1e12
vector<ll> prime;
ll perfect[] = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328};

void setPrime() {  //厄拉托西尼篩法
                   // https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95

    vector<bool> p(sqrt(MAX) + 1, true);
    for (ll i = 2; i <= sqrt(MAX); i++) {
        if (p[i]) {
            prime.pb(i);
            for (ll j = i * i; j <= sqrt(MAX); j += i) p[j] = false;
        }
    }
    // cerr << prime << endl;
    // cerr << prime.size() << endl;
    // cerr << maxe(prime) << endl;
}
auto setFactor(ll n) {  //因式分解
    ll tmp_n = n;
    vector<pair<ll, int>> factor;
    FIA(prime) {
        int num{};
        while (n % i == 0) {
            n /= i;
            num++;
        }
        if (num) factor.pb(mp(i, num));
    }
    if (n > sqrt(tmp_n)) factor.pb(mp(n, 1));
    return factor;
}  // up ok
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
    setPrime();
    CASE {
        ll n, ans = 1;
        cin >> n;
        cerr << n << endl;
        bool per = false;
        for (ll &i : perfect) { //perfect num先篩出
            if (n == i) {
                per = true;
                break;
            }
        }
        if (!per) {
            vector<pair<ll, int>> factor = setFactor(n);
            FIA(factor) { //所有因數和 = (a1^0+a1^1+a1^2+...)*(a2^0+a2^1+a2^2+...)*...
                ans *= ((pow(i.first, i.second + 1) - 1) / (i.first - 1));
            }
            ans -= n;
        }  // up ok
        /*vector<int> local; // 下面爆時1100*1e6 一定要因式分解不浪費測試數字->只測一次
        for (ll &i : prime) {
            if (per || i > sqrt(n)) break;
            if (n % i == 0) {
                ans += i + n / i;
                // cerr << " " << i;
                for (ll j = 2, k = 0;; j++) {
                    if (k < local.size()) {
                        if (j == local[k]) {
                            k++;
                            continue;
                        }
                    }

                    ll tmp = i * j;
                    if (tmp > sqrt(n)) break;
                    if (n % tmp == 0) {
                        ans += tmp + n / tmp;
                        // cerr << " " << tmp;
                    } else
                        cerr << " " << tmp;
                }
                cerr << endl;
                local.pb(i);
            }
        }*/
        // cerr << "ans:" << ans << endl;
        if (ans == n || per)
            cout << "perfect" << endl;
        else if (ans > n)
            cout << "abundant" << endl;
        else
            cout << "deficient" << endl;
    }
    return Interesting;  // end of code
}
