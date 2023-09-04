//https://zerojudge.tw/ShowProblem?problemid=a020
/**********************
*作者: P.Y.Snow 楊佳峻*
**********************/

/* 常用設定 -------------------------------------- */
#pragma GCC optimize("Ofast")

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
#include <immintrin.h>
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
    for (int tt = 0; t < _T; tt++)
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
TT1 inline void swap(T &a, T &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
/*-pair-*/
#define PT1T2 pair<T1, T2>
TT1T2 inline PT1T2 operator+(const PT1T2 &p1, const PT1T2 &p2)
{
    return PT1T2(p1.first + p2.first, p1.second + p2.second);
}
TT1T2 inline PT1T2 &operator+=(PT1T2 &p1, const PT1T2 &p2)
{
    p1.first += p2.first, p1.second += p2.second;
    return p1;
}
TT1T2 inline PT1T2 operator-(const PT1T2 &p1, const PT1T2 &p2)
{
    return PT1T2(p1.first - p2.first, p1.second - p2.second);
}
TT1T2 inline PT1T2 &operator-=(PT1T2 &p1, const PT1T2 &p2)
{
    p1.first -= p2.first, p1.second -= p2.second;
    return p1;
}
#undef PT1T2

/* 程式碼 ---------------------------------------- */
/*-函式-*/
const map<char, int> m = {
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15},
    {'G', 16},
    {'H', 17},
    {'I', 34},
    {'J', 18},
    {'K', 19},
    {'L', 20},
    {'M', 21},
    {'N', 22},
    {'O', 35},
    {'P', 23},
    {'Q', 24},
    {'R', 25},
    {'S', 26},
    {'T', 27},
    {'U', 28},
    {'V', 29},
    {'W', 32},
    {'X', 30},
    {'Y', 31},
    {'Z', 33}};

/*-主程式-*/
int InSolving();
int main()
{
    // args
    cin.tie(0), ios_base::sync_with_stdio(0);
#ifdef _TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //_TEST
    Be InSolving();
}

int InSolving()
{
    char c;
    string s;
    cin >> c >> s;
    int ans = m.find(c)->second / 10 + m.find(c)->second % 10 * 9;
    for (int i = 8; i > 0; i--)
    {
        ans += (int)(s[8 - i] - 48) * i;
    }
    ans += (int)(s[s.size() - 1] - 48);
    if(ans%10==0){
        cout << "real";
    }
    else{
        cout << "fake";
    }

    return Interesting;
}
