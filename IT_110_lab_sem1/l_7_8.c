#include <stdio.h>
void swapR(int *n1, int s)
{
    int *first;
    int *last;
    for (int i = s, j = 0; i > 0 && j < s / 2; i--, j++)
    {
        if (i >= 2)
        {
            first = n1 + j;
            last = n1 + i - 1;
            int t;
            t = *(n1 + j);
            *(n1 + j) = *(n1 + i - 1);
            *(n1 + i - 1) = t;
        }
    }
}
int main()
{
    void swapR(int *n1, int s);
    int s;
    scanf("%d", &s);
    int a[s], b[s];
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = (s - 1), j = 0; i >= 0, j < s; i--, j++)
    {
        b[j] = a[i];
    }
    for (int i = 0; i < s; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    swapR(a, s);
    for (int i = 0; i < s; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}