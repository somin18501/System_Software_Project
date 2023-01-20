#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int findminint(int x, int *n)
{
    int a=32676;
    for(int i=0;i<x;i++)
    {
        if(*(n+i)<a)
        a=*(n+i);
    }
    return a;
}
float findminfloat(int x, float *n)
{
    float a=32676.0;
    for(int i=0;i<x;i++)
    {
        if(*(n+i)<a)
        a=*(n+i);
    }
    return a;
}
void changecase(int x, char *n)
{
    int A[26];
    int a[26];
    for(int k=0,i=65,j=97;k<26 && i<91 && j<123;i++,j++,k++)
    {
        A[k]=i;
        a[k]=j;
    }
    for(int k=0;k<26;k++)
    {
        for(int s=0;s<x;s++)
        {   
            if(*(n+s)==A[k])
            {
                *(n+s)=a[k];
            }
            else if(*(n+s)==a[k])
            {
                *(n+s)=A[k];
            }
        }
    }
    for(int c=0;c<x;c++)
    {
        printf("%c ",*(n+c));
    }

}

int main()
{
    void changecase(int x, char *n);
    float findminfloat(int x, float n[]);
    int findminint(int x, int n[]);
    int n1,n2,n3;
    scanf("%d %d %d",&n1,&n2,&n3);
    char word[n1];
    int num[n2];
    float deci[n3];
    void *ptr[3];
    scanf("%s",word);
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n3;i++)
    {
        scanf("%f",&deci[i]);
    }
    ptr[0]=&word;
    ptr[1]=&num;
    ptr[2]=&deci;
    for(int i=0;i<n1;i++)
    {
        if(*((char*)ptr[0]+i)!='\0')
        {
            printf("%c ",*((char*)ptr[0]+i));
        }
    }
    printf("\n");
    for(int i=0;i<n2;i++)
    {
        {
            printf("%d ",*((int*)ptr[1]+i));
        }
    }
    printf("\n");
    for(int i=0;i<n3;i++)
    {
        {
            printf("%f ",*((float*)ptr[2]+i));
        }
    }
    printf("\n");
    changecase(n1,word);
    printf("\n");
    printf("%d\n",findminint(n2,num));
    printf("%f\n",findminfloat(n3,deci));

    return 0;
}