#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int t, tmp;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k, count = 0;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> d(k);
        for (int j = 0; j < k; j++)
        {
            d[j] = 0;
            //cerr << " " << d[j];
        }
        //cerr << endl << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            a[j] = tmp;
            d[tmp % k]+=1;
            //cerr << " " << d[tmp % k];
        }
        //cerr << endl << endl;
        int num = 0;
        for (int j = 1; j < k; j++){
            cerr << " j:" << j << " ans:" << d[j] << endl;
            if(d[j] >= d[num]){
                num = j;
                cerr << "  num:" << num << " d[num]:" << d[num] << endl;
            }
        }
        cout << (d[num]) * (k-1) + (num) + 1 << endl;
        cerr << endl;
    }
}