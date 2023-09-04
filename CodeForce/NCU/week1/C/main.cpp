#include <iostream>
using namespace std;

int main() {
    int m, n,ans{};
    cin >> m >> n;
    while(m>1){
        m -= 2;
        ans += n;
    }
    while(n>1&&m==1){
        n -= 2;
        ans += 1;
    }
    cout << ans << endl;
}