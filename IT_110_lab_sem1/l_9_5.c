#include<stdio.h>
#include<math.h>
int main(){
    int n,num,c,a=0,b=0,d=0;
    scanf("%d",&n);
    c=1;
    while(c<=n)
    {
        scanf("%d",&num);
        if(num>0)
        {a=a+1;}
        else if (num<0)
        {b=b+1;}
        else
        {d=d+1;}
        c=c+1;
    }
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d",d);

    return 0;
}