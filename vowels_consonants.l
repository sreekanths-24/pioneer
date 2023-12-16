
%{
#include <stdio.h>

int vowel_count = 0;
int consonant_count = 0;
%}

%%
[aeiouAEIOU]   { vowel_count++; }
[a-zA-Z]       { consonant_count++; }
[\n]           { printf("Number of vowels: %d, Number of consonants: %d\n", vowel_count, consonant_count); return 0; }
[\t]          ;
.              {printf("Unknown symbol encountered, Please try again..."); return 0;}
%%

int main() 
{
    printf("Enter the input: ");
    yylex();
    return 0;
}

int yywrap() 
{
    return 1;
}
