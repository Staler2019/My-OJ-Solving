#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c, tmp;
    cin >> n >> c;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        a[i] = tmp;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        b[i] = tmp;
    }

    bool ele = false;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cout << count << " ";

        if (ele == true && a[i] >= b[i])// && a[i] < b[i] + c
        {
            count += b[i];
        }
        else if (a[i] < b[i] + c && ele == true )//  && ele == false
        {
            ele = false;
            count += a[i];
        }
        else if(a[i] < b[i] + c && ele == false ) {
            ele = false;
            count += a[i];
        }
        else
        {
            count = count + b[i] + c;
            ele = true;
        }
    }
    cout << count;
}