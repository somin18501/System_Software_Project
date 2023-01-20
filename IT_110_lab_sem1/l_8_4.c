#include <stdio.h>

int main()
{
    int x, y, z, s;
    scanf("%d %d %d", &x, &y, &z);
    int a[x], b[y], c[z];
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < y; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < z; i++)
    {
        scanf("%d", &c[i]);
    }
    scanf("%d", &s);
    int *ptr[3];
    ptr[0] = a;
    ptr[1] = b;
    ptr[2] = c;
    for (int i = 0; i < x; i++)
    {
        if (*(ptr[0] + i) == s)
        {
            printf("yes ");
            break;
        }
        if (i == x -1)
        {
            printf("no ");
        }
    }
    for (int i = 0; i < y; i++)
    {
        if (*(ptr[1] + i) == s)
        {
            printf("yes ");
            break;
        }
        if (i == y - 1)
        {
            printf("no ");
        }
    }
    for (int i = 0; i < z; i++)
    {
        if (*(ptr[2] + i) == s)
        {
            printf("yes ");
            break;
        }
        if (i == z - 1)
        {
            printf("no ");
        }
    }
    return 0;
}