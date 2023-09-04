#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

using ll = long long;
using ull = unsigned long long;
// change vector<long long> to string, and the first place store sign
using BigNum = string;

template <class T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

string Plus(const BigNum &a, const BigNum &b);

string Time(const BigNum &a, const BigNum &b);

string Divide(const BigNum &a, const BigNum &b);

int main() {
    BigNum a;
    BigNum b;
    cin >> a >> b;
    cout << a << endl << b << endl;
    cout << Plus(a, b) << endl;
}

BigNum Plus(const BigNum &a, const BigNum &b) {
    if (a.length() < b.length() || (a.length() == b.length() && a < b))
        swap(a, b);
    BigNum pb = std::move(a);

    ull index = 0, sizeA = pb.length(), sizeB = b.length();
    char sign = (pb[0] == b[0]) ? 1 : -1;
    char carry = 0;
    for (index = sizeB - 1; index > 0; index--) {
        pb[index] += b[index] * sign + carry;
        if (pb[index] >= (10 + '0')) {
            carry = 1;
            pb[index] -= 10;
        } else if (pb[index] >= (0 + '0')) {
            carry = 0;
        } else {
            carry = -1;
            pb[index] += 10;
        }
    }
    for (index = sizeA - 1; index >= sizeB; index--) {
        pb[index] += carry;
        if (pb[index] >= (10 + '0')) {
            carry = 1;
            pb[index] -= 10;
        } else if (pb[index] >= (0 + '0')) {
            carry = 0;
        } else {
            carry = -1;
            pb[index] += 10;
        }
    }

    if (carry == 1) pb.insert(1, "1");
    return pb;
}

BigNum Time(const BigNum &a, const BigNum &b) {}

BigNum Divide(const BigNum &a, const BigNum &b) {}