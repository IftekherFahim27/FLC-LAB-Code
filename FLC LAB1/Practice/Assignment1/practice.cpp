#include<bits/stdc++.h>
using namespace std;

int main()
{
    FILE *ptr1,*ptr2;
    char c;
    bool removeNewLine=false;

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
            if(c=='\n')
            {
                removeNewLine=true;
            }else{
                removeNewLine=false;
            }
            if(removeNewLine==false)
            {
                fputc(c,ptr2);
            }


        }



    }
    fclose(ptr1);
    fclose(ptr2);

    ptr2=fopen("Output.txt","r");
    while((c=fgetc(ptr2))!=EOF ){
        printf("%c",c);
    }
    fclose(ptr2);
    return 0;

}


