#include<stdio.h>
int main()
{
    FILE *ptr1,*ptr2;
    char c;
    int flagslash=0;
    int multi=0,single=0,newline=0;

    ptr1=fopen("Given.txt","r");
    ptr2=fopen("Output.txt","w");


    if(ptr1==NULL)
    {
        printf("File is not valid \n");
    }
    else
    {
        while((c=fgetc(ptr1) )!=EOF)
        {
            if(c=='/')
            {
                flagslash=1;
            }

            if(c =='*' && flagslash==1)
            {
                multi=1;
            }
            if(c=='/' && multi ==1)
            {
                multi=0;
            }

            if(c=='/' && flagslash==1)
            {
                single=1;
            }
            if(c=='\n' && single==1)
            {
                single=0;
            }
            if (c=='\n' )
            {
                newline=1;
            }
            else
            {
                newline=0;
            }

            if(multi==0 && single==0 && newline==0)
            {
                fputc(c,ptr2);

            }


        }



    }
    fclose(ptr1);
    fclose(ptr2);

    ptr2=fopen("Output.txt","r");
    while((c=fgetc(ptr2))!=EOF )
    {
        printf("%c",c);
    }
    fclose(ptr2);
    return 0;

}


