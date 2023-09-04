#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test(string a) { cout << " " << a << endl; }

vector<string> split(string str) {
    vector<string> ans;
    int start = 0, end = 1;
    for (; end < str.length(); end++) {
        if (str[end] == ' ') {
            ans.emplace_back(
                str.substr(start, end - start));
            start = ++end;  //在一個空白後必有字元
        }
    }
    ans.emplace_back(
        str.substr(start, str.length() - start));
    return ans;
}

void print(vector<string> vs) {
    for (string &s : vs) cout << s << endl;
}

int main() {
    string line;
    // case
    while (getline(cin, line)) {
        vector<string> sent = split(line);
    }
}