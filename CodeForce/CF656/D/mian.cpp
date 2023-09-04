#include <bits/stdc++.h>

using namespace std;

string s = "";

int change(string str, char c)
{
    int first_half = 0, second_half = 0;
    for (int i = 0; i < s.size() / 2;i++)
    {
        if(str[i]==c){
            first_half++;
        }
        if(str[i+str.size()]==c){
            second_half++;
        }
    }
    if(first_half>second_half){
        str = str.substr(str.size() / 2);
    }
    else if(first_half<second_half){
        str = str.substr(0, str.size() / 2);
    }
    else{
        if(change(s.sub))
    }
}

int main()
{
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        char c = 97;
        s = "";
        int count = 0;

        getline(cin, s);
        int begin = 0;
        int end = s.size();
        if (n == 1)
        {
            if (s[0] != 'a')
            {
                count = 1;
            }
        }
        else
        {
            while (true)
            {
                count += change(s, c);
                c += 1;
            }
        }
        cout << count << endl;
    }
}