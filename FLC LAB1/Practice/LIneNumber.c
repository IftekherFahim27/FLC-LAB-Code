#include<stdio.h>
int main(){

FILE  *ptr1,*ptr2;
char c;
int line=0;

ptr1=fopen("Demo.txt","r");
ptr2=fopen("Result.txt","w");

if(ptr1==NULL){
    printf("File is not  exists \n");
}
else{
    while((c=fgetc(ptr1))!=EOF){
            fputc(c,ptr2);
        if(c=='\n'){
            line++;
            fprintf(ptr2,"%d",line);
            fputc(':' ,ptr2);

        }
    }
}
fclose(ptr1);
fclose(ptr2);

ptr2=fopen("Result.txt","r");
while((c=fgetc(ptr2))!=EOF){
    printf("%c",c);
}
return 0;

}
