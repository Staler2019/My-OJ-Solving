//TODO
#include <bits/stdc++.h>

using namespace std;

void printPosi(int &i, int &j)
{
    cout << i + 1 << " " << j + 1 << endl;
}

void vx(bool *visit, int &n, int &sx, int &sy)
{
}

void vy(bool *visit, int &n, int &m)
{
    for (sy = 0; sy < m; sy += 2)
    {
        if (visit[sx][sy] == false)
        {
            visit[sx][sy] = true;
            printPosi(sx, sy);
        }
        if (sy + 2 == m && m % 2 == 0) // m is even
            sy = -1;
        else if (sy + 2 == m + 1 && m % 2 == 1) // m is odd
            sy = -1;
    }
}

int main()
{
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    bool visit[n][m]{};

    sx--;
    sy--;
    printPosi(sx, sy);
    visit[sx][sy] = true;
    for (sy = 0; sy < m; sy += 2)
    {
        if (visit[sx][sy] == false)
        {
            visit[sx][sy] = true;
            printPosi(sx, sy);
        }
        if (sy + 2 == m && m % 2 == 0) // m is even
            sy = -1;
        else if (sy + 2 == m + 1 && m % 2 == 1) // m is odd
            sy = -1;
    }
    for (sx = 0; sx < n; sx += 2)
    {
        for (sy = 0; sy < m; sy += 2)
        {
            if (visit[sx][sy] == false)
            {
                visit[sx][sy] = true;
                printPosi(sx, sy);
            }
            if (sy + 2 == m && m % 2 == 0) // m is even
                sy = -1;
            else if (sy + 2 == m + 1 && m % 2 == 1) // m is odd
                sy = -1;
        }
        if (sx + 2 == n && n % 2 == 0) // n is even
            sx = -1;
        else if (sx + 2 == n + 1 && n % 2 == 1) // n is odd
            sx = -1;
    }
}