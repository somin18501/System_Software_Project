#include<stdio.h>

int main(){
    int hour,op,count;
    count=1;
    while(count<=10)
    {
        scanf("%d",&hour);
        if(hour>40)
        {op=(hour-40)*12;
        printf("%d",op);}
        else
        {
            op=0;
            printf("%d",op);
        }
        
        count=count+1;

    }
    return 0;
}