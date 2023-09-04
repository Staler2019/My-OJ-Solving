#include <iostream>
#include <vector>
using namespace std;
#define mp make_pair
#define pb push_back
using ll = long long;

#define MAX (ll)1e6

vector<ll> prime;
void setPrime();
ll getFactorSum(ll n);
int main() {
    setPrime();
    int c;
    cin >> c;
    while (c--) {
        ll n;
        cin >> n;
        ll ans = getFactorSum(n);
        if (ans == n)
            cout << "perfect";
        else if (ans > n)
            cout << "abundant";
        else
            cout << "deficient";
        cout << endl;
    }
}

void setPrime() {
    bool p[MAX + 1]{};
    for (int i = 2; i < MAX; i++) {

    }
}

ll getFactorSum(ll n) {}