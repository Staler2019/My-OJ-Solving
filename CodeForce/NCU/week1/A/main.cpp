#include <iostream>
using namespace std;

int main() {
    int w;
    cin >> w;
    if (w % 2 || w < 4)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}