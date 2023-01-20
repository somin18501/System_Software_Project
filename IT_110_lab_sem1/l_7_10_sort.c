#include<stdio.h>
void swapR(int *n1,int *n2)
{
    int t;
    t=*n1;
    *n1=*n2;
    *n2=t;
}
int main()
{
    void swapR(int *n1,int *n2);
    int s;
    scanf("%d",&s);
    int a[s];
    for(int i=0;i<s;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<s;i++)
    {
        for(int j=i+1;j<s;j++)
        {
            if(a[i]>a[j])
            {
                swapR(&a[i],&a[j]);
                j=i+1;
                continue;
            }

        }
    }
    for(int i=0;i<s;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}