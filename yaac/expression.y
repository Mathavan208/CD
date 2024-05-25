%{
#include<stdio.h>
int yyerror(char* s);
%}

%token NUMBER
%token VARIABLE

%left '+''-'
%left '*''/''%'
%left '('')'

%%
S:E'='E {printf("valid arithmetic expression");return 0;}

E:E'+'E|
  E'-'E|
  E'*'E|
  E'/'E|
  E'%'E|
  '('E')'|
  NUMBER|
  VARIABLE


%%

void main(){
    printf("enter the arithmetic expression : ");
    yyparse();
}
int yyerror(char* s){
    printf("error ");
    return 0;
}



