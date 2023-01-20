#include<stdio.h>
void found(int *p,int sz,int x)
{
    for(int i=0;i<sz;i++)
    {
        if(*(p+i)==x)
        {printf("%d\n",i);
        break;}
        else
        {
            if(i==(sz-1))
        {printf("-1");}
        }
        
        
    }
}
int main(){
    void found(int *p,int sz,int x);
    int sz,x;
    scanf("%d",&sz);
    int a[sz];
    for(int i=0;i<sz;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    found(a,sz,x);
    return 0;
}