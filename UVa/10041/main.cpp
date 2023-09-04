// time:
//     start:1:16
//     end:1:41
//     edit:1:56
//     total:25min, 40min
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        vector<int> s(r);
        // use the only num -> 1st.use <set>(pointers use lots of time)
        //                     2nd.record input and find the same (<vector>)
        //                     3rd.record input and sort them (<vector>)
        //                     4th.use map and sort them (<vector>)
        // => 中位數 -> 1st.record inputs, sort them, and find the middle index
        while (r--) cin >> s[r];
        // for (int i = 0; i < s.size(); i++) cin >> s[i];
        sort(s.begin(), s.end());
        int ans = 0, middle = s[s.size() / 2];
        for (int i = 0; i < s.size(); i++) ans += abs(s[i] - middle);
        cout << ans << endl;
    }
}