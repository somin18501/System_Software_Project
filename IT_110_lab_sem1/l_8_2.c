#include <stdio.h>
int multiply(int x[3][3], int y[3][3], int i, int j)
{
    int c = 0;
    for (int k = 0; k < 3; k++)
    {
        c = c + x[i][k] * y[k][j];
    }
    return c;
}
int main()
{
    int multiply(int x[3][3], int y[3][3], int i, int j);
    int a[3][3], b[3][3], c[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = multiply(a, b, i, j);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}