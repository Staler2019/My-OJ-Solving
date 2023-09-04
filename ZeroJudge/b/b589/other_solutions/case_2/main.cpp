//記憶體沒有差很多，不如寫得清楚一些還比較好
//影響記憶體主要: 1引用函式庫 2亂增加記憶量 3未簡化想法
//影響時間主要: 1未簡化想法 2少檢討程式碼 3少觀摩程式碼
#include <iostream>
using namespace std;

#define max(a, b) (a > b) ? a : b

int main()
{
    int n;
    while (cin >> n && n)
    {
        int in[n], dp[n];

        for (auto &i : in)
            cin >> i;

        // n=1
        dp[0] = 2 * in[n - 1]; // last one: 2
        // n>=2
        if (n >= 2)
            dp[1] = max(in[n - 2] + dp[0], 2 * in[n - 2]); // last two: 1[2], 20
        // n>=3
        for (int i = 2; i < n; i++) // probably: max(in[n-1-i]+dp[i-1], 2*in[n-1-i]+dp[i-2])
            dp[i] = max(in[n - i - 1] + dp[i - 1], 2 * in[n - i - 1] + dp[i - 2]);
        // last three: 1[12], 1[20], 202 // last four: 1[112], 1[120], 1[202], 20{12}, 20{20}

        cout << dp[n - 1] << endl;
    }
}