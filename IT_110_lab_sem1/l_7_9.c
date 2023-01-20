#include<stdio.h>

int main()
{
    int s;
    scanf("%d",&s);
    int a[s];
    for(int i=0;i<s;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int j=0;j<11;j++)
    {
        int c=0;
        for(int i=0;i<s;i++)
        {
            if(a[i]==j)
            c=c+1;
        }
        printf("%d: %d\n",j,c);
    }
    return 0;
}