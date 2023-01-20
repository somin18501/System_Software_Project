#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void swap(int *p1,int *p2);
int main()
{
/*
    int line;
    scanf("%d",&line);                               A
    int i;                                           A B 
    for(i=0;i<line;i++)                              A B C
    {
        int j,s=65;
        for(j=0;j<i;j++)
        {
            printf("%c ",s);
            s++;
        }
        printf("\n");
    }
*/
/*
    int i,len=5;
    for(i=1;i<=5;i++)
    {
        int j,c=5;
        for(j=0;j<i;j++)
        {
            printf("%d ",c);                   
            c--;
        }
        printf("\n");
    }
    // printf("\n");
    for(int i=0;i<4;i++)
    {
        int j=4-i,c=5;
        for(;j>0;j--)
        {
            printf("%d ",c);
            c--;
        }
        printf("\n");
    }
                                                                            5
                                                                            5 4
                                                                            5 4 3
                                                                            5 4 3 2
                                                                            5 4 3 2 1
                                                                            5 4 3 2
                                                                            5 4 3
                                                                            5 4
                                                                            5
*/
/*
    int sz;
    scanf("%d",&sz);
    int arr[sz],a[sz],d[sz];
    for(int i=0;i<sz;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<sz;i++)
    {
        a[i]=arr[i];
        d[i]=arr[i];
    }
    for(int i=0;i<sz;i++)
    {
        for(int j=i+1;j<sz;j++)
        {
            if(a[i]>a[j])                                // ascending sorting
            {
                swap(&a[i],&a[j]);
                j=i+1;
                continue;
            }
        }
    }
    for(int i=0;i<sz;i++)
    {
        for(int j=i+1;j<sz;j++)
        {
            if(d[i]<d[j])                                 // descending sorting
            {
                swap(&d[i],&d[j]);
                j=i+1;
                continue;
            }
        }
    }
    for(int i=0;i<sz;i++)
    {
        printf("%d\t%d\n",a[i],d[i]);
    }
*/
/*
    int r,c;
    scanf("%d %d",&r,&c);
    int a[r][c],at[c][r];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<c;i++)                                              // matrix transpose
    {
        for(int j=0;j<r;j++)
        {
            at[i][j]=a[j][i];
        }
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d ",at[i][j]);
        }
        printf("\n");
    }
*/
/*
    int a1[3][3],a2[3][3],a3[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a1[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a2[i][j]);                                        // matrix multiplication
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int c=0;
            for(int k=0;k<3;k++)
            {
                c+=a1[i][k]*a2[k][j];
            }
            a3[i][j]=c;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",a3[i][j]);
        }
        printf("\n");
    }
*/
    
    return 0;
}
void swap(int *p1,int *p2)
{
    int t;
    t=*p1;
    *p1=*p2;
    *p2=t;
}