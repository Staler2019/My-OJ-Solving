// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1078
// reference: https://blog.csdn.net/mobius_strip/article/details/13762783
// Author: PY.Snow
// Date: 2020/11/12
// TODO: WA

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;

    while (cin >> n && n != 0) {
        vector<int> money;
        int total = 0;

        for (int i = 0; i < n; i++) {
            float input;

            cin >> input;
            input *= 100;
            money.emplace_back((int)ceil(input));
            total += (int)input;
        }
        // cerr << endl;

        cerr << "moneys: ";
        for (auto it = money.begin(); it != money.end(); it++)
            cerr << *it << " ";
        cerr << endl;

        int ave = total / n;
        int remain = total % n;
        cerr << "total: " << total << endl;
        cerr << "ave: " << ave << endl;
        cerr << "remain: " << remain << endl;
        int sum = 0;

        // for (auto it = money.begin(); it != money.end(); it++) {
        //     if (*it > ave) {
        //         sum += *it - ave;
        //         if (remain) {
        //             sum -= 1;
        //             remain--;
        //         }
        //     }
            // 下面多算了一次
            // if (*it > ave && remain) {
            //     sum += *it - (ave + 1);
            //     remain--;
            // } else
            //     sum += abs(*it - ave);
        // }

        // version 2
        for (auto it = money.begin(); it != money.end(); it++) {
            if (*it < ave) {
                sum += ave-*it;
                if (remain) {
                    sum--;
                    remain--;
                }
            }
        }
        cerr << "before sum: " << sum << endl;
        // sum += remain/2;
        cerr << "after sum: " << sum << endl;
        cerr << "----------------------" << endl;
        cout << "$" << fixed << setprecision(2) << (float)sum / 100 << endl;
    }
}