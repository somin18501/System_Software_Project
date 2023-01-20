/*#include <stdio.h>
// snake and ladder game
int main()
{
    int s1,s2,n1,n2;
    s1 = 0;
    s2 = 0;
    while (1)
    {
        printf("enter n1 1-6 that appear on dice:");
        scanf("%d", &n1);
        printf("enter n2 1-6 that appear on dice:");
        scanf("%d", &n2);
        if (n1 >= 1 && n1 <= 6 && n2 >= 1 && n2 <= 6)
        {
            s1 = s1 + n1;
            s2 = s2 + n2;
            if ((s1 == 17 || s1 == 54 || s1 == 62 || s1 == 64 || s1 == 87 || s1 == 93 || s1 == 96 || s1 == 98) && (s2 == 17 || s2 == 54 || s2 == 62 || s2 == 64 || s2 == 87 || s2 == 93 || s2 == 96 || s2 == 98))
            {
                s1 = s1 - 15;
                s2 = s2 - 15;
            }
            else if ((s1 == 1 || s1 == 4 || s1 == 9 || s1 == 21 || s1 == 28 || s1 == 51 || s1 == 71 || s1 == 80) && (s2 == 1 || s2 == 4 || s2 == 9 || s2 == 21 || s2 == 28 || s2 == 51 || s2 == 71 || s2 == 80))
            {
                s1 = s1 + 15;
                s2 = s2 + 15;
            }
            else if (s1 == 100)
            {
                printf("s1 win");
                break;
            }
            else if (s2 == 100)
            {
                printf("s2 win");
                break;
            }
            else
            {
                if (s1 > 100)
                    s1 = s1 - n1;
                continue;
                if (s2 > 100)
                    s2 = s2 - n2;
                continue;
            }
        }
        else
        {
            printf("enter valid number!\n");
            continue;
        }
    }
    return 0;
}*/
/*#include<stdio.h>

int main()
{
    char s=3;
    switch(s)
    {
        case 1:
        printf("diamond");
        case 2:
        printf("spade");
        default:
        printf("heart");
    }
    printf("clube");
    return 0;
}*/
/*#include<stdio.h>

int main()
{
    int i,k=2;
    switch(i=k+1)
    {
        case 1:
        printf("tailor");
        case 2:
        printf("tutor");
        default:
        printf("tramp");
    }
    return 0;
}*/
/*#include<stdio.h>

int main()
{
    int i;
    float k=0.6;
    switch(i=k+1)
    {
        case 1:
        printf("tailor");
        break;
        case 2:
        printf("tutor");
        break;
        default:
        printf("tramp");
    }

    return 0;
}*/
/*#include<stdio.h>

int main()
{
    int temp;
    scanf("%d",&temp);
    switch(temp<=20)
    {case 1:
    printf("true");
    break;
    case 0:
    printf("false");
    break;
    return 0;}
}*/
/*#include<stdio.h>

int main()
{
    int ch='a'+'b';
    switch(ch)
    {
        case 'a':
        case 'b':
        printf("yes");
        break;
        case 'A':
        printf("no");
        break;
        case 'b' + 'a':
        printf("yo");
        break;
        default:
        printf("yono");
    }
    
    return 0;
}*/
#include<stdio.h>

int main()
{
    
    return 0;
}