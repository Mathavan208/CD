%{
#include<stdio.h>
#include "id.tab.h"
int yyerror();
int flag=1;
%}

%token letter digit

%%

start:letter s
s:letter s|digit s
|  
;

%%


int main(){
    printf("enter the identifier");
    yyparse();
    if(flag){
        printf("valid identifier");
    }
    return 0;
}

int yyerror(){
    printf("invalid idemtifier");
    flag=0;
    return 0;
}