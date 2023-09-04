// OJ 1023
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxn 5005
vector<int> G[maxn];
bool visit[maxn];

void add_directed_edge(int u, int v){
    // u -> v
    G[u].push_back(v);
}

queue<int> q;
void bfs() {
    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        // cerr << u << endl;
        for (int x : G[u]) if (visit[x] == false) {
                visit[x] = true;
                q.push(x);
        }
    }
}

int main()
{
    int a,b;
    cin >> a >> b;


}