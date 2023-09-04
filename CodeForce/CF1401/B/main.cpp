//
/**********************
 *作者: P.Y.Snow 楊佳峻*
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

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
/* 定義用函式 ------------------------------------ */
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define isOdd(a) ((a & 1) ? true : false)
#define FIA(a) for (auto &i : a)
#define FJA(a) for (auto &J : a)
#define FI(a) for (int i = 0; i < a; i++)
#define FJ(a) for (int j = 0; j < a; j++)
#define FK(a) for (int k = 0; k < a; k++)

/* 定義用名詞 ------------------------------------ */
#define CASE   \
    int _T;    \
    cin >> _T; \
    for (int tt = 0; tt < _T; tt++)
#define Be return
#define Interesting 0
#define all(a) std::begin(a), std::end(a)

/* 定義用型態 ------------------------------------ */
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#define TT1 template <class T>
#define TT1T2 template <class T1, class T2>

// '^' == '!='
/* 常用函式 -------------------------------------- */
TT1 inline void swap(T &a, T &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
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
#undef PT1T2

/* 程式碼 ---------------------------------------- */
/*-函式-*/

/*-主程式-*/
int InSolving();
int main() {
    // args
    cin.tie(0), ios_base::sync_with_stdio(0);
#ifdef _TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  //_TEST
    Be InSolving();
}

int InSolving() {
    CASE {
        int z[2], o[2], s[2], ans = 0;
        FI(2) { cin >> z[i] >> o[i] >> s[i]; }
        int tmp;
        if(s[0] > 0 && o[1] > 0){
            tmp = min(s[0], o[1]);
            s[0] -= tmp;
            o[1] -= tmp;
            ans += tmp << 1;
        }
        if(o[0] > 0 && o[1] > 0){
            tmp = min(o[0], o[1]);
            o[0] -= tmp;
            o[1] -= tmp;
        }
        if(o[0] > 0 && z[1] > 0){
            tmp = min(o[0],z[1]);
            o[0] -= tmp;
            z[1] -= tmp;
        }if(o[0] > 0 && s[1] > 0){
            tmp = min(o[0], s[1]);
            ans -= tmp << 1;
        }

        /*while (s[0] > 0 && o[1] > 0) {
            ans += 2;
            s[0]--, o[1]--;
        }
        while (o[0] > 0 && o[1] > 0) {
            o[0]--, o[1]--;
        }
        while (o[0] > 0 && z[1] > 0) {
            o[0]--, z[1]--;
        }
        while (o[0] > 0 && s[1] > 0) {
            ans -= 2;
            o[0]--, s[1]--;
        }*/
        cout << ans << endl;
    }
    // end of code
    return Interesting;
}
