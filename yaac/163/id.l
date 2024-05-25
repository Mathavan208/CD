%{
#include<stdio.h>
#include "id.tab.h"
%}

%%
[a-zA-Z]+ {return letter;}
[0-9]+ {return digit;}
%%

int yywrap(){
    return 1;
}