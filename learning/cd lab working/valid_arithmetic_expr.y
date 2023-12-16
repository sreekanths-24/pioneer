%{
#include <stdio.h>
#include <windows.h>
int yylex();
void yyerror(char *);
%}

%token NUMBER
%token VARIABLE

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

S: VARIABLE '=' E {
    printf("\nEntered arithmetic expression is Valid\n\n");
    return 0;
}
E: E '+' E
 | E '-' E
 | E '*' E
 | E '/' E
 | E '%' E
 | '(' E ')'
 | NUMBER
 | VARIABLE
;

%%

int main()
{
    printf("\nEnter Any Arithmetic Expression which can have operations Addition, Subtraction, Multiplication, Division, Modulus and Round brackets:\n");
    yyparse();
    return 0;
}

void yyerror(char *s)
{
    printf("\nEntered arithmetic expression is Invalid\n\n");
}