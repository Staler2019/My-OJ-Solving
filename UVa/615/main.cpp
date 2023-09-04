// TODO: 未完成，卡在資訊的建立，要兩種資料結構才能做判斷
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool dfs(int point, bool trace[][501], bool visit[]) // true: all visited, false doubly visited
{
    if (visit[point])
        return false;
    visit[point] = true;

    bool tree = true;
    for (int i = 1; i < 501; i++)
    {
        if (trace[point][i])
            tree = dfs(i, trace, visit);
        if (!tree)
            return false;
    }
    return true;
}

int main()
{
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a < 0 || b < 0)
            break;

        // make node: direction point
        map<int, int> node;
        map<int, vector<int>> trace;
        // bool trace[501][501]{};
        // bool visit[501]{};
        // bool tree = true;
        // trace[a][b] = true;
        // node[b]++;
        while (cin >> a >> b && a * b != 0)
        {
            if(node.find(a)==node.end())
                node[a] = 0;
            node[b]++;
            trace[a].emplace_back(b);
            // node[b]++;
            // trace[a][b] = true;
            // if (node[b] > 1)
            //     tree = false;
        }
        // find start
        // int start;
        // for (int i = 0;i <)
        //     tree |= dfs(start, trace, visit);
        // //

        // if (tree)
        //     cout <<

        /* trace[][]
        \ 1 2 3 4
        1     1
        2 1     1
        3
        4
        */
    }
}