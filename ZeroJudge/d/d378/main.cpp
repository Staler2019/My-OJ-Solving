//#define _DEBUG
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int cases = 1, n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> matr;
        vector<int> tmp(m);
        for (int i = 0; i < n; i++)
        {
            matr.push_back(tmp);
            for (int j = 0; j < m; j++)
                cin >> matr[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    matr[0][0] = 0;
                else if (i == 0)
                    matr[i][j] += matr[i][j - 1];

                else if (j == 0)
                    matr[i][j] += matr[i - 1][j];
                else
                    matr[i][j] += min(matr[i][j - 1], matr[i - 1][j]);
            }
        }
        cout << "Case #" << cases++ << " :" << endl
             << matr[n - 1][m - 1] << endl;
    }
}