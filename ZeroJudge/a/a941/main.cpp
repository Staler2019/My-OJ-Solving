// my method is not counting sort
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int r;
        cin >> r;
        int s[30005]{};
        for (int i = 0; i < r; i++) {
            int tmp;
            cin >> tmp;
            s[tmp]++;
        }
        int mid = {};
        for (ll sum = 0, index = 0; index < 30001; index++) {
            sum += s[index];
            if (s[index]) {
                mid = index;
            }
            if (sum >= (r + 1) / 2) break;
        }
        ll ans{};
        for (int i = 0; i < 30001; i++) {
            ans += abs(i - mid) * s[i];
        }
        cout << ans << " " << mid << endl;
        /*map<ll, ll> s; TRY 1
        for (ll i = 0; i < r; i++) {
            ll tmp;
            cin >> tmp;
            s[tmp]++;
        }*/
        /*for (auto it = s.begin(); it != s.end(); it++)
            cerr << it->first << " " << it->second << endl;
        sort(s.begin(), s.end());*/ // map sets keys sorted to default establishment
        /*auto middleIt = s.begin(); TRY 1
        for (ll i = 0;; middleIt++) {
            i += middleIt->second;
            if (i > (r + 1) / 2) break;
        }
        middleIt--;
        //cerr << middleIt->first << " " << middleIt->second << endl;
        ll ans{};
        for (auto it = s.begin(); it != s.end(); it++) {
            ans += abs(it->first - middleIt->first) * it->second;
        }
        cout << ans << " " << middleIt->first << endl;*/
    }
}