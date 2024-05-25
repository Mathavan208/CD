%{
#include <stdio.h>
#include <string.h>
#include "expression.tab.h"
%}

%%
[a-zA-Z]+   { return VARIABLE; }
[0-9]+      { return NUMBER; }
[\t]        { /* Ignore tabs */ }
[\n]        { return 0; } // Signifies end of input
.           { return yytext[0]; } // Returns the character itself
%%

int yywrap() {
    return 1; // Indicates no more input
}
