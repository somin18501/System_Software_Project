#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct TD
{
    char name[64];
    char num[5];
};

struct TD addnewdirectory(void)
{
    struct TD entry;
    scanf("%s",entry.name);
    scanf("%s",entry.num);
    return entry;
}

void searchname(struct TD *p,int n,char *ptr[n])
{
    for(int i=0;i<n;i++)
    {
        int j,k;
        for(j=0;j<10;j++)
        {
            k=strcmp(ptr[i],(p+j)->name);
            if(k==0)
            {
                printf("1\n");
                break;
            }
        }
        if(j==10)
        {
            printf("0\n");
        }
    }
}
void searchname(struct TD *p,int n,char *ptr[n]);

int main()
{
    struct TD entryarr[10];
    for(int i=0;i<10;i++)
    {
        entryarr[i]=addnewdirectory();
    }
    int N,len;
    scanf("%d",&N);
    char *p[N];
    char n[24];
    char *p1;
    for(int i=0;i<N;i++)
    {
        scanf("%s",n);
        len=strlen(n);
        p1=(char*)malloc(len+1);
        strcpy(p1,n);
        p[i]=p1;
    }
    searchname(entryarr,N,p);

    return 0;
}