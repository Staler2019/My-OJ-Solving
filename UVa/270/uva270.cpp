#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void printVectorPair( vector<pair<int, int>>& vp) {
    for (auto& it : vp) cout << it.first << " " << it.second << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    char garbage;
    int cases;

    cin >> cases;
    cin.get(garbage);  // := getChar(); | a is a char
    cin.get(garbage);
    while (cases--) {
        vector<pair<int, int>> points;
        int a, b;

        while (cin >> a >> b) {
            cin.get(garbage);
            if (garbage == '\0') break;
            if (cin.peek() == '\n') break;
            points.emplace_back(a, b);
        }
        printVectorPair(points);
        cout << "-----------" << endl;
        system("pause");
    }
}