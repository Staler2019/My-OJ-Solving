// OJ 1020 by Mr. Lee Trun-Sie
#include <iostream>

using namespace std;
#define mod 1000000007

class matrixx;
matrixx matrix(int[][2], int[][2]);

class matrixx
{
public:
    int a[2][2]{};

    matrixx(){};
    matrixx(matrixx *aa)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                a[i][j] = aa->a[i][j];
            }
        }
    }

    matrixx zero()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                a[i][j] = 1;
            }
        }
        return this;
    }
    matrixx one()
    {
        zero();
        a[0][0] = 0;
        return this;
    }
    matrixx selfTimes()
    {
        return matrix(a, a);
    }
};

matrixx matrix(int a[][2], int b[][2]) // times
{
    matrixx tmp;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                tmp.a[i][j] += a[i][k] * b[k][j];
                tmp.a[i][j] %= mod;
            }
        }
    }
    return tmp;
}

matrixx p(int n)
{
    if (n == 0)
    {
        matrixx x;
        return x.zero();
    }
    else if (n == 1)
    {
        matrixx x;
        return x.one();
    }
    matrixx a = p(n / 2);
    if (n % 2 == 0)
    {
        matrixx x;
        return x.selfTimes();
    }
    else
    {
        matrixx x, y;
        return matrix(y.selfTimes().a, x.zero().a);
    }
}

int main()
{
    int n = 0, a = 0, b = 1, ans;
    cin >> n;
    matrixx output = p(n);
    ans = output.a[0][1];
    cout << ans;
}
