#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
using LL = long long;

int main() {
    int n, ain, start;
    cin >> n;
    vector<int> a(n);

    LL last = 0;
    LL ans = 0;
    for (int i = 0; i < n;i++){
        cin >> ain;
        a[i] = ain;
        if(last<=0){
            last = ain;
            start = i + 1;
        }
        else {
            last += ain;
        }
		ans = (ans>last)?ans:last;
    }
    for (int i = 0; i < start;i++){
        ain = a[i];
        last += ain;
        if(last<0){
            break;
        }
		ans = (ans>last)?ans:last;
    }
    cout << ans;
}