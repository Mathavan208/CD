%{
#include<stdio.h>
#include "identifier.tab.h"
%}

%%
[a-zA-Z_]+  { return letter; }
[0-9]+      { return digit; }
\n          { return 0; }
.           { ECHO yytext; }

%%

int yywrap() {
    return 1;
}
