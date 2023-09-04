#include <iostream>
#include <string>

using namespace std;

inline string smallPlus(const char &a, const char &b, const char &carry)
{
    string ans;
    ans.push_back((char)((a + b + carry - 48 * 3) / 10 + 48));
    ans.push_back((char)((a + b + carry - 48 * 3) % 10 + 48));
    return ans;
}

inline string smallPlus(const char &a, const char &carry)
{
    string ans;
    ans.push_back((char)((a + carry - 48 * 2) / 10 + 48));
    ans.push_back((char)((a + carry - 48 * 2) % 10 + 48));
    return ans;
}

string bigPlus(string a, string b)
{
    if (a.size() < b.size())
        a.swap(b);

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

inline string smallMulti(const char &a, const char &b, const char &carry) //max: 81, min: 01 + carry(9~0)
{
    string ans;
    ans.push_back((char)(((a - 48) * (b - 48) + carry - 48) / 10 + 48));
    ans.push_back((char)(((a - 48) * (b - 48) + carry - 48) % 10 + 48));
    return ans;
}

string bigMulti(string a, string b)
{
    if (a.size() < b.size())
        a.swap(b);

    int indexB = b.size() - 1;
    string ans = "0";

    for (int i = 0; indexB >= 0; indexB--, i++)
    {
        int indexA = a.size() - 1;
        char carry = '0';
        string tmp_ans = "";

        if (b.at(indexB) != '0')
        {
            for (int m = 0; indexA >= 0; indexA--, m++) //a * (digit)b
            {
                string tmp = smallMulti(a.at(indexA), b.at(indexB), carry);
                carry = tmp[0];
                tmp_ans = tmp[1] + tmp_ans;
            }

            if (carry != '0')
                tmp_ans = carry + tmp_ans;
        }

        string digits = "";
        if (tmp_ans != "")
        {
            for (int j = 0; j < i; j++)
            {
                digits += '0';
            }
        }
        else
        {
            tmp_ans = "0";
        }
        tmp_ans += digits;
        //cerr << " ans:" << ans << endl;
        ans = bigPlus(ans, tmp_ans);
        //cerr << "i:" << i << " tmp_ans=:" << tmp_ans << " ans:" << ans << endl;
    }

    return ans;
}

int main()
{
    string a, b;
    cin >> a >> b;

    //cerr << bigPlus(a, b) << endl;
    cout << bigMulti(a, b) << endl;
}