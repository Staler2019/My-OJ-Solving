// Reference: https://dreamisadream97.pixnet.net/blog/post/278849548-b589
#define _DEBUG
//**************************//
#include <iostream>
using namespace std;

#define M 41

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n; // n(path)
    while (cin >> n && n)
    {
        int p[M]; // p(weight)
        int dp[5], co_dp[5]; // dp(rec2), co_dp(rec1)
        // cin
        for (int i = 0; i < n; i++)
            cin >> p[i];
        // i == 0
        dp[4] = 0;
        dp[0] = dp[2] = p[0];
        dp[1] = dp[3] = 2 * p[0];
        // i == 1~n-1
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
                co_dp[j] = dp[j];
            dp[0] = max(dp[0], co_dp[4] + p[i]);
            dp[1] = max(dp[1], co_dp[4] + 2 * p[i]);
            dp[2] = max(dp[2], max(co_dp[0] + p[i], co_dp[2] + p[i]));
            dp[3] = max(dp[3], max(co_dp[0] + 2 * p[i], co_dp[2] + 2 * p[i]));
            dp[4] = max(dp[4], max(co_dp[1], co_dp[3]));
        }
        // max
        int maximum = 0;
        for (int i = 0; i < 5;i++)
            maximum = max(maximum, dp[i]);
        cout << maximum << endl;
    }
}