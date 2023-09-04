// OJ 1007
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const int maxn = 1e6 + 100;

int main() {
    //vector<int> begin(maxn, 1e9);
    //vector<int> end(maxn, 1e9);
    int n;
    cin >> n;

    vector<int> begin(n + 1);
    vector<int> end(n + 1);
    vector<int> dp(n + 1, 0);
    int greedy[maxn]{};
    int start[maxn]{};

    for (int i = 0; i < n+1;i++)

        for (int i = 1; i < n + 1; i++)
        {
            cin >> begin[i] >> end[i];
            dp[end[i]]++;
        }
    for (int i = 1; i < n + 1;i++) {
        for (int j = 1; j < i + 1; j++) {
            greedy[i] += max(dp[j], greedy[i]) + 1 ;
        }
    }
}