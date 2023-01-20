#include<stdio.h>

int main(){
    int num,ratio,product;
    scanf("%d",&num);
    product=1;
    ratio=1;
    while(ratio<=num)
    {
        product=product*ratio;
        ratio=ratio+1;
    }
    printf("%d",product);
    return 0;
}