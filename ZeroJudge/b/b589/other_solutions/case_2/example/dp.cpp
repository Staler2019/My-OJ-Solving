#include <iostream>
#include <vector>
using namespace std;
#define max(a, b) (a > b) ? a : b
int main()
{
    int n;
    while (cin >> n && n)
    {
        int paths[n];
        for (auto &i : paths)
            cin >> i;
        vector<int> dp = vector<int>();
        //for i=n-1 n-2
        dp.push_back(paths[n - 1] * 2);
        if (n >= 2)
            dp.push_back(max(dp.at(0) + paths[n - 2], paths[n - 2] * 2));

        //for i=n-3 -- i=0
        for (int i = n - 3, j = 1; i >= 0; i--, j++)
            dp.push_back(max(dp.at(j) + paths[i], paths[i] * 2 + dp.at(j - 1)));

        cout << dp.back() << endl;
    }
}
