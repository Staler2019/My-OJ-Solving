//TODO
#include <iostream>

using namespace std;

const int NUM = 6;

#define max(a, b) ((a > b) ? a : b)

int dfs(const int &n, int visit[NUM][NUM], int _i, int _j)
{
    cerr << "_i:" << _i << " _j:" << _j << endl;

    int maximum = 0;
    int c[4]{};

    if (_i > 0)
    {
        if (visit[_i - 1][_j] != 0)
        {
            cerr << "<-";
            visit[_i - 1][_j] = 0;
            c[0] = dfs(n, visit, _i - 1, _j) + 1;
            visit[_i - 1][_j] = 1;
        }
    }
    if (_i < n - 1)
    {
        if (visit[_i + 1][_j] != 0)
        {
            cerr << "->";
            visit[_i + 1][_j] = 0;
            c[1] = dfs(n, visit, _i + 1, _j) + 1;
            visit[_i + 1][_j] = 1;
        }
    }
    if (_j > 0)
    {
        if (visit[_i][_j - 1] != 0)
        {
            cerr << "^";
            visit[_i][_j - 1] = 0;
            c[2] = dfs(n, visit, _i, _j - 1) + 1;
            visit[_i][_j - 1] = 1;
        }
    }
    if (_j < n + 1)
    {
        if (visit[_i][_j + 1] != 0)
        {
            cerr << "d";
            visit[_i][_j + 1] = 0;
            c[3] = dfs(n, visit, _i, _j + 1) + 1;
            visit[_i][_j + 1] = 1;
        }
    }
    maximum = max(max(c[0], c[1]), max(c[2], c[3]));
    cerr << "maximum:" << maximum << " _i:" << _i << " _j:" << _j << endl;
    return maximum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int visit[NUM][NUM]{}; //1:unvisited 0:visited
    for (int i = 0; i < n; i++)
    {
        cin.get();
        for (int j = 0; j < n; j++)
        {
            visit[i][j] = cin.get() - 48;
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cerr << visit[i][j] << " ";
        }
        cerr << endl;
    }
    system("pause");*/

    int maximum = 1;
    if (visit[0][0] == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        visit[0][0] = 0;
        dfs(n, visit, 0, 0);
        cout << maximum << endl;
    }
}