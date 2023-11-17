#include<stdio.h>
#include<string.h>

int identifier(char lexeme[])
{
    int i = 0;
    int l=0;
    int s=0;
    if(isalpha(lexeme[i]) || (lexeme[i]=='_'))
    {
        s=1;
        i++;
    }
    else
        s=0;
    l=strlen(lexeme);
    if(s)
    {
        for(; i<l; i++)
        {
            if(isalpha(lexeme[i]) || (lexeme[i]=='_') || isdigit(lexeme[i]))
            {
                s=1;
            }
            else
            {
                s=0;
                break;
            }
        }
    }
    return s;
}
int main()
{
    FILE *ptr1;
    char c;

    ptr1 = fopen("Input.txt","r");
    printf("Input:\n");
    while((c=getc(ptr1))!=EOF)
    {
        printf("%c",c);
    }
    fclose(ptr1);
    char lex[100];
    char unknown[100];
    int ln;
    int i=0;
    int sp = 0,ucheck = 0;

    ptr1 = fopen("Input.txt","r");
    while((c=fgetc(ptr1))!=EOF)
    {
        if(!isspace(c))
        {
            lex[i]=c;
            i++;
            sp=0;


        }
        else if(sp != 1)
        {
            sp=1;
            if(identifier(lex) == 1)
            {

                printf("%s is an identifier\t",lex);

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
            i = 0;
            memset(lex,0,strlen(lex));
        }
    }
    fclose(ptr1);

    if(ucheck)
        printf("\n\n Opps !!!! Unknown lexeme found  which is  ");
    for(int i=0; i<ln; i++)
    {
        printf("%c",unknown[i]);
    }

    printf("\n");
    return 0;
}
