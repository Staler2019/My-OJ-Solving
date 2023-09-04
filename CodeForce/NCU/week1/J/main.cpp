#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (a && b) {
        if (b > a) swap(a, b);
        a %= b;
    }
    return b;
}

inline int lcm(int &a, int &b) {
    long long ans = a * b / gcd(a, b);
    return ans;
}

int main() {
    freopen("output.txt", "w", stdout);
    int tt;
    cin >> tt;
    while (tt--) {
        //
        cout << "Case " << tt << ":" << endl;
        int l, r;
        cin >> l >> r;
        int x = -1, y = -1;
        for (int i = l; i <= r - 1 && x == -1; i++) {
            //因式分解
        }
    }
}