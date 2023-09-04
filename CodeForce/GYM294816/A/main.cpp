#include <iostream>

using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans{};
        for (int i = l-1; i < r-m+1; i++) {
            if (t == s.substr(i, m)) ans++;
        }
        cout << ans << endl;
    }
}