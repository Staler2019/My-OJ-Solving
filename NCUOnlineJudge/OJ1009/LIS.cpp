#include <iostream>
using namespace std;

#define max(a, b) ((a > b) ? a : b)
//#define INT_MAX 2147483647

int main() {
    int n;
    cin >> n;
    int h[n];
    for (int &i : h) cin >> i;
    int length{};
    //, tmp_length = 1;
    for (int i = 0; i < n - 1; i++) {
        cerr << "------" << h[i] << endl;
        /*int tmp_length = 1; // second try
        for (int j = i + 1; j < n; j++)
            if (h[i] <= h[j]) {
                tmp_length++;
                length = max(length, tmp_length);
                cerr << length << endl;
            }*/
        /*if (h[i] <= h[i + 1]) // first try
            tmp_length += 1;
        else {
            length = max(length, tmp_length);
            tmp_length = 1;
        }*/
    }
    // length = max(length, tmp_length);
    cout << n - length << endl;
}

/*int main() // pre try
{
    int n;
    cin >> n;
    int h[n];
    for (auto &i : h)
        cin >> i;

    int count = INT_MAX, curr{};
    for (int i = 0; i < n; i++)
    {
        int tmp_count = i;
        curr = h[i];
        for (int j = i; j < n; j++)
        {
            if (h[j] >= curr)
                curr = h[j];
            else
                tmp_count++;
        }
        cerr << tmp_count << " " << count << endl;
        count = min(count, tmp_count);
    }
    cout << count << endl;
}*/