#include <iostream>
#include <string>
using namespace std;

void dfs(int s, int l, const int &n, const int &m, string str)
{
    if (s == n && l == m)
    {
        cout << str << endl;
        return;
    }
    else
    {
        if (s < n)
            dfs(s + 1, l, n, m, str + "S");
        if (l < m)
            dfs(s, l+1, n, m, str + "L");
        return;
    }
    cerr << "ERROR";
    return;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        dfs(0, 0, n, m, "");
        cout << endl;
    }
}