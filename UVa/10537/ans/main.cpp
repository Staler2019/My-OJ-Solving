#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const long long inf = (1ll << 62);
const int maxn = 110;
const int maxm = 1010;
ll dist[maxn], D;
bool vis[maxn];
int n, pre[maxn];

struct Node
{
    int v;
    ll dis;
    Node(int _v, ll _dis): v(_v), dis(_dis) {}
    bool operator < (const Node & r) const
    {
        return dis > r.dis;
    }
};

struct Edge
{
    int to, cost;
    Edge(int _to): to(_to) {}
    Edge(int _to, int _cost): to(_to), cost(_cost) {}
};

vector <Edge> edge[maxn];

void addedge(int u, int v)
{
    edge[u].push_back(Edge(v));
}

int char2int(char ch) // 字母转数字
{
    return ch - 'A';
}

char int2char(int x) // 数字转字母
{
    return char(x + 65);
}

ll Cost(int u) // 到达点u时下一个点v的花费
{
    if (u < 26) // 大写字母-城镇
        return dist[u] + (dist[u] + 18) / 19;
    return dist[u] + 1; // 村庄
}

void dijkstra(int s)
{
    for (int i = 0; i < maxn; ++i) // 点数，不为n
    {
        dist[i] = inf;
        vis[i] = false;
        pre[i] = -1;
    }
    dist[s] = D;
    priority_queue <Node> Q;
    Q.push(Node(s, dist[s]));
    while (!Q.empty())
    {
        Node tmp = Q.top();
        Q.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < edge[u].size(); ++i)
        {
            int v = edge[u][i].to;
            if (vis[v])
                continue;
            ll cost = Cost(u);
            if (dist[v] > cost) // 更新到达v点所需要的最少货物
            {
                pre[v] = u; // 记录前驱节点
                dist[v] = cost;
                Q.push(Node(v, dist[v]));
            }
            else if (dist[v] == cost && u < pre[v]) // 相等时取字典序最小的
                pre[v] = u;
        }
    }
}

int main()
{
    int s, t, kase = 0;
    char s1[2], s2[2];
    while (scanf("%d", &n))
    {
        if (n == -1)
            break;
        for (int i = 0; i < maxn; ++i) // 注意点的范围
            edge[i].clear();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s%s", s1, s2);
            addedge(char2int(s1[0]), char2int(s2[0]));
            addedge(char2int(s2[0]), char2int(s1[0]));
        }
        scanf("%lld%s%s", &D, s1, s2);
        s =  char2int(s1[0]), t = char2int(s2[0]);
        dijkstra(t); // 从终点开始逆序求最短路
        printf("Case %d:\n", ++kase);
        printf("%lld\n", dist[s]);
        while (pre[s] != -1) // 逆序输出
        {
            printf("%c-", int2char(s));
            s = pre[s];
        }
        printf("%c\n", int2char(t));
    }
    return 0;
}