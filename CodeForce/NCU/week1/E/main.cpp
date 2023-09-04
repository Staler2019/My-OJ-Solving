#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get();
    map<char, int> mci;
    for (int i = 0; i < n; i++) mci[cin.get()]++;
    //cerr << mci['A'] << " " << mci['D'] << " " << n / 2 << endl;
    if (mci['A'] > n / 2)
        cout << "Anton" << endl;
    else if (mci['D'] > n / 2)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
}