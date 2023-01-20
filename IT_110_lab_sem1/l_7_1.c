#include<stdio.h>
void swapV(int n1,int n2)
{
    int t;
    t=n1;
    n1=n2;
    n2=t;
    printf("%d %d\n",n1,n2);
}
void swapR(int *n1,int *n2)
{
    int t;
    t=*n1;
    *n1=*n2;
    *n2=t;
}
float rectangleV(float a,float b)
{
    float area;
    area=a*b;
    return area;
}
float rectangleR(float *a,float *b,float *area)
{
    *area=*a**b;
}
void modify(long int *arr, int size, int n)
{
    for(int i=0;i<size;i++)
    {
        *(arr+i)=*(arr+i)*n;
    }
}
int main()
{
    //void modify(long int *arr, int size, int n);
    //float rectangleV(float a,float b);
    //float rectangleR(float *a,float *b,float *area);
    //void swapV(int n1,int n2);
    //void swapR(int *n1,int *n2);
    /*int n1;
    char c1;
    float f1;
    int *pi;
    char *pc;
    float *pf;
    scanf("%d %c %f",&n1,&c1,&f1);
    pi=&n1;
    pc=&c1;
    pf=&f1;
    printf("%u\n",&n1);
    printf("%u\n",&c1);
    printf("%u\n",&f1);
    printf("%d\n",*pi);
    printf("%c\n",*pc);
    printf("%f\n",*pf);*/
    /*int x,y;
    scanf("%d %d",&x,&y);
    swapV(x,y);
    swapR(&x,&y);
    printf("%d %d",x,y);*/
    /*float L,B,A;
    scanf("%f %f",&L,&B);
    A=rectangleV(L,B);
    printf("areaV:%f\n",A);
    rectangleR(&L,&B,&A);
    printf("areaR:%f\n",A);*/
    int sz,n1;
    //long int a[sz];
    scanf("%d",&sz);
    long int a[sz];
    for(int i=0;i<sz;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<sz;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    scanf("%d",&n1);
    modify(a,sz,n1);
    for(int i=0;i<sz;i++)
    {
        printf("%d ",*(a+i));
    }

    return 0;
}