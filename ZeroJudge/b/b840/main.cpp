//#define _DEBUG
#include <iostream>
using namespace std;

#define max(a, b) (a > b) ? a : b

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    int matr[n + 1][n + 1]{};
    int dp[n + 1][n + 1]{};

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            cin >> matr[i][j];
    /*//test
    cerr << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cerr << matr[i][j] << " ";
        cerr << endl;
    }*/

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            dp[i][j] = matr[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
    /*/test
    cerr << "----------" << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cerr << dp[i][j] << " ";
        cerr << endl;
    }*/

    int maximum = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            for (int a = 0; a < i; a++)
                for (int b = 0; b < j; b++)
                    maximum = max(maximum, dp[i][j] - dp[i][b] - dp[a][j] + dp[a][b]);

    cout << maximum << endl;
}