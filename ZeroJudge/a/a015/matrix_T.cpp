#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int m[a][b];
        for (auto &i : m)
            for (auto &j : i)
                cin >> j;

        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
                cout << m[j][i] << " ";
            cout << endl;
        }
    }
}