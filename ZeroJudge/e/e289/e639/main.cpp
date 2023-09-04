#include <iostream>
#include <string>
using namespace std;
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
int main() {
    string s;
    int cas = 1;
    while (cin >> s) {
        cout << "Case " << cas << ":" << endl;
        int n;
        cin >> n;
        while (n--) {
            int a, b;
            char now;
            bool ans = true;
            cin >> a >> b;
            now = s[min(a, b)];
            for (int i = min(a, b) + 1; i <= max(a, b) && ans; i++) {
                if (s[i] != now) ans = false;
            }
            if (ans)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cas++;
    }
}