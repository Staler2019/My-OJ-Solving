
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int n, t;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        //char pre = 0;
        long long int count = 0, left = 0, right = 0;
        char c = cin.get();
        for (int j = 0; j < n; j++){

            c = cin.get();
            if(c==41){
                right++;
            }
            else if(c==40){
                left++;

            }
            count = max(count, (right - left>0)?right-left:0);
            //pre = c;
        }
        c = cin.get();
        cout << count << endl;
    }
}