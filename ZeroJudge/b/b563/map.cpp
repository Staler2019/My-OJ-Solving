/**********************
*作者: P.Y.Snow 楊佳峻*
**********************/

/* 常用設定 -------------------------------------- */
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;
/* 定義 ------------------------------------------ */
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define isOdd(a) ((a & 1) ? true : false)
#define forA(i, a) for (auto &i : a)
#define for0(i, a) for (int i = 0; i < a; i++)
#define print(a) printf("%d ", a)
#define println(a) printf("%d\n", a)

#define IOS cin.tie(NULL), ios_base::sync_with_stdio(NULL)
#define TEST freopen("input.txt", "r", stdin)
#define CASE   \
    int _T;    \
    cin >> _T; \
    for0(tt, _T)
#define Be return
#define Interesting 0

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

// '^' == '!='

/* 程式碼 ---------------------------------------- */
int main()
{
    int n;
    while (cin >> n)
    {
        map<pair<int, int>, int> m;
        int a, b, ans = 0;
        for0(tt, n)
        {
            cin >> a >> b;
            //cerr << a << " " << b << endl;
            auto it = m.find(make_pair(b, a));
            if (it != m.end())
            {
                int tmp = it->second--;
                if (tmp == 0)
                {
                    m.erase(it);
                }
                ans++;
            }
            else
            {
                m[make_pair(a, b)]++;
            }
        }
        cout << ans << endl;
    }

    Be Interesting;
}
