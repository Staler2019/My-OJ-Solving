#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int toInt(char a)
{
    const pair<int, char> vp[] = {
        make_pair(1, 'I'),
        make_pair(5, 'V'),
        make_pair(10, 'X'),
        make_pair(50, 'L'),
        make_pair(100, 'C'),
        make_pair(500, 'D'),
        make_pair(1000, 'M'),
    };

    for (auto &i : vp)
    {
        if (a == i.second)
        {
            return i.first;
        }
    }
    //cerr << "ERROR in single roman to int";
    return -1;
}

int toInt(string a)
{
    int number = 0, last = 0, now;
    for (int i = 0; i < a.size(); i++)
    {
        now = toInt(a[i]);

        if (now > last)
        {
            number -= last;
        }
        else
        {
            number += last;
        }
        last = now;
    }
    number += now;
    return number;
}

string toRoman(int a)
{
    string s = "";
    const vector<pair<string, int>> vp = {make_pair("M", 1000),
                                          make_pair("CM", 900),
                                          make_pair("D", 500),
                                          make_pair("CD", 400),
                                          make_pair("C", 100),
                                          make_pair("XC", 90),
                                          make_pair("L", 50),
                                          make_pair("XL", 40),
                                          make_pair("X", 10),
                                          make_pair("IX", 9),
                                          make_pair("V", 5),
                                          make_pair("IV", 4),
                                          make_pair("I", 1)};
    int index = 0;
    while(a>0){
        if(a>=vp[index].second){
            a -= vp[index].second;
            //cerr << "a:" << a<<endl;
            s += vp[index].first;
        }else{
            index++;
        }
    }
    return s;
}

int main()
{
    string a, b;
    while (cin >> a)
    {
        if (a == "#")
            break;
        cin >> b;

        //cerr << a << " " << b << endl;
        int ans = abs(toInt(a) - toInt(b));
        //cerr << ans << endl;
        if(ans){ // !=0
        cout << toRoman(ans) << endl;
        }
        else{
            cout << "ZERO" << endl;
        }
    }
}