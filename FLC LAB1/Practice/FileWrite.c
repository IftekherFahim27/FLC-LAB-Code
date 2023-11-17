#include<Stdio.h>
#include<Stdlib.h>
int main(){
int val;
FILE *ptr;


ptr=fopen("Practice.txt","w");
if(ptr==NULL){
    printf("File does not Exists \n");
}
else{
    printf("Enter the value you want to write\n");
    scanf("%d",&val);
    printf("Your input  is %d ",val);
    fprintf(ptr,"%d",val);
    fclose(ptr);
    return 0;

}




}
