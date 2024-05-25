%{
#include<stdio.h>
#include<string.h>
int n;
%}

%option noyywrap

DIGIT [0-9]
LETTER [a-zA-Z]

id [_|a-zA-Z]

OP [+|-|*|/]
RO [>=|>|<=|<|==|!=]
pp [#]

%%

{DIGIT}{DIGIT}* {printf("%d numbers\n",yytext);printf("\n");}

"int"|"boolean"|"double"|"float"|"if"|"else"|"printf"|"scanf" {printf("%s keywords \n ",yytext);printf("\n");}

{LETTER}*[(][)] {printf("%s function \n ",yytext);printf("\n");}

{pp}*{LETTER}*[<]{LETTER}*[.]{LETTER}*[>] {printf("%s preprocessor \n ",yytext);printf("\n");}

"."|","|"{"|"}"|"("|")" {printf("%s others \n",yytext);printf("\n");}

{OP}* {printf("%s operator \n",yytext);printf("\n");}

{RO}* {printf("%s operator \n",yytext);printf("\n");}
[\n] {n++;}

%%

int main(){
    yyin=fopen("sample.c","r");
    yylex();
    printf("number of lines :%d",n);
}





