#include <stdio.h>
#include <stdlib.h>
void multiply(int x[3][3], int y[3][3],int *ptr)
{
    ptr=(int*)malloc(3*3*sizeof(int));
    int i,j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int c=0;
            for (int k = 0; k < 3; k++)
            {
                c = c + x[i][k] * y[k][j];
            }
            *(ptr+i*3+j)=c;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",*(ptr+i*3+j));
        }
        printf("\n");
    }
}
int main()
{
    void multiply(int x[3][3], int y[3][3],int *ptr);
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
    multiply(a,b,c);
    /*for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}