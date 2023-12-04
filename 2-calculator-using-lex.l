%{
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
int op = 0, i;
float a, b;
%}
dig [0-9]+|([0-9]*)\.([0-9]+)
add &quot;+&quot;
sub &quot;-&quot;
mul &quot;*&quot;
div &quot;/&quot;
pow &quot;^&quot;
ln \n
%%
{dig} {digi();}
{add} {op = 1;}
{sub} {op = 2;}
{mul} {op = 3;}
{div} {op = 4;}
{pow} {op = 5;}
{ln} {printf(&quot;\n The Answer: %f\n\n&quot;, a); 
exit(0);}
%%
digi()
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
printf(&quot;Error: Division by zero\n&quot;);
exit(1);
}
break;
case 5:
for (i = 1; i &lt; b; ++i)
a = a * a;
break;
}
op = 0;
}
}
int main()
{
printf(&quot;Enter a number with the operation you 
prefer (e.g., 5+3, 8*2, etc.):\n&quot;);
yylex();
return 0;
}
int yywrap()
{
return 1;
}