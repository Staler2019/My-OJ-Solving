//TODO
#include <iostream>

using namespace std;

const int NUM = 6;

inline int max(const int &a,const int &b){
    return (a > b) ? a : b;
}

int dfs(const int &x, const int &y, const int &n, bool visit[NUM][NUM])
{
    if (x < 0 || x >= n || y < 0 || y >= n || (!visit[x][y]))
        return 0;
    else
    {
        //cerr << "x:" << x << " y:" << y << endl;
        visit[x][y] = false;
        int c1 = dfs(x + 1, y, n, visit) + 1;
        int c2 = dfs(x - 1, y, n, visit) + 1;
        int c3 = dfs(x, y + 1, n, visit) + 1;
        int c4 = dfs(x, y - 1, n, visit) + 1;
        //cerr << "c1:" << c1 << " c2:" << c2 << " c3:" << c3 << " c4:" << c4 << endl;
        visit[x][y] = true;
        return max(max(c1, c2), max(c3, c4));
    }
}

int main()
{
    int n;
    bool visit[NUM][NUM];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin.get();
        for (int j = 0; j < n; j++)
        {
            visit[i][j] = (bool)(cin.get() - '0');
        }
    }

    cout << dfs(0, 0, n, visit) << endl;
}