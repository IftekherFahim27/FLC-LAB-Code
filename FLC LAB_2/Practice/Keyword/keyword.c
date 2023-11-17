#include<stdio.h>
#include<string.h>

int keyword(char lexeme[])
{
    FILE *kw;
    kw = fopen("Keyword.txt","r");
    char c,kwstr[100];
    int i=0,result=0;
    while((c = getc(kw))!=EOF)
    {
        if(!isspace(c))
        {
            kwstr[i] = c;
            i++;
        }
        else
        {
            for(int j=0; j<strlen(kwstr); j++)
            {
                if(kwstr[j]!=lexeme[j])
                {
                    result = 0;
                    break;
                }
                result = 1;
            }
            i = 0;
            if(result==1)
            {
                return result;
            }
            memset(kwstr,0,strlen(kwstr));
        }
    }
    fclose(kw);
    return result;
}

int main()
{

    char a[50]="fahim auto ";

    int sp=0;
    char lex[100];
    int val=10;

    char c;
    int ln=0;
    int m=0;
    ln=strlen(a);

    char unknown[100];
    int ucheck = 0;

    FILE *ptr1,*ptr2;
    ptr1 = fopen("test.txt","w");

    for(int i=0; i<ln; i++)
    {

        fprintf(ptr1,"%c",a[i]);
    }


    fclose(ptr1);


    ptr2= fopen("test.txt","r");
    while((c=fgetc(ptr2))!=EOF)
    {
        if(!isspace(c))
        {
            lex[m]=c;
            m++;
            sp=0;
        }
        else if(sp != 1)
        {
            sp = 1;
            if(keyword(lex) == 1)
            {
                printf("\nKeyword is found which %s\n",lex);
            }
            else
            {
              printf("%s is unknown ",lex);
                ucheck = 1;
                ln=strlen(lex);
                for(int i=0; i<ln; i++)
                {
                    unknown[i]=lex[i];
                }

            }
            m = 0;
            memset(lex,0,strlen(lex));

        }
    }
      fclose(ptr1);





    return 0;
}
