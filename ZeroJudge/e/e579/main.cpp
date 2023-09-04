#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<bool> day(n + 1);
        cin >> n;
        vector<int> party(n);
        for (auto &i : party) {
            cin >> i;
            int now = i;
            while (now < day.size()) {
                day[now] = true;
                now += i;
            }
        }
        int ans{};
        for (int i = 1; i < day.size(); i++) {
            if ((i - 6) % 7 == 0) continue;
            ans += day[i];
        }
        cout << ans << endl;
        /*for (int i = 1; i < day.size(); i++) {
            cout << day[i] << " ";
        }
        cout << endl;*/
    }
}
