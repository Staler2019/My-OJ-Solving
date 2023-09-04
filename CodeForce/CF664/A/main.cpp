#include <stdio.h>

//using namespace std;

int main()
{
    int n, r, g, b, w;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int even = 0, zero = 0;
        scanf("%d%d%d%d", &r, &g, &b, &w);
        if (r % 2 == 0)
            even++;
        if (g % 2 == 0)
            even++;
        if (b % 2 == 0)
            even++;
        if (r == 0)
            zero++;
        if (g == 0)
            zero++;
        if (b == 0)
            zero++;
        /*if (w % 2 == 0)
            even++;*/
        if (even == 3 || (even == 2 && w % 2 == 0) || (even == 1 && w % 2 == 1 && zero != 1) || even == 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
