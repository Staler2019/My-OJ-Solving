//TODO
#include <iostream>

using namespace std;

const int NUM = 6;

#define max(a, b) (a > b) ? a : b

void dfs(int &maximum, int visit[NUM][NUM], const int &n, int pre_i, int pre_j)
{
    int stored_max = maximum, tmp_max;
    //cerr << "maximum:" << maximum << " _i:" << pre_i << " _j:" << pre_j << endl;

    if (pre_i > 0)
    {
        if (visit[pre_i - 1][pre_j] != 0)
        {
            tmp_max = stored_max;
            tmp_max += 1;
            visit[pre_i - 1][pre_j] = 0;
            dfs(tmp_max, visit, n, pre_i - 1, pre_j);
            visit[pre_i - 1][pre_j] = 1;
            maximum = max(maximum, tmp_max);
        }
    }
    if (pre_i < n - 1)
    {
        if (visit[pre_i + 1][pre_j] != 0)
        {
            tmp_max = stored_max;
            tmp_max += 1;
            visit[pre_i + 1][pre_j] = 0;
            dfs(tmp_max, visit, n, pre_i + 1, pre_j);
            visit[pre_i + 1][pre_j] = 1;
            maximum = max(maximum, tmp_max);
        }
    }
    if (pre_j > 0)
    {
        if (visit[pre_i][pre_j - 1] != 0)
        {
            tmp_max = stored_max;
            tmp_max += 1;
            visit[pre_i][pre_j - 1] = 0;
            dfs(tmp_max, visit, n, pre_i, pre_j - 1);
            visit[pre_i][pre_j - 1] = 1;
            maximum = max(maximum, tmp_max);
        }
    }
    if (pre_j < n - 1)
    {
        if (visit[pre_i][pre_j + 1] != 0)
        {
            tmp_max = stored_max;
            tmp_max += 1;
            visit[pre_i][pre_j + 1] = 0;
            dfs(tmp_max, visit, n, pre_i, pre_j + 1);
            visit[pre_i][pre_j + 1] = 1;
            maximum = max(maximum, tmp_max);
        }
    }
}

int main()
{
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
        dfs(maximum, visit, n, 0, 0);
        cout << maximum << endl;
    }
}