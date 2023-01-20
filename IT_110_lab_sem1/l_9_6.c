#include<stdio.h>
#include<math.h>
int main(){
    int n,count,num;
    scanf("%d",&n);
    count=1;
    while(count<=n)
    {
        scanf("%d",&num);
        count=count+1;
    }
    printf("%d",maxf(num)-minf(num));
    return 0;
}