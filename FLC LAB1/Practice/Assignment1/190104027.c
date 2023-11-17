#include<stdio.h>
int main()
{

    FILE  *ptr1,*ptr2;
    char c;
    int enter=0;

    ptr1=fopen("Given.txt","r");
    ptr2=fopen("Output.txt","w");

    if(ptr1==NULL)
    {
        printf("File is not  exists \n");
    }
    else
    {
        while((c=fgetc(ptr1))!=EOF)
        {

            if(c=='\n' )
            {
                enter=1;
            }
            else
            {
                enter=0;
            }
            if(enter==0)
            {
                fputc(c,ptr2);
            }
        }
    }
    fclose(ptr1);
    fclose(ptr2);

    ptr2=fopen("Output.txt","r");
    while((c=fgetc(ptr2))!=EOF)
    {
        printf("%c",c);
    }
    return 0;

}
