#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int count = 0;
        int mod = 0;
        do {
            mod = (mod * 10 + 1) % n;
            count++;
        } while (mod);
        cout << count << endl;
    }
}