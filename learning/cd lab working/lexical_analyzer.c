#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register","return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union","unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }

return flag;
}


int main()
{
    char ch, buffer[15], operators[] = "+-*/%=";
    char specialChars[] = ":,;(){}";
    FILE *fp;
    int i, j = 0, k = 0, flagop=0, flagsp=0, flagnum=0;

    fp = fopen("lexical_analyzer_program.txt", "r");
    if (fp == NULL)
    {
        printf("\nError while opening the file\n");
        exit(0);
    }

    printf("\n");
    while ((ch = fgetc(fp)) != EOF)
    {
        for (i = 0; i < strlen(operators); i++)
        {
            if (ch == operators[i])
            {
                flagop=1;
            }
        }
        
        for (i = 0; i < strlen(specialChars); i++)
        {
            if (ch == specialChars[i])
            {
                flagsp=1;
            }
        }
        
        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }

        else if (ch == ' ' || ch == '\n' || flagop == 1 || flagsp == 1)
        {
            buffer[j] = '\0';
            
            if(j!=0)
            {
                if (isKeyword(buffer) == 1)
                    printf("%s is keyword\n", buffer);
                else
                {
                    if(isalpha(buffer[0]))
                        printf("%s is identifier\n", buffer);
                    else
                    {
                        flagnum=1;
                        for(i=1; i<strlen(buffer); i++)
                        {
                            if(isalpha(buffer[i]))
                            {
                                flagnum=0;
                                break;
                            }
                        }

                        if(flagnum==1)
                            printf("%s is number\n", buffer);
                        else
                            printf("%s is not a valid identifier\n", buffer);
                    }
                }

                j=0;
            }
            
            if(flagop == 1)
                printf("%c is operator\n", ch);
            else if(flagsp == 1)
                printf("%c is special character\n", ch);

            flagop=0;
            flagsp=0;
            buffer[0] = '\0';

            if(ch == '\n' || ch == ';')
                printf("\n");

        }   
    }    

    fclose(fp);
    return 0;
}