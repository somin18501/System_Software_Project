#include<stdio.h>
int creatfloatarry(int n)
{
    float *p;
    p=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
    {
        scanf("%f",p+i);
    }
}
void printfloatarry(int creatfloatarry(int n),int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%f\n",*(p+i));
    }
}
int main()
{
    int creatfloatarry(int n);
    void printfloatarry(int creatfloatarry(int n),int n);
    int n;
    scanf("%d",&n);
    printfloatarry(creatfloatarry(n),n);
    return 0;
}