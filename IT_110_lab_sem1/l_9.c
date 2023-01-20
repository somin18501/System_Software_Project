#include<stdio.h>
#include<math.h>
int main(){
    int sum,count,num;
    sum=0;
    count=1;
    scanf("%d",&num);
    while(count<=num)
    {
        sum=sum+pow(count,3);
        count=count+1;
    }
    printf("%d",sum);
    return 0;
}