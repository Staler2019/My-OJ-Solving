// https://codeforces.com/contest/1407/problem/A
#include <iostream>
#include <vector>
#define max(a, b) ((a > b) ? a : b)
#define pb push_back

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a, b;
        int an{}, bn{};
        for (int i = 0; i < n / 2; i++) {
            int tmp;
            cin >> tmp;
            an += tmp;
            a.pb(tmp);
            cin >> tmp;
            bn += tmp;
            b.bp(tmp);
        }
    }
}