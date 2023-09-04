#include <iostream>

using namespace std;

int main()
{
    long long int x, y, n, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y >> n;
        cout << (n - y) / x * x + y << endl;
    }
}