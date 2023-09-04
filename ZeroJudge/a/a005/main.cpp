#include <stdio.h>

int main()
{
    int t, a[4];
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        for (auto &j : a)
            scanf("%d", &j);
        for (auto &j : a)
            printf("%d ", j);
        int ans;
        if ((a[3] - a[2]) == (a[2] - a[1]))
            ans = a[3] + (a[3] - a[2]);
        else
            ans = a[3] * (a[3] / a[2]);
        printf("%d\n", ans);
    }
}