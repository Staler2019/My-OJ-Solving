#include <iostream>
#include <string>

using namespace std;

inline string smallPlus(char a, char b, char carry)
{
    string ans;
    ans.push_back((char)((a + b + carry - 48 * 3) / 10 + 48));
    ans.push_back((char)((a + b + carry - 48 * 3) % 10 + 48));
    return ans;
}

inline string smallPlus(char a, char carry)
{
    string ans;
    ans.push_back((char)((a + carry - 48 * 2) / 10 + 48));
    ans.push_back((char)((a + carry - 48 * 2) % 10 + 48));
    return ans;
}

string bigPlus(string a, string b)
{
    int indexA = a.size() - 1, indexB = b.size() - 1;
    char carry = '0';
    string ans = "";

    for (; indexB >= 0; indexB--, indexA--)
    {
        //cerr << "indexA:" << indexA << " indexB:" << indexB << endl << " " << a[indexA] << " " << b[indexB]<<endl;
        string tmp = smallPlus(a.at(indexA), b.at(indexB), carry);
        carry = tmp[0];
        ans = tmp[1] + ans;
    }

    for (; indexA >= 0; indexA--)
    {
        //cerr << "indexA:" << indexA << endl << " " << a[indexA]<<endl;
        string tmp = smallPlus(a.at(indexA), carry);
        carry = tmp[0];
        ans = tmp[1] + ans;
    }

    if (carry != '0')
        ans = carry + ans;

    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;

    if (a.size() < b.size())
        a.swap(b);

    cout << bigPlus(a, b) << endl;
}
