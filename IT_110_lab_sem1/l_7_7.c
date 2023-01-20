#include<stdio.h>
#include<math.h>
void normofvector(float *v,float *a1,int sz)
{
    float s=0;
    for(int i=0;i<sz;i++)
    {
        s=s+pow(*(v+i),2);
    }
    *a1=pow(s,0.5);
}
void dotpro(float *ans,float *x,float *y)
{
    *ans=*x**y;
}
int main()
{
    void dotpro(float *ans,float *x,float *y);
    void normofvector(float *v,float *a1,int sz);
    int s1,s2;
    scanf("%d %d",&s1,&s2);
    float V1[s1],a,ans;
    float V2[s2],b;
    for(int i=0;i<s1;i++)
    {
        scanf("%f",&V1[i]);
    }
    for(int i=0;i<s2;i++)
    {
        scanf("%f",&V2[i]);
    }
    normofvector(V1,&a,s1);
    normofvector(V2,&b,s2);
    dotpro(&ans,&a,&b);
    printf("%f",ans);
    return 0;
}