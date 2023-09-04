#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> weight(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> weight[i];
            sum += weight[i];
        }

        int halfSum = sum / 2, halfN = n / 2;
        vector<ll> dp(halfSum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = halfSum; j >= weight[i]; j--)
                dp[j] |= dp[j - weight[i]] << 1LL;
        }

        if (n & 1) {
            while (!(dp[halfSum] & (1LL << halfN)) &&
                   !(dp[halfSum] & (1LL << (halfN + 1))))
                halfSum--;
        } else {
            while (!(dp[halfSum] & (1LL << halfN))) halfSum--;
        }
        cout << halfSum << " " << sum - halfSum << endl;
        if (tt) cout << endl;
    }
}