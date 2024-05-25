%{
#include<stdio.h>
#include<string.h>
float a,b;
int op=0;
void digi();
%}

digit [0-9]
plus [+]
multiply [*]
minus [-]
division [/]
%option noyywrap
%%
{digit}* {digi();}
{plus}* {op=1;}
{minus}* {op=2;}
{multiply}* {op=3;}
{division}* {op=4;}
["\n"] {printf("result : %f",a);}
%%
void digi(){
    if(op==0){
        a=atof(yytext);
    }
    else{
        b=atof(yytext);
        switch(op){
            case 1:
            a=a+b;
            break;
            case 2:
            a=a-b;
            break;
            case 3:
            a=a*b;
            case 4:
            a=a/b;
        }
        op=0;
    }
}
int main(){
    yylex();
    return 0;
}
