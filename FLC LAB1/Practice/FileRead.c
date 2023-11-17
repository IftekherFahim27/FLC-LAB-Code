#include<Stdio.h>

int val;
FILE *fptr;
int main(){

fptr=fopen("Practice.txt","r");

if(fptr==NULL){
    printf("File not exist");
}

else{
    fscanf(fptr,"%d",&val);
    printf("From the file we get %d",val);
    fclose(fptr);
}

return 0;
}
