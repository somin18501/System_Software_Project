#include<stdio.h>

int main(){
    int count,a,b,c,d;
    count=1;
    while(count<=500)
    {
        a=count%10;
        b=(count%100-a)/10;
        c=(count-count%100)/100;
        d=c*c*c+b*b*b+a*a*a;
        if(d==count)
        printf("%d\n",d);
        count=count+1;
    }
    return 0;
}