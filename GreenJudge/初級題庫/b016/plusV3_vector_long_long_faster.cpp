#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define UNIT 18
#define UNIT_NUMBER (ll)1e18  // unit = 19

struct BigNum {
    vector<long long> number;
    // sign false:positive, true:negative
    bool sign = false;
    void neg() { sign = !sign; }
};

BigNum &trim(BigNum &b) {
    while (b.number.size() > 1 && b.number.back() == 0) b.number.pop_back();
    if (b.number.size() == 1 && b.number[0] == 0) b.sign = false;
    return b;
}

ull string2ll(const string &s) {
    ull number = 0;
    for (auto &c : s) number = number * 10 + c - '0';
    return number;
}

BigNum stob(const string &s) {
    BigNum b;
    // sign positive:false, negative:true
    if (s[0] == '-') b.sign = true;
    // number
    for (ll sub = s.length(); sub - b.sign > 0; sub -= UNIT) {
        if (sub - b.sign >= UNIT)
            b.number.emplace_back(string2ll(s.substr(sub - UNIT, UNIT)));
        else
            b.number.emplace_back(string2ll(s.substr(b.sign, sub - b.sign)));
    }
    return trim(b);
}

string ull2Fullstring(ull n) {
    string number = "";
    while (number.size() < UNIT) {
        number = (char)(n % 10 + '0') + number;
        n /= 10;
    }
    return number;
}
// TODO:if a memory block stores not fully for 18 elements
void show(const BigNum &b) {
    if (b.sign) cout << "-";
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
    BigNum plusBigNum = std::move(a);
    // plusBigNum.sign = a.sign;
    // calculate the number
    ull sizeA = plusBigNum.number.size(), sizeB = b.number.size(), index = 0;
    char sign = (plusBigNum.sign == b.sign) ? 1 : -1;
    char carry = 0;

    for (; index < sizeB; index++) {
        plusBigNum.number[index] += b.number[index] * sign + carry;
        if (plusBigNum.number[index] >= UNIT_NUMBER) {
            carry = 1;
            plusBigNum.number[index] -= UNIT_NUMBER;
        } else if (plusBigNum.number[index] >= 0) {
            carry = 0;
        } else {
            carry = -1;
            plusBigNum.number[index] += UNIT_NUMBER;
        }
    }
    for (; index < sizeA; index++) {
        plusBigNum.number[index] += carry;
        if (plusBigNum.number[index] >= UNIT_NUMBER) {
            carry = 1;
            plusBigNum.number[index] -= UNIT_NUMBER;
        } else if (plusBigNum.number[index] >= 0) {
            carry = 0;
        } else {
            carry = -1;
            plusBigNum.number[index] += UNIT_NUMBER;
        }
    }
    plusBigNum.number.emplace_back(carry);
    return trim(plusBigNum);
}

BigNum Minus(BigNum a, BigNum b) {
    b.neg();
    return Plus(a, b);
}

BigNum Time_(BigNum a, BigNum b) {

}

BigNum Divide(BigNum a, BigNum b) {}

int main() {
    string a, b;
    char oper;
    cin >> a >> oper >> b;
    BigNum ba = stob(a), bb = stob(b);
    switch (oper) {
        case '+':
            BigNum pb = Plus(ba, bb);
            break;
        case '-':
            pb = Minus(ba, bb);
            break;
        case '*':
            pb = Time(ba, bb);
            break;
        case '/':
            pb = Divide(ba, bb);
            break;
        default:
            cout << "the operator is wrong" << endl;
            return 0;
    }
    show(pb);
}