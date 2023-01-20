#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct player
{
    char name[64];
    int age;
    int testmatch;
    int runs;
};
struct player readrecord(void)
{
    struct player boy;
    scanf("%s",boy.name);
    scanf("%d",&boy.age);
    scanf("%d",&boy.testmatch);
    scanf("%d",&boy.runs);
    return boy;
}
void minmaxruns(struct player *p)
{
    int a1=0;
    int a2=30000;
    int i;
    for(i=0;i<10;i++)
    {
        if(((p+i)->runs)<a2)
        {
            a2=(p+i)->runs;
        }
        else if(((p+i)->runs)>a1)
        {
            a1=(p+i)->runs;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(a2==((p+i)->runs))
        {
            printf("%d %s ",a2,(p+i)->name);
            break;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(a1==((p+i)->runs))
        {
            printf("%d %s",a1,(p+i)->name);
            break;
        }
    }
}
void minmaxmatch(struct player *p)
{
    int a1=0;
    int a2=30000;
    int i;
    for(i=0;i<10;i++)
    {
        if(((p+i)->testmatch)<a2)
        {
            a2=(p+i)->testmatch;
        }
        else if(((p+i)->testmatch)>a1)
        {
            a1=(p+i)->testmatch;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(a2==((p+i)->testmatch))
        {
            printf("%d %s ",a2,(p+i)->name);
            break;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(a1==((p+i)->testmatch))
        {
            printf("%d %s",a1,(p+i)->name);
            break;
        }
    }
}
void minmaxavg(struct player *p)
{
    float a1=0;
    float a2=30000;
    int i;
    for(i=0;i<10;i++)
    {
        float d;
        d=(float)((p+i)->runs)/((p+i)->testmatch);
        if(d<a2)
        {
            a2=d;
        }
        else if(d>a1)
        {
            a1=d;
        }
    }
    for(int i=0;i<10;i++)
    {
        float d;
        d=(float)((p+i)->runs)/((p+i)->testmatch);
        if(a2==d)
        {
            printf("%f %s ",a2,(p+i)->name);
            break;
        }
    }
    for(int i=0;i<10;i++)
    {   
        float d;
        d=(float)((p+i)->runs)/((p+i)->testmatch);
        if(a1==d)
        {
            printf("%f %s",a1,(p+i)->name);
            break;
        }
    }
}
void minmaxruns(struct player *p);
void minmaxmatch(struct player *p);
void minmaxavg(struct player *p);
struct player readrecord(void);
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    struct player p1[10];
    for(int i=0;i<10;i++)
    {
        p1[i]=readrecord();
    }
    minmaxruns(p1);
    printf("\n");
    minmaxmatch(p1);
    printf("\n");
    minmaxavg(p1);

    return 0;
}
