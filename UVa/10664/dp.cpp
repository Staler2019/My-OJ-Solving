#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        vector<int> weight;
        int sum = 0;
        do {
            int tmp;
            cin >> tmp;
            sum += tmp;
            weight.emplace_back(tmp);
        } while (cin.peek() != '\n');
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < weight.size(); i++) {
            for (int j = sum; j >= weight[i]; j--) {
                if (dp[j - weight[i]]) dp[j] = 1;
            }
        }
        if (sum % 2 == 0 && dp[sum / 2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}