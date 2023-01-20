#include <stdio.h>
#include <stdlib.h>

/*
float* CreatFloatArray(int N)
{
    float *arr = (float*)malloc(N*sizeof(float));
    return arr;
}
void PrintFloatArray(float prt[], int N)
{
    for (int z = 0; z < N; z++)
    {
        printf("%f\n", prt[z]);
    }
}
*/
int main()
{
    float* CreateFloatArray(int N);
    void PrintFloatArray(float arr[],int N);

    /*void PrintFloatArray(float prt[], int N);
    float* CreatFloatArray(int N);
    int n;
    scanf("%d",&n);
    float* p = CreatFloatArray(n);
    float* q = p;
    for(int i = 0; i < n; i++)
    {
        scanf("%f", (q));
        q = q+1;
    }
    PrintFloatArray(p, n);*/
    int num;
    scanf("%d",&num);
    float *ptr=CreateFloatArray(num);
    for(int i=0;i<num;i++)
    {
        scanf("%f",ptr+i);
    }
    PrintFloatArray(ptr,num);
    return 0;
}
float* CreateFloatArray(int N)
{
    float *a=(float*)malloc(N*sizeof(float));
    return a;
}
void PrintFloatArray(float *arr,int N)
{
    for(int i=0;i<N;i++)
    {
        printf("%f\n",arr[i]);
    }
}