%{
#include<stdio.h>
#include "y.tab.h"
#include <windows.h>
%}

%%
[a-zA-Z]+   { return VARIABLE; }
[0-9]+      { return NUMBER; }
[\t]        ;  // Ignore tabs
[\n]        { return 0; }
.           { return yytext[0]; }
%%

int yywrap() {
    return 1;
}