#include <stdio.h>
// snake and ladder game
int main()
{
    int s, n;
    s = 0;
    while (1)
    {
        printf("enter number 1-6 that appear on dice:");
        scanf("%d", &n);
        s = s + n;
        if (s == 17 || s == 54 || s == 62 || s == 64 || s == 87 || s == 93 || s == 96 || s == 98)
        {
            s = s - 15;
        }
        else if (s == 1 || s == 4 || s == 9 || s == 21 || s == 28 || s == 51 || s == 71 || s == 80)
        {
            s = s + 15;
        }
        else if (s == 100)
        {
            printf("win");
            break;
        }
        else
        {
            if (s > 100)
                s = s - n;
            continue;
        }
    }
    return 0;
}