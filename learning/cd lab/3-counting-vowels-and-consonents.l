%{
#include&lt;stdio.h&gt;
int v=0,c=0;
%}
%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
[\n] { printf(&quot;no of vowels:%d,no of 
consonants:%d&quot;,v,c);
exit(0);}
%%
int main()
{
printf(&quot;Enter the input:&quot;);
yylex();
return 0;
}
int yywrap()
{
return 1;
}
