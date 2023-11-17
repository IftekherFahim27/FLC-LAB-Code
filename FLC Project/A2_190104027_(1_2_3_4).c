#include<stdio.h>
#include<string.h>
void assign1()
{
    FILE *ptr,*ptr2;
    ptr = fopen("input1.txt","r");
    ptr2= fopen("output1.txt","w");

    int pf=1,parf=0,prif=1;
    char c,cb;
    while((c=getc(ptr))!=EOF)
    {
        if(c=='(')
            parf = 1;
        if(c=='"' && parf)
            prif = 0;
        if(c== ')')
        {
            prif = 1;
            parf = 0;
        }
        if(prif)
        {
            if (c == cb && c==' ')
                pf = 0;
            if(c=='/')
            {
                while(c=getc(ptr))
                {
                    if(c=='/')
                    {
                        while((c=getc(ptr) )!= '\n');
                        break;
                    }
                    else if(c=='*')
                        while((c=getc(ptr) )!= '/');
                    pf=0;
                    break;
                }
            }
        }
        if(c=='\n')
            continue;
        if(pf)
            fputc(c,ptr2);
        pf=1;
        cb = c;
    }
    fclose(ptr);
    fclose(ptr2);

    printf("Main Input File is \n");
    ptr2= fopen("input1.txt","r");
    while((c=getc(ptr2))!=EOF)
    {
        printf("%c",c);
    }


    printf("\nAfter Task 1  File is :\n");
    ptr2= fopen("output1.txt","r");
    while((c=getc(ptr2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(ptr2);

    printf("\n\n *********************** END OF TASK 1 ****************************** \n");

}

void assign2()
{

    int sep(char lexeme)
    {
        if(lexeme == '\'' || lexeme== ',' || lexeme == ';' || lexeme == '\"')
        {
            return 1;
        }

        return 0;
    }

    int par(char lexeme)
    {
        if(lexeme == '(' || lexeme == ')')
        {
            return 1;
        }

        return 0;
    }

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
    int op(char lexeme[])
    {
        FILE *op;
        op = fopen("Operator.txt","r");
        char c,opstr[100];
        int i=0,result=0;
        while((c = getc(op))!=EOF)
        {
            if(!isspace(c))
            {
                opstr[i] = c;
                i++;
            }
            else
            {
                for(int j=0; j<strlen(opstr); j++)
                {
                    if(opstr[j]!=lexeme[j])
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
                memset(opstr,0,strlen(opstr));
            }
        }
        fclose(op);
        return result;
    }
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
    int num(char lexeme[])
    {
        int i = 0;
        int l=0;
        int s=0;
        if(isdigit(lexeme[i]))
        {
            s=1;
            i++;
        }
        else if(lexeme[i]=='.')
        {
            s=2;
            i++;
        }
        else s=0;
        l=strlen(lexeme);
        if(s==1)
            for( ; i<l; i++)
            {
                if(isdigit(lexeme[i]))
                    s=1;
                else if(lexeme[i]=='.')
                {
                    s=2;
                    i++;
                    break;
                }
                else
                {
                    s=0;
                    break;
                }
            }
        if(s==2)
            if(isdigit(lexeme[i]))
            {
                s=3;
                i++;
            }
            else
                s=0;
        if(s==3)
            for(; i<l; i++)
            {
                if(isdigit(lexeme[i]))
                    s=3;
                else
                {
                    s=0;
                    break;
                }
            }
        if(s==3) s=1;
        return s;
    }

    FILE *ptr1,*ptr2;
    ptr1 = fopen("output1.txt","r");
    ptr2= fopen("Output2_1.txt","w");
    int i=1;
    char c,temp;
    printf("Input:\n");
    while((c=getc(ptr1))!=EOF)  //<
    {
        printf("%c",c);
        if(c == '<' || c == '>' || c == '!' || c == '=')
        {
            temp = c;
            c=getc(ptr1);
            printf("%c",c);
            if(c == '=')
            {
                fprintf(ptr2," %c%c ",temp,c); // <=
            }
            else if( c == '\'')
            {
                fprintf(ptr2," %c %c ",temp,c);
            }
            else
            {
                fprintf(ptr2," %c %c",temp,c);
            }
        }
        else if(c == ',' || c == ';' || c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == '"' || c == ')' || c == '\'')
        {
            fprintf(ptr2," %c ",c);
        }
        else
            fputc(c,ptr2);
    }
    fclose(ptr1);
    fclose(ptr2);
    ptr2= fopen("Output2_1.txt","r");
    printf("\nOutput Step 1:\n");
    while((c=getc(ptr2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(ptr2);

    ptr2= fopen("Output2_1.txt","r");
    ptr1 = fopen("Output2_2.txt","w");

    char lex[100];
    char unknown[100];
    int ln;
    i=0;
    int sp = 0,ucheck = 0;
    while((c=fgetc(ptr2))!=EOF)
    {
        if(!isspace(c))
        {
            lex[i]=c;
            i++;
            sp=0;
        }
        else if(sp != 1)
        {
            sp = 1;
            fputc('[',ptr1);
            if(keyword(lex) == 1)
            {
                fprintf(ptr1,"kw %s",lex);
            }
            else if(sep(lex[0]) == 1)
            {
                fprintf(ptr1,"sep %s",lex);
            }
            else if(identifier(lex) == 1)
            {
                fprintf(ptr1,"id %s",lex);
            }
            else if(num(lex) == 1)
            {
                fprintf(ptr1,"num %s",lex);
            }
            else if(op(lex) == 1)
            {
                fprintf(ptr1,"op %s",lex);
            }
            else if(par(lex[0]) == 1)
            {
                fprintf(ptr1,"par %s",lex);
            }
            else
            {
                fprintf(ptr1,"unkn %s",lex);
                ucheck = 1;
                ln=strlen(lex);
                for(int i=0; i<ln; i++)
                {
                    unknown[i]=lex[i];
                }
            }
            fprintf(ptr1,"] ");
            i = 0;
            memset(lex,0,strlen(lex));
        }
    }
    fclose(ptr2);
    fclose(ptr1);

    ptr2= fopen("Output2_2.txt","r");
    printf("\nOutput 2:\n");
    while((c=getc(ptr2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(ptr2);

    if(ucheck)
        printf("\n\n Opps !!!! Unknown lexeme found  which is  ");
    for(int i=0; i<ln; i++)
    {
        printf("%c",unknown[i]);
    }

    printf("\n");


    printf("\n\n *********************** END OF TASK 2 ****************************** \n");

}

void assign3()
{
    int tablei = 0;
    struct sTable
    {
        char name[20][20];
        char idType[20][20];
        char dataType[20][20];
        char scope[20][20];
        char value[20][20];
    } sTable;

    void insert(char n[], char iT[], char dT[], char scp[], char v[])
    {
        strcpy(sTable.name[tablei],n);
        strcpy(sTable.idType[tablei],iT);
        strcpy(sTable.dataType[tablei],dT);
        strcpy(sTable.scope[tablei],scp);
        strcpy(sTable.value[tablei],v);
        tablei++;
    }
    void set_attribute(char n[], char scp[], char v[])
    {
        int i;
        for(i=0; i<tablei; i++)
        {
            if(strcmp(sTable.name[i],n)==0 && strcmp(sTable.scope[i],scp)==0)
            {
                strcpy(sTable.value[i],v);
                break;
            }
        }
    }
    void frees()
    {
        int i;
        for(i = 0 ; i<tablei ; i++)
        {
            free(sTable.name[i]);
        }
    }

    int lookUp(char n[],char scp[])
    {
        int i;
        for(i = 0; i<tablei; i++)
            if(strcmp(sTable.name[i],n)==0)
            {
                if(strcmp(sTable.idType[i],"func")==0)
                {
                    return (i+1);
                }
                else if(strcmp(sTable.scope[i],scp)==0)
                {
                    return (i+1);
                }
            }

    }
    void display()
    {
        printf("\nSl.No.\tName\tId Type\tData Type\tScope\tValue\n-------------------------------------------------------\n");
        for(int i = 0; i<tablei ; i++)
        {
            printf("%d\t|%s\t|%s\t|%s\t\t|%s\t|%s\n",(i+1),sTable.name[i],sTable.idType[i],sTable.dataType[i],sTable.scope[i],sTable.value[i]);
        }
    }


    FILE *ptr,*ptr2;
    int inputi=0;
    char input[1500],c;
    char scp[20] = "global";
    int j;
    ptr = fopen("Output2_2.txt","r");
    printf("Input file:\n");
    while((c=getc(ptr))!=EOF)
    {
        printf("%c",c);
        input[inputi]=c;
        inputi++;
    }
    fclose(ptr);

    ptr2 = fopen("output3.txt","w");
    printf("\nStep 1:\n");

    for(int i = 0; i<inputi; i++)
    {
        if(input[i] == '[' && input[i+1]== 'i' && input[i+2]=='d' && input[i+3]==' ')
        {
            i+=4;
            j = 0;
            char id[20];
            while(input[i] != ']')
            {
                id[j] = input[i];
                i++;
                j++;
            }
            id[j] = '\0';
            printf("[id %s",id);
            fprintf(ptr2,"[id %s",id);

        }
        if(input[i]=='[')
        {
            printf("[");
            fputc('[',ptr2);
            while(input[i]!=' ')
                i++;
            i++;
        }

        printf("%c",input[i]);
        fputc(input[i],ptr2);
    }
    fclose(ptr2);

    for(int i = 0; i<inputi; i++)
    {
        if(input[i] == 'k' && input[i+1] == 'w' && input[i+3]!='r')
        {
            char dT[20],n[20],v[20];
            j=0;
            i+=3;
            while(input[i]!=']')
            {
                dT[j] = input[i];
                j++;
                i++;
            }
            dT[j] = '\0';
            i+=3;
            if(input[i]=='i' && input[i+1] == 'd' && input[i+2] == ' ')
            {
                i+=3;
                j=0;
                while(input[i] !=']')
                {
                    n[j] = input[i];
                    i++;
                    j++;
                }
                n[j] = '\0';

                i+=3;

                if(input[i] == 's' || input[i] == 'o')
                {
                    if(input[i] == 's')
                        insert(n,"var",dT,scp," ");
                    else
                    {
                        i+=10;
                        j = 0;
                        while(input[i] != ']')
                        {
                            v[j] = input[i];
                            j++;
                            i++;
                        }
                        v[j] = '\0';
                        insert(n,"var",dT,scp,v);
                    }
                }
                else
                {
                    i+=4;
                    if(input[i]==')')
                        insert(n,"var",dT,scp," ");
                    else
                    {
                        insert(n,"func",dT,"global"," ");
                        strcpy(scp,n);
                    }
                }
            }
        }
        else if(input[i]=='[' && input[i+1]=='i' && input[i+2] == 'd' && input[i+3]== ' ')
        {
            char n[20],v[20];
            i+=4;
            j = 0;
            while(input[i] != ']')
            {
                n[j] = input[i];
                j++;
                i++;
            }
            n[j]='\0';
            i+=3;
            if(input[i]=='o' && input[i+7] == 'n')
            {
                i+=10;
                j=0;
                while(input[i] != ']')
                {
                    v[j] = input[i];
                    j++;
                    i++;
                }
                v[j] = '\0';
                set_attribute(n,scp,v);
            }
        }
        else if(input[i]=='}')
        {
            strcpy(scp,"global");
        }
    }
    printf("\n\nStep 2:\n");
    display();
    strcpy(scp,"global");
    printf("\nStep 4: Modified token stream for Syntax Analysis: \n\n");
    ptr2 = fopen("output3_2.txt","w");
    for(int i = 0; i<inputi; i++)
    {
        if(input[i] == '[' && input[i+1]== 'i' && input[i+2]=='d' && input[i+3]==' ')
        {
            i+=4;
            j = 0;
            char id[20];
            while(input[i] != ']')
            {
                id[j] = input[i];
                i++;
                j++;
            }
            id[j] = '\0';
            printf("[id %d",lookUp(id,scp));
            fprintf(ptr2,"[id %d",lookUp(id,scp));
            if(input[i+3]=='p' && input[i+7]=='(' && strcmp(scp,"global") == 0)
                strcpy(scp,id);
        }
        if(input[i]=='[')
        {
            printf("[");
            fputc('[',ptr2);
            while(input[i]!=' ')
                i++;
            i++;
        }
        if(input[i] == '}')
            strcpy(scp,"global");
        printf("%c",input[i]);
        fputc(input[i],ptr2);
    }
    fclose(ptr2);

    printf("\n\n *********************** END OF TASK 3 ****************************** \n");

}
int taI = 0;
struct symbolTable
{
    char name[20][20];
    char idType[20][20];
    char dataType[20][20];
    char scope[20][20];
} sTable;

void insert(char n[], char iT[], char dT[], char scp[])
{
    strcpy(sTable.name[taI],n);
    strcpy(sTable.idType[taI],iT);
    strcpy(sTable.dataType[taI],dT);
    strcpy(sTable.scope[taI],scp);
    taI++;
}

int lookUp(char n[],char scp[])
{
    for(int i = 0; i<taI; i++)
        if(!strcmp(sTable.name[i],n))
        {

            if(!strcmp(sTable.idType[i],"func"))
                return (i+1);
            else if(!strcmp(sTable.scope[i],scp) || !strcmp(scp,"global") || !strcmp(sTable.scope[i],"global"))
            {
                return (i+1);
            }
        }
    return 0;
}
void display()
{
    printf("\nSl\tName\tId TYPE\tData Type\tScope\n-------------------------------------------------------\n");
    for(int i = 0; i<taI ; i++)
        printf("%d\t|%s\t|%s\t|%s\t\t|%s\t\n",(i+1),sTable.name[i],sTable.idType[i],sTable.dataType[i],sTable.scope[i]);
}


int error;
int id(char lex[])
{
    int i = 0,l,s;
    if(isalpha(lex[i]) || (lex[i]=='_'))
    {
        s=1;
        i++;
    }
    else
        s=0;
    l=strlen(lex);
    if(s)
    {
        for(; i<l; i++)
        {
            if(isalpha(lex[i]) || (lex[i]=='_') || isdigit(lex[i]))
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

void kwIdChecker(char inp[],int inpi)
{
    FILE *ptr;
    char c,word[20],kword[20],keyW[20]=" ",idW[20]=" ",linec[20];
    int j=0,kwf,idf,wf;
    char scope[20]="global";
    ptr = fopen("space_add.txt","w");
    for(int i=0; i<inpi; i++)
    {
        if(inp[i]=='(' || inp[i]==';' || inp[i]==',' || inp[i]==')' || inp[i]=='=' || inp[i]=='<')
            fprintf(ptr," %c ",inp[i]);
        else
            fputc(inp[i],ptr);
    }
    fclose(ptr);
    inpi=0;
    ptr= fopen("space_add.txt","r");
    while((c=fgetc(ptr))!=EOF)
    {
        inp[inpi] = c;
        inpi++;
    }
    fclose(ptr);
    for(int i=0; i<inpi; i++)
    {
        if(inp[i]=='\n')
        {
            strcpy(keyW," ");
            strcpy(idW," ");
            idf=0;
            kwf=0;
            i++;
            j=0;
            while(inp[i] != ' ')
            {
                linec[j] = inp[i];
                i++;
                j++;
            }
            linec[j] = '\0';
            continue;
        }
        if(inp[i]=='}')
        {
            strcpy(scope,"global");
        }
        j=0;
        while(inp[i] != ' ')
        {
            word[j] = inp[i];
            i++;
            j++;
        }
        word[j] = '\0';
        wf = 1;

        ptr = fopen("keyword.txt","r");
        while(fscanf(ptr,"%s ",kword)==1)
        {
            if(!strcmp(kword,word))
            {
                if(kwf && !strcmp(word,keyW) && strcmp(word,"else"))
                {
                    printf("\nDuplicate keyword detected at line %s",linec);
                }
                strcpy(keyW,word);
                kwf = 1;
                wf=0;
            }
        }
        fclose(ptr);
        if(id(word) && wf)
        {
            strcpy(idW,word);
            idf=1;
        }
        if(idf && kwf && strcmp(idW," ") && strcmp(keyW," ") && keyW[0]!='e' && keyW[0]!='r' )
        {
            i++;
            j=0;
            while(inp[i] != ' ')
            {
                word[j] = inp[i];
                i++;
                j++;
            }
            word[j] = '\0';
            if(lookUp(idW,scope))
            {
                printf("\nDuplicate identifier detected at line %s",linec);
            }
            else if(!strcmp(word,"("))
            {

                insert(idW,"func",keyW,scope);
                strcpy(scope,idW);
            }
            else
            {

                insert(idW,"var",keyW,scope);
            }
            idf = 0;
            kwf = 0;
        }
        else if(idf && strcmp(idW," "))
        {
            if(!lookUp(idW,scope))
            {
                printf("\nUnknown identifier detected at line %s",linec);

            }
            idf = 0;
        }


    }
}

void commentRemove(FILE *fp)
{
    FILE *f;
    f= fopen("comment_add.txt","w");
    int putfi=1,parf=0,prif=1;
    char c,cb;
    while((c=getc(fp))!=EOF)
    {
        if(c=='(')
            parf = 1;
        if(c=='"' && parf)
            prif = 0;
        if(c== ')')
        {
            prif = 1;
            parf = 0;
        }
        if(prif)
        {
            if (c == cb && c==' ')
                putfi = 0;
            if(c=='/')
            {
                while(c=getc(fp))
                {
                    if(c=='/')
                    {
                        while((c=getc(fp) )!= '\n');
                        break;
                    }
                    else if(c=='*')
                        while((c=getc(fp) )!= '/');
                    putfi=0;
                    break;
                }
            }
        }
        if(putfi)
            fputc(c,f);
        putfi=1;
        cb = c;
    }
    fclose(f);

}
int forCheck(char inp[],int k)
{
    k--;
    while(inp[k]==' ' && inp[k]!='(')
    {
        k--;
    }

    if(inp[k]=='(')
    {
        if(inp[k-3]=='f' && inp[k-2]=='o' && inp[k-1]=='r')
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
void duplicateErrors(char inp[],int inpi)
{
    char linec[20],linecB[20],lineP[20],lineD[20],lineD2[20];
    int i=0, ifflag=0;
    int j=0, countB=0,countP=0,k;
    while(inp[i] != ' ')
    {
        linec[j] = inp[i];
        i++;
        j++;
    }
    linec[j] = '\0';
    for(i = 0; i<inpi; i++)
    {
        if(inp[i] == '\n')
        {
            if(countP>0)
            {
                error=1;
                printf("\nUnbalanced '(' at line %s",lineP);
                countP = 0;
            }
            i++;
            j=0;
            while(inp[i] != ' ')
            {
                linec[j] = inp[i];
                i++;
                j++;
            }
            linec[j] = '\0';
        }
        else if(inp[i] == '{')
        {
            countB++;
            strcpy(linecB,linec);
        }
        else if(inp[i] == '}')
            countB--;
        else if(inp[i] == '(')
        {
            countP++;

            strcpy(lineP,linec);
        }
        else if(inp[i]==';')
        {
            k=i;
            k++;
            while(inp[k]!=';' && inp[k]==' ')
                k++;
            if(inp[k]==';')
                if(!forCheck(inp,i))
                {
                    if(strcmp(lineD2,linec))
                    {
                        error=1;
                        printf("\nDuplicate token at line %s",linec);
                        strcpy(lineD2,linec);
                    }
                }
        }
        else if(inp[i] == ')')
            countP--;
        else if(inp[i] == 'i' && inp[i+1] == 'f' && inp[i+2] == '(')
            ifflag++;
        else if(inp[i] == ' ' && inp[i+1] == 'e' && inp[i+2] == 'l' && inp[i+3] == 's' && inp[i+4] == 'e' && inp[i+5] == ' ')
            ifflag--;

        if(countB<0 && strcmp(lineD,linec))
        {
            error=1;
            printf("\nUnbalanced '}' at line %s",linec);
            strcpy(lineD,linec);
            countB=0;
        }
        else if(countB < 0)
            countB = 0;

        if(countP<0 && strcmp(lineP,linec))
        {
            error=1;
            printf("\nUnbalanced ')' at line %s",linec);
            strcpy(lineP,linec);
            countP=0;
        }
        else if(countP < 0)
            countP = 0;
        if(ifflag<0)
        {
            error=1;
            printf("\nUnmatched 'else' at line %s",linec);
            ifflag=0;
        }
    }
    if(countB)
        error=1;
        printf("\nUnbalanced '{' at line %s",linecB);

}

void addLineNum(FILE *fp, char inp[],int inpi)
{
    int linen=1;
    fprintf(fp,"%d ",linen);
    for(int i = 0; i<inpi; i++)
    {
        while(inp[i]!='\n')
        {
            fputc(inp[i],fp);
            i++;
        }
        fputc(inp[i],fp);
        linen++;
        fprintf(fp,"%d ",linen);
    }
}


int main()
{
    assign1();
    assign2();
    assign3();

    FILE *ptr,*fp2;
    int inpi=0;
    char inp[1000],c;
    int j,countB=0;
    printf("Input File:\n");
    ptr = fopen("input1.txt","r");
    while((c=getc(ptr))!=EOF)
    {
        printf("%c",c);
    }
    fclose(ptr);
    printf("\n-----------------------------------------------\n");

    ptr = fopen("input1.txt","r");
    commentRemove(ptr);
    fclose(ptr);

    ptr = fopen("comment_add.txt","r");
    while((c=getc(ptr))!=EOF)
    {
        inp[inpi]=c;
        inpi++;
    }
    fclose(ptr);

    ptr = fopen("line_add.txt","w");
    addLineNum(ptr,inp,inpi);
    fclose(ptr);

    ptr= fopen("line_add.txt","r");
    inpi=0;
    printf("Output :\n");
    while((c=getc(ptr))!=EOF)
    {
        printf("%c",c);
        inp[inpi]=c;
        inpi++;
    }
    fclose(ptr);

    printf("\n------------------------------\nErrors:");
    duplicateErrors(inp,inpi);
    kwIdChecker(inp,inpi);
    display();
    if(!error)
        printf("\nNo error.\n");
    else
        printf("\nThere is at least one error.\n");



    return 0;
}
