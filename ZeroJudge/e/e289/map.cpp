/**********************
*作者: P.Y.Snow 楊佳峻*
**********************/

/* 常用設定 -------------------------------------- */
#include <cstdio>
#include <iostream>
#include <string>
#include <map>

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
#define TEST freopen("input,txt", 'r', stdin)
#define Keep return
#define Interesting 0

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;

// '^' == '!='

/* 程式碼 ---------------------------------------- */
/*#define M (ull)(1e9 + 7)

class Matrix{
    const ull m[2][2]{1,1,1,0};

    void powM(ull fx_1,ull fx_2){

    }
}*/

int main()
{
    /*int n;
    ull ans = 1, pre = 1;
    scanf("%d", &n);
    if (n == 2)
        ans = 2;
    else if (n >= 3)
    {
        int i = 3;
        ull tmp;
        pre = 2;
        ans = 3;
        while (n > (2 * i))
        {
            tmp = ans;
            ans = (((pre * 2 + ans) % M) * ans) % M;
            pre = (tmp * tmp) % M + (pre * pre) % M;
            i = 2 * i + 1;
            //printf("%d %lld\n", i, ans);
        }
        //i++;
        for (; i < n; i++)
        {
            pre = (ans + pre) % M;

            ans = ans ^ pre;
            pre = ans ^ pre;
            ans = ans ^ pre;
            //if(ans==620469133)
                //println(i);
            //if(n-i<10)
                //printf("%d %lld\n", i, ans);

        }
    }
    printf("%lld\n", ans);
    //println(ans == 620469133);*/

    IOS;
    int m, n;
    cin >> m >> n;

    string a[n];
    forA(i, a)
        cin >> i;

    int ans = 0;
    map<string,int> now;
    for0(i, n)
    {
        now[a[i]]++;
        if(i>=m){
            now[a[i-m]]--;
            if(now[a[i-m]]==0)
                now.erase(a[i-m]);
        }
        if (now.size() == m)
            ans++;
    }
    cout << ans << endl;

    Keep Interesting;
}