#include <iostream>

using namespace std;

int main()
{
    long long int t, n;
    cin >> t;
    for (long long int i = 0; i < t; i++)
    {
        cin >> n;
        long long count = 0;
        while (true)
        {
            if (n == 1)
            {
                break;
            }
            if(n %3 != 0){
                count = -1;
                break;
            }
            if(n>=6 && n%6 ==0){
                //cerr << " " << n;
                n /= 6;
                count++;
                //cerr << " " << n << endl;
            }
            else{
                //cerr << " " << n;
                n *= 2;
                count++;
                //cerr << " " << n << endl;
            }
        }
        cout << count << endl;
    }
}