#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n=0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if(i==j)
                continue;
            for (int k = 0; k < n; k++)
            {
                if (i != k && j != k)
                {
                    if ((a[i] - a[j]) % a[k] != 0)
                    {
                        cout << "no";
                        //cout << a[i] - a[j] << " " << a[k] << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "yes";
    return 0;
}