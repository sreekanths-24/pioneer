%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int yylex();
void yyerror(char *msg);
int flag;
int i;
int k = 0;
%}

%union {
    char* f;
}

%token <f> STR
%type <f> E

%%

S: E {
    flag = 0;
    k = strlen($1) - 1;
    for (i=0; i<k/2; i++)
    {
        if ($1[i] != $1[k-i])
        {
            flag = 1;
        }
    }
    printf("\n-> OUTPUT\n");
    if (flag == 1)
        printf("Not palindrome\n");
    else
        printf("palindrome\n");
};

E: STR {$$ = $1;};

%%

void yyerror(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main()
{
    printf("\n\n\t --- CHECK PALINDROME ---\n");
    printf("\nEnter the input: ");
    yyparse();
    return 0;
}
