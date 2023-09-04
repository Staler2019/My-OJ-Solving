#include <iostream>
using namespace std;

//#define _DEBUG
using LL = long long;

int main()
{
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        LL ans = 1, pre = 1;
        for (int i = 2; i <= n; i++)
        {
            LL tmp = ans;
            ans = ans + pre;
            pre = tmp;
        }
        cout << ans << endl;
    }
}