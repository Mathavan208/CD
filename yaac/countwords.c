#include<stdio.h>
int count(FILE * file){
    char c;
    int flag=0;
    int count=0;
    int n;
    while((c=fgetc(file))!=EOF){
        if(c=='\n')
        n++;
        if(isalnum(c)){
            if(!flag){
            flag=1;
            count++;
            }
        }
        else{
            flag=0;
        }
    }
    printf("%d\n",n);
    return count;

}

int main(){
    FILE * file;
    file=fopen("input.txt","r");
    printf("count of words is %d",count(file));
    return 0;

}