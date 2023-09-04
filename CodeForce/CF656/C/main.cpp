#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t;i++){
        cin >> n;
        vector<int> a(n);

        for (int j = 0; j < n;j++){
            cin >> a[j];
        }
        /*for (int j = 0; j < n;j++){
            cerr << a[j] << " ";
        }*/

            int end = 0;
        bool cas = false;
        for(int j = n-1; j > 0; --j){
            //cerr << "j=" << j << endl;
            if(cas){
                //cerr << "+" << endl;
                if(a[j-1]>a[j]){
                    end = j;
                    break;
                }
            }else{
                //cerr << "-" << endl;
                if(a[j-1]<a[j]){
                    cas = true;
                    //cerr << "!j=" << j << endl;
                }
            }
        }
        cout << end << endl;
    }
}