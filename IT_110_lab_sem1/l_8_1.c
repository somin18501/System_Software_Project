#include<stdio.h>
void swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
int main()
{
    void swap(int *x,int *y);
    int N;
    scanf("%d",&N);
    int a[N][N],b[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            b[i][j]=a[i][j];
        }
    }
    
    for(int i=0;i<N-1;i++)
    {
        for(int j=1;j<N;j++)
        {
            swap(&b[i][j],&b[j][i]);
        }
    }

    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d",b[i][j]);
        }
    }*/

    for(int i=0;i<N;i++)
    {
        int j;
        for(j=0;j<N;j++)
        {
            if(a[i][j]!=b[i][j])
            {printf("0");
            break;}
            if(i==N-1 && j==N-1)
            printf("1");
        }
        if(a[i][j]!=b[i][j])
        break;
    }
    
    return 0;
}