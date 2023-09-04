#include <iostream>
using namespace std;

int main() {
    int tt,ans{};
    cin >> tt;
    while (tt--) {
        int total{};
        for (int i = 0; i < 3; i++){
            bool tmp;
            cin >> tmp;
            total += tmp;
        }
        if (total > 1) ans++;
    }
    cout << ans << endl;
}