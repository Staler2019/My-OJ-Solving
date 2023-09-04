#include <cstdio>

int main()
{
    int in, divider = 2, divide_count = 0;
    scanf("%d", &in);
    while (true)
    {
        if (in == 1)
            break;

        if (in % divider == 0)
        {
            if (divide_count == -1)
            {
                printf(" * ");
                divide_count++;
            }
            in /= divider;
            divide_count++;
            if (divide_count == 1)
                printf("%d", divider);
        }
        else if (divide_count >= 1)
        {
            if (divide_count >= 2)
                printf("^%d", divide_count);
            divide_count = -1;
            divider++;
        }
        else
            divider++;
    }
    if (divide_count >= 2)
        printf("^%d", divide_count);
}