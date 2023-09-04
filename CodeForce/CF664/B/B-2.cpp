//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool visit[100][100]{};
int count = 0;

void print(int &x, int &y)
{
    count++;
    cout << x + 1 << " " << y + 1 << endl;
}

void dfs(int n, int m, int &sx, int &sy)
{
    visit[sx][sy] = true;
    print(sx, sy);

    if (sx < n - 2 && visit[sx + 1][sy] == false)
    {
        dfs(n, m, ++sx, sy);
        return;
    }
    if (sy < m - 2 && visit[sx][sy + 1] == false)
    {
        dfs(n, m, sx, ++sy);
        return;
    }
    if (sx > 1 && visit[sx - 1][sy] == false)
    {
        dfs(n, m, --sx, sy);
        return;
    }
    if (sy > 1 && visit[sx][sy - 1] == false)
    {
        dfs(n, m, sx, --sy);
        return;
    }

    if (sx < n - 1 && visit[sx + 1][sy] == false)
    {
        dfs(n, m, ++sx, sy);
        return;
    }
    if (sy < m - 1 && visit[sx][sy + 1] == false)
    {
        dfs(n, m, sx, ++sy);
        return;
    }
    if (sx > 0 && visit[sx - 1][sy] == false)
    {
        dfs(n, m, --sx, sy);
        return;
    }
    if (sy > 0 && visit[sx][sy - 1] == false)
    {
        dfs(n, m, sx, --sy);
        return;
    }
}

int main()
{
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    sx--, sy--;
    dfs(n, m, sx, sy);
    cerr << count << endl;
}