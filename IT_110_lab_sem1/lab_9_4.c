#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int stringcompare(char *s1,char *s2)
{
    char *t1=s1,*t2=s2;
    while(*t1!='\0' || *t2!='\0')
    {
        if(*t1!=*t2)
        {
            return *t1-*t2;
            break;
        }
        t1++;
        t2++;
        if(*t1=='\0' && *t2=='\0')
        {
            return 0;
        }
    }
}
void stringcopy(char *s1,char *s2)
{
    char *t1=s1;
    while(*s2!=0)
    {
        *t1=*s2;
        t1++;
        s2++;
    }
    while(*s1!='\0')
    {
        printf("%c",*s1);
        s1++;
    }
    
}
int main()
{
    int stringcompare(char *s1,char *s2);
    void stringcopy(char *s1,char *s2);

    char p1[]="somin";
    char p2[]="somil";
    char p3[]="somin";
    char p4[10];
    int i,k;
    i=stringcompare(p1,p3);
    k=stringcompare(p1,p2);
    printf("%d %d\n",k,i);
    stringcopy(p4,p1);
    /*char *t=p4;
    while(*t!=0)
    {
        printf("%c",*p4);
        t++;
    }*/

    return 0;
}