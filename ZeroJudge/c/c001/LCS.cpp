//ZJ C001
//TODO: error
#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    string a, b;
    while (cin >> a >> b)
    {
        if (a.size() < b.size())
            a.swap(b);

        /*int dp1[1002]{}, dp2[1002]{};
        for (auto &i : a)
        {
            for (int j = 1; j <= b.size(); j++)
                dp1[j] = dp2[j];
            for (int j = 1; j <= b.size(); j++)
            {
                if (i == b.at(j - 1))
                    dp2[j] = dp1[j - 1] + 1;
                else
                    dp2[j] = max(dp2[j - 1], dp1[j]);
            }*/
        //cerr
        /*for (int j = 0; j <= b.size();j++){
                cout << dp2[j] << " ";
            }
            cout << endl;*/
        //
        //}
        //cout << dp2[b.size()] << endl;

        int dp[1002]{};
        bool check[1002]{};
        for (auto &i : a)
        {
            for (int j = 0; j < b.size(); j++)
            {
                if (i == b.at(j))
                {
                    if (check[j])
                        dp[j]++;
                    else
                        check[j] = false;
                }
                else if (j > 0)
                    dp[j] = max(dp[j - 1], dp[j]);
            }
            //cerr
            for (int j = 0; j < b.size(); j++)
                cout << dp[j] << " ";
            cout << endl;
            //
        }
        cout << dp[b.size() - 1] << endl;
    }
}
