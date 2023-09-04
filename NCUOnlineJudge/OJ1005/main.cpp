#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

#define endl '\n'
typedef pair<int, int> PII;

int n;

int BS(PII a[])
{
    int L = 0;
    int R = n-1;

    int find;
    cin >> find;

    while (L <= R)
    {
        int M = (L + R) / 2;
        if (a[M].first == find)
        {
            return a[M].second;
        }
        else if (a[M].first > find)
        {
            R = M - 1;
        }
        else
        {
            L = M + 1;
        }
    }
    return -1;
}

int main()
{
    // opti
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> n;
    PII a[n+1];
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        a[i] = make_pair(in, i + 1);
    }
    sort(a, a + n);

    // find
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cout << BS(a) << endl;
    }
}