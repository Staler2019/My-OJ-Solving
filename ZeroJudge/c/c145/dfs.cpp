//modified from b554
//TODO
#include <iostream>

using namespace std;

const int NUM = 11;

#define max(a, b) (a > b) ? a : b

void dfs(int &maximum, int visit[NUM][NUM], const int &n, const int &m, int pre_i, int pre_j, int direction)
{
    int stored_max = maximum, tmp_max;
    //cerr << "maximum:" << maximum << " _i:" << pre_i << " _j:" << pre_j << endl;

    if ((pre_i > 0) && direction != 1)
    {
        if (visit[pre_i - 1][pre_j] != 0)
        {
            tmp_max = stored_max;
            tmp_max += 1;
            visit[pre_i - 1][pre_j] = 0;
            dfs(tmp_max, visit, n, m, pre_i - 1, pre_j, 1);
            visit[pre_i - 1][pre_j] = 1;
            maximum = max(maximum, tmp_max);
        }
    }
    if ((pre_i < n - 1) && direction != 2)
    {
        if (visit[pre_i + 1][pre_j] != 0)
        {
            tmp_max = stored_max;
            tmp_max += 1;
            visit[pre_i + 1][pre_j] = 0;
            dfs(tmp_max, visit, n, m, pre_i + 1, pre_j, 2);
            visit[pre_i + 1][pre_j] = 1;
            maximum = max(maximum, tmp_max);
        }
    }
    if ((pre_j > 0) && direction != 3)
    {
        if (visit[pre_i][pre_j - 1] != 0)
        {
            tmp_max = stored_max;
            tmp_max += 1;
            visit[pre_i][pre_j - 1] = 0;
            dfs(tmp_max, visit, n, m, pre_i, pre_j - 1, 3);
            visit[pre_i][pre_j - 1] = 1;
            maximum = max(maximum, tmp_max);
        }
    }
    if ((pre_j < m - 1) && direction != 4)
    {
        if (visit[pre_i][pre_j + 1] != 0)
        {
            tmp_max = stored_max;
            tmp_max += 1;
            visit[pre_i][pre_j + 1] = 0;
            dfs(tmp_max, visit, n, m, pre_i, pre_j + 1, 4);
            visit[pre_i][pre_j + 1] = 1;
            maximum = max(maximum, tmp_max);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int visit[NUM][NUM]{}; //1:unvisited 0:visited
    // 不加這段就錯了 why?? 大的一定要在前面
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visit[i][j] = 1;
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
    visit[0][0] = 0;
    dfs(maximum, visit, n, m, 0, 0, 0);
    cout << maximum << endl;
}