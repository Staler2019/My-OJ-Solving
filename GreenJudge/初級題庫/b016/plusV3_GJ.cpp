#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define UNIT 18
#define UNIT_NUMBER (ll)1e18  // unit = 19

struct BigNum {
    vector<long long> number;
    // si false:positive, true:negative
    bool si = false;
};

BigNum &trim(BigNum &b) {
    while (b.number.size() > 1 && b.number.back() == 0) b.number.pop_back();
    if (b.number.size() == 1 && b.number[0] == 0) b.si = false;
    return b;
}

ull string2ll(const string &s) {
    ull number = 0;
    for (ull c = 0; c < s.length();c++) number = number * 10 + s[c] - '0';
    return number;
}

BigNum stob(const string &s) {
    BigNum b;
    // si positive:false, negative:true
    if (s[0] == '-') b.si = true;
    // number
    for (ll sub = s.length(); sub - b.si > 0; sub -= UNIT) {
        if (sub - b.si >= UNIT)
            b.number.push_back(string2ll(s.substr(sub - UNIT, UNIT)));
        else
            b.number.push_back(string2ll(s.substr(b.si, sub - b.si)));
    }
    return trim(b);
}

string ull2Fullstring(ull n) {
    string number = "";
    while (number.size() < UNIT) {
        number = (char)(n % 10 + '0')+number;
        n /= 10;
    }
    return number;
}
// TODO:if a memory block stores not fully for 18 elements
void show(const BigNum &b) {
    if (b.si) cout << "-";
    auto i = b.number.rbegin();
    cout << *i;
    for (i++; i != b.number.rend(); i++) cout << ull2Fullstring(*i);
    cout << '\n';
}

BigNum Plus(BigNum a, BigNum b) {
    // check bigger
    if ((a.number.size() < b.number.size()) ||
        (a.number.size() == b.number.size() &&
         a.number.back() < b.number.back()))
        swap(a, b);
    // create number
    BigNum plusBigNum;
    plusBigNum.si = a.si;
    // calculate the number
    ull sizeA = a.number.size(), sizeB = b.number.size();
    char si = (a.si == b.si) ? 1 : -1;
    char carry = 0;

    for (ull i = 0; i < sizeB; i++) {
        ll number = a.number[i] + b.number[i] * si + carry;
        if (number >= UNIT_NUMBER) {
            carry = 1;
            number -= UNIT_NUMBER;
        } else if (number >= 0) {
            carry = 0;
        } else {
            carry = -1;
            number += UNIT_NUMBER;
        }
        plusBigNum.number.push_back(number);
    }
    for (ull i = sizeB; i < sizeA; i++) {
        ll number = a.number[i] + carry;
        if (number >= UNIT_NUMBER) {
            carry = 1;
            number -= UNIT_NUMBER;
        } else if (number >= 0) {
            carry = 0;
        } else {
            carry = -1;
            number += UNIT_NUMBER;
        }
        plusBigNum.number.push_back(number);
    }
    return trim(plusBigNum);
}

int main() {
    string a,b;
    cin >> a >> b;
    BigNum ba = stob(a), bb = stob(b);
    BigNum pb = Plus(ba, bb);
    show(pb);
}