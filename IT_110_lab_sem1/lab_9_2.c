#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    char *str[N];
    for(int i=0;i<N;i++)
    {
        gets(str[i]);
    }
    int c=0;
    for(int i=0;i<N;i++)
    {
        int j=0;
        while(*(str[i]+j)!='\0')
        {
            if(*(str[i]+j)=='e')
            {
                c++;
            }
        }
    }
    printf("%d",c);


    return 0;
}  
/* 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 250
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d",&N);
    char *str[N];
        //str=(char*)malloc(MAX*sizeof(char));
    for(int i=0;i<N;i++)
    {
        str[i]=(char*)malloc(MAX*sizeof(char));
        fgets(str[i],MAX,stdin);
        //puts(str[i]);//gets(str[i]);//scanf("%[^\n]s",str[i]);
    }
    int c=0;
    for(int i=0;i<N;i++)
    {
        int j=0;
        while(*(str[i]+j)!='\0')
        {
            if(*(str[i]+j)=='e')
            {
                c++;
            }
            j++;
        }
    }
    printf("%d",c);
    return 0;
}
*/
