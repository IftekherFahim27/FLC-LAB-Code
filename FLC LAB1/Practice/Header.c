#include<stdio.h>
int main()
{
    FILE *ptr,*ptr2;
    int  lead=0,main=0;
    char c;

    ptr=fopen("Demo.txt","r");
    ptr2=fopen("Result.txt","w");
    if(ptr==NULL)
    {
        printf("File is Invalid \n");
    }
    else
    {
        while( (c=fgetc(ptr) ) != EOF)
        {
            if(c=='#')
            {
                lead=1;
            }
            if(c=='>')
            {
                fputc('\n',ptr2);
                lead=0;
                main=0;
            }
            if(main==1)
            {
                fputc(c,ptr2);
            }
            if (c=='<' && lead==1)
            {
                main=1;
            }


        }
    }
    fclose(ptr);
    fclose(ptr2);

    ptr2=fopen("Result.txt","r");
    while((c=fgetc(ptr2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(ptr2);
    return 0;
}
