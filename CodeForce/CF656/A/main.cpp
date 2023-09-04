#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, cas = 0;
    cin >> t;

    unsigned int x[4]{};
    for (int i = 0; i < t; i++)
    {
        cas = 0;
        cin >> x[0] >> x[1] >> x[2];
        sort(x, x + 3);/*
        cerr << "----" << endl;
        for (int j = 0; j < 3;j++){
            cerr << x[j] << " ";
        }
        cerr << endl
             << "----" << endl;*/
        if (x[2] == x[1])
        {
            cas = 1;
            }
        if (x[0] == x[1] && x[0] == x[2])
        {
            cas = 2;
        }
        switch (cas)
        {
        case 0:
            cout << "NO" << endl;
            break;
        case 1:
            cout << "YES" << endl
                 << x[1] << " " << x[0] << " " << "1" << endl;
            break;
        case 2:
            cout << "YES" << endl
                 << x[0] << " " << x[0] << " " << x[0] << endl;
            break;
        }
    }
    //cerr << "end";
}