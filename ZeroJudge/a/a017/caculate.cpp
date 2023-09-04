/**********************
 *Sorce: https://zerojudge.tw/ShowProblem?problemid=a017
 *Author: P.Y.Snow      *
 **********************/
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

string input;

int prec(char ch)
{
    switch (ch)
    {
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
    }
}
map<char, int> table = {mp('+', 1), mp('-', 1), mp('*', 2), mp('/', 2), mp('%', 2), mp('(', 3), mp(')', 0)};

int calculate(int posi)
{
    /*
    if the program run into '(', 
    call a recursion to calculate between '()'.
    */
}

int main()
{
    while (cin >> input)
    {
        int ans = calculate(0);
        cout << ans << endl;
    }
}