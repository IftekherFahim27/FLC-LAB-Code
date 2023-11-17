#include<stdio.h>
#include<stdlib.h>

int main()
{

    FILE *ptr1, *ptr2;
    char c;


    ptr1=fopen("Bracket.c","r");
    ptr2=fopen("Result.txt","w");

    if(!ptr1)
    {
        printf("File is Invalid/n");
    }
    else
    {
        while((c=fgetc(ptr1))!=EOF)
        {
            if( ( c== '(' ) | ( c ==')' ) )
            {
                fputc(c,ptr2);
            }
        }

    }
       fclose(ptr1);
        fclose(ptr2);

      ptr2=fopen("Result.txt","r");

        while((c=fgetc(ptr1))!=EOF)
        {
            printf("%c",c);
        }

        fclose(ptr2);
        return 0;



}
