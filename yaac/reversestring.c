#include<stdio.h>
#include<string.h>

void reverse(char str[]){
    int n=strlen(str);
    int i;
    for(i=0;i<n/2;i++){
       char temp=str[i];
       str[i]=str[n-i-1];
       str[n-i-1]=temp;
    }
}
int main(){
    char str[100];
    scanf("%s",str);
    printf("%s\n",str);
    reverse(str);
    printf("%s\n",str);
    return 0;
}