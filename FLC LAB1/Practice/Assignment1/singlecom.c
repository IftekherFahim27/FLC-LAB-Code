#include<stdio.h>
int main()
{
    FILE *ptr1,*ptr2;
    char c;
    int removeNewLine=0;
    int singleCom=0;
    int    slash=0;

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
            if(c=='\n' )
            {
                removeNewLine=1;
            }
            else
            {
                removeNewLine=0;
            }
            if(c=='/'){
                singleCom=1;
                slash=1;
            }
            if(c=='\n' && singleCom==1){
                singleCom=0;
            }



            if(removeNewLine==0 && singleCom==0)
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

