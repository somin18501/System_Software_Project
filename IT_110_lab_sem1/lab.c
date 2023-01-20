#include <stdio.h>

int main()
{
    int Ram, Shyam, Ajay;
    scanf("%d %d %d", &Ram, &Shyam, &Ajay);
    /*if (Ram < Shyam)
    {
        if (Ram < Ajay)
        {
            printf("Ram");
        }
        else if (Ram == Ajay)
        {
            printf("Ram\n");
            printf("Ajay");
        }
        else
        {
            printf("Ajay");
        }
    }
    else if (Ram > Shyam)
    {
        if (Shyam < Ajay)
        {
            printf("Shyam");
        }
        else if (Shyam == Ajay)
        {
            printf("Shyam\n");
            printf("Ajay");
        }
        else
        {
            printf("Ajay");
        }
    }
    else
    {
        if ((Ram == Shyam) < Ajay)
        {
            printf("Ram\n");
            printf("Shyam");
        }
        else if ((Ram == Shyam) > Ajay)
        {
            printf("Ajay");
        }
        else
        {
            printf("Ram\n");
            printf("Shyam\n");
            printf("Ajay");
        }
    }*/
    if (Ram < Shyam && Ram < Ajay)
    {
        printf("Ram");
    }
    else if (Ram < Shyam && Ram == Ajay)
    {
        printf("Ram\n");
        printf("Ajay");
    }
    else if (Ram > Shyam && Shyam < Ajay)
    {
        printf("Shyam");
    }
    else if (Ram > Shyam && Shyam == Ajay)
    {
        printf("Shyam\n");
        printf("Ajay");
    }
    else if (Ram == Shyam && Ram < Ajay)
    {
        printf("Ram\n");
        printf("Shyam");
    }
    else if (Ram == Shyam && Ram > Ajay)
    {
        printf("Ajay");
    }
    else if (Ram == Shyam && Ram == Ajay)
    {
        printf("Ram\n");
        printf("Shyam\n");
        printf("Ajay");
    }
    else
    {
        printf("Ajay");
    }

    return 0;
}