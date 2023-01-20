#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct student
{
    char name[64];
    int r_no;
    int dept;
    char course[64];
    int yoj;
};

void data(struct student *p,int x,int k);
void printname(struct student *p,int x,int k);
struct student getdetail(void);
int main()
{
    int k;
    scanf("%d",&k);
    struct student std[k];
    for(int i=0;i<k;i++)
    {
        std[i]=getdetail();
    }
    int year;
    scanf("%d",&year);
    printname(std,year,k);
    int r;
    scanf("%d",&r);
    data(std,r,k);
    return 0;
}

struct student getdetail(void)
{
    struct student s1;
    scanf("%s",s1.name);
    scanf("%d",&s1.r_no);
    scanf("%d",&s1.dept);
    scanf("%s",s1.course);
    scanf("%d",&s1.yoj);
    return s1;
}

void printname(struct student *p,int x,int k)
{
    for(int i=0;i<k;i++)
    {
        if(x==((p+i)->yoj))
        {
            printf("%s\n",((p+i)->name));
        }
    }
}

void data(struct student *p,int x,int k)
{
    for(int i=0;i<k;i++)
    {
        if(x==((p+i)->r_no))
        {printf("%s\n",(p+i)->name);
        printf("%d\n",(p+i)->r_no);
        printf("%d\n",(p+i)->dept);
        printf("%s\n",(p+i)->course);
        printf("%d",(p+i)->yoj);}   
    }
}


