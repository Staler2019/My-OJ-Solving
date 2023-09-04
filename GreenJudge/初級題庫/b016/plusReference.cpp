#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using BigNum = vector<long long>;
using ll = long long;

BigNum &trim(BigNum &b) {
    while (b.size() > 1 && b.back() == 0) b.pop_back();
    return b;
}

BigNum stob(const string &s) {
    BigNum b;
    for (auto c = s.rbegin(); c != s.rend(); c++) b.emplace_back(*c - '0');
    return trim(b);
}

void show(const BigNum &b) {
    for (auto i = b.rbegin(); i != b.rend(); i++) cout << *i << " ";
    cout << '\n';
}

int main() {
    string a = "123456789";
    BigNum bn = stob(a.substr(3));
    show(bn);
}