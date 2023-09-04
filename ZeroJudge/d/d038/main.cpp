// dp: zero judge d038 using Fibonacci--recursion & memorization(memoize)
#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL dp[51]{};

LL fib(int n)
{
    LL ans;
    if (dp[n] != 0)
        return dp[n];
    if (n == 0 || n == 1)
        ans = 1;
    else
    {

        ans = fib(n - 1) + fib(n - 2);
    }
    dp[n] = ans;
    return ans;
}

int main()
{
    do
    {
        int num;
        cin >> num;

        if (num == 0)
            break;

        cout << fib(num) << endl;
    } while (true);
}