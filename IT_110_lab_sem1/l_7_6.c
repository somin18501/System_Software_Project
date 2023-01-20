#include<stdio.h>

int main(){
    int sz,p=0,n=0;
    scanf("%d",&sz);
    int a[sz];
    for(int i=0;i<sz;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<sz;i++)
    {
        if(a[i]>0)
        p=p+1;
        if(a[i]<0)
        n=n+1;
    }
    printf("positive: %d\n",p);
    printf("negative: %d",n);

    return 0;
}