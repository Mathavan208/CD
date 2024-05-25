%{
#include<stdio.h>
int valid =1;
%}
%token letter digit

%%

start:letter s
s: letter s|
   digit s
   |
  ; 
  
  

%%

int yyerror(){
    printf("it is not identifier");
    valid=0;
    return 0;
}

int main(){
    printf("enter the identifier variable:");
    yyparse();
    if(valid){
        printf("it is valid identifier");
    }
    return 0;
}
