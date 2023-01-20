#include <stdio.h>
#include <string.h>
void inputname(char name[])
{
    int sz, k = 0, a1[25], a2[25];
    scanf("%s", name);
    sz = strlen(name);
    for (int i = 65; i < 91; i++)
    {
        int c = 0, j;
        for (j = 0; j < sz; j++)
        {
            if (name[j] == i)
            {
                c = c + 1;

                //printf("%c:%d, ", i, c);
            }
        }
        if (c != 0)
            {
                *(a1 + k) = i;
                *(a2 + k) = c;
                k++;
            }
        //if(c!=0)
        //{printf("%c:%d, ",i,c);}
    }
    for (int i = 0; i < k; i++)
    {
        printf("%c:%d ", *(a1 + i), *(a2 + i));
    }
    /*for(int t=0;t<k;t++)
    {
        for(int i=0;i<sz;i++)
        {
            if(*(a1+t)==name[i])
            {
                printf("%c:%d ",name[i],*(a2+t));
            }
        }
    }*/
}
int main()
{
    void inputname(char name[]);
    /*char Name[25];
    inputname(Name);*/
    char name[25];
    inputname(name);

    return 0;
}