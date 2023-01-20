/*
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void changecase(char *p);
void minint(int *p,int y);
void minfloat(float *p,int z);

int main()
{
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    char a[x];
    int b[y];
    float c[z];
    void *arr[3];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;
    for(int i=0;i<x;i++)
    {
        scanf("\n%c",&a[i]);
    }
    for(int i=0;i<y;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<z;i++)
    {
        scanf("%f",&c[i]);
    }
    for(int i=0;i<x;i++)
    {
        printf("%c ",*((char *)arr[0]+i));
    }
    printf("\n");
    for(int i=0;i<y;i++)
    {
        printf("%d ",*((int *)arr[1]+i));
    }
    printf("\n");
    for(int i=0;i<z;i++)
    {
        printf("%f ",*((float *)arr[2]+i));
    }
    printf("\n");
    changecase(a);
    for(int i=0;i<x;i++)
    {
        printf("%c ",*((char *)arr[0]+i));
    }
    printf("\n");
    minint(b,y);
    printf("\n");
    minfloat(c,z);
    return 0;
}
void changecase(char *p)
{
    int i=0;
    while(*(p+i)!='\0')
    {
        if(*(p+i)>=65 && *(p+i)<=90)
        {
            *(p+i)+=32;
        }
        if(*(p+i)>=97 && *(p+i)<=122)
        {
            *(p+i)-=32;
        }
        i++;
    }
}
void minint(int *p,int y)
{
    int c=32678;
    for(int i=0;i<y;i++)
    {
        if(*(p+i)<c)
        {
            c=*(p+i);
        }
    }
    printf("%d",c);
}
void minfloat(float *p,int z)
{
    float c=32678.0;
    for(int i=0;i<z;i++)
    {
        if(*(p+i)<c)
        {
            c=*(p+i);
        }
    }
    printf("%f",c);
}
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    int a[x],b[y],c[z];
    int *p[3];
    p[0]=a;
    p[1]=b;
    p[2]=c;
    for(int i=0;i<x;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<y;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<z;i++)
    {
        scanf("%d",&c[i]);
    }
    int s;
    scanf("%d",&s);
    for(int j=0;j<x;j++)
    {
        if(*(p[0]+j)==s)
        {
            printf("yes ");
            break;
        }
        else
        {
            printf("no ");
        }
    }
    for(int j=0;j<y;j++)
    {
        if(*(p[1]+j)==s)
        {
            printf("yes ");
            break;
        }
        else
        {
            printf("no ");
        }
    }
    for(int j=0;j<z;j++)
    {
        if(*(p[2]+j)==s)
        {
            printf("yes ");
            break;
        }
        else
        {
            printf("no ");
        }
    }
    
    return 0;
}