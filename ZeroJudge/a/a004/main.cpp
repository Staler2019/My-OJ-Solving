#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        //Method 1太亂了,沒有增加速度也沒有讓邏輯清晰,不再使用
        /*if (n % 4) //n不被4整除
            cout << "平年" << endl;
        else if (n % 100) //n被4整除&&n不被100整除
            cout << "閏年" << endl;
        else if (!(n % 400)) //n被4整除&&n被100整除&&n被400整除
            cout << "閏年" << endl;
        else
            cout << "平年" << endl;*/
        if (n % 4 == 0 && n % 100 || n % 400 == 0)
            cout << "閏年" << endl;
        else
            cout << "平年" << endl;
    }
}