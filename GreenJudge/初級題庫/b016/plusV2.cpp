#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define cer(arg...) cerr << #arg << "=" << arg << endl;
#define bMod(a, b) (bool)(a % b)
#define T1 template <class T>
T1 ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i : v) os << i;
    os << endl;
    return os;
}
#undef T1

using ull = unsigned long long;
using BigNum = vector<ull>;
// 0~18,446,744,073,709,551,615; ull = 0xffff ffff ffff ffff;
const ull UNIT = 18;
const size_t USIZE = UNIT;

BigNum str2BigNum(const string &a) {
    BigNum num(a.size()/UNIT+bMod(a.size(),UNIT));
    for (ull i = a.length(); i > 0; i -= UNIT)
        a.push_back(stoull(&a[(i >= 18) ? i - 18 : 0], &USIZE, 10)) return
}

BigNum plus(const BigNum &a, const BigNum &b) { return }

// void printBigNum(BigNum &a) { cout << a << endl; }

int main() {
    string a, b;
    cin >> a >> b;
    BigNum Ba = str2BigNum(a), Bb = str2BigNum(b);
    cout << plus(Ba, Bb) << endl;
}