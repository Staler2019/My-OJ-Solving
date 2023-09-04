// content: 1. find edge O(E) 2. find vertix of it O(EV)...final O(EV)
// optimization: "Dijkstra" priority_queue
//TODO

#include <iostream>
#include <queue>

using namespace std;

#define out 99999

struct S
{
public:
    int first;
    int second;

    S(int f, int s) : first(f), second(s){};

    bool operator<(struct S R)
    {
        return first > R.second;
    }
};

priority_queue<S> pq;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = m; i >= 0; --i)
    {
        cin >>
    }
}