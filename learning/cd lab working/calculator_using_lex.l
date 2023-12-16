%{
#include <stdio.h>
#include <stdlib.h>
 
int op = 0, i;
float a, b;
%}
 
dig [0-9]+|([0-9]*)\.([0-9]+)
add "+"
sub "-"
mul "*"
div "/"
pow "^"
ln \n


%%
 
{dig} {digi();}
{add} {op = 1;}
{sub} {op = 2;}
{mul} {op = 3;}
{div} {op = 4;}
{pow} {op = 5;}
{ln} {printf("\n The Answer: %f\n\n", a); exit(0);}
 
%%


int digi()
{
    if (op == 0)
        a = atof(yytext);
    else
    {
        b = atof(yytext);
        
        switch (op)
        {
            case 1:
                    a = a + b;
                    break;
            case 2:
                    a = a - b;
                    break;
            case 3:
                    a = a * b;
                    break;
            case 4:
                    if (b != 0)
                        a = a / b;
                    else
                    {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    break;
            
                    case 5:
                    for (i = 1; i < b; ++i)
                        a = a * a;
                    break;
        }
        op = 0;
    }
    return 0;
}


int main()
{
    printf("Enter a number with the operation you prefer (e.g., 5+3, 8*2, etc.):\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}