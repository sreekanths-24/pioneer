#include<stdio.h>
#include<string.h>

void main()
{
    char icode[10][30], str[20], opr[10];
    int i=0;

    printf("\nEnter the set of intermediate code(terminated by exit): \n");

    do
    {
        scanf("%s", icode[i]);
    }
    while(strcmp(icode[i++], "exit") != 0);

    printf("\n\nTarget code generation: ");
    i=0;

    while(strcmp(icode[i], "exit")!=0)
    {
        strcpy(str, icode[i]);
        switch(str[3])
        {
            case'+':
                    strcpy(opr,"ADD");
                    break;
            case'-':
                    strcpy(opr,"SUB");
                    break;
            case'*':
                    strcpy(opr,"MUL");
                    break;
            case'/':
                    strcpy(opr,"DIV");
                    break;
        }

        printf("\n\tMov R%d, %c", 0, str[2]);
        printf("\n\tMov R%d, %c", 1, str[4]);
        printf("\n\t%s R%d, R%d", opr, 0, 1);
        printf("\n\tMov %c, R%d", str[0], 0);
        
        i++;
    }

}
