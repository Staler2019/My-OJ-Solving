#include <iostream>
using namespace std;

int main() {
    int x,ans{};
    cin >> x;
    ans = x / 5 + (bool)(x % 5);
    cout << ans << endl;
}