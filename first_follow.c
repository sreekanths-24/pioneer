#include<stdio.h> 
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h> 

int n, m = 0, p, i = 0, j = 0, loopflag, first_epsilon=0, follow_epsilon=0;
char a[10][10], f[10];
void follow(char c);
void first(char c);

int main() {
    int i, z;
    char c, ch;
    printf("\n\t--- FIRST AND FOLLOW ---\n");
    printf("\nEnter the no of productions : ");
    scanf("%d", & n);
    printf("\n(NOTE: Epsilon = '#' when giving inputs)\n(NOTE: Use the format A=Ab\n\t\t      A=c)\n");
    printf("\nEnter the productions below: \n");

    for (i = 0; i < n; i++)
        scanf("%s%c", a[i], & ch);

    do
    {
        m = 0;
        printf("\nEnter a variable whose first & follow is to be found:");
        scanf("%c", & c);

        loopflag=0;
        first(c);
        printf("First(%c) = {", c);

        for (i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n");
        strcpy(f, " ");
        m = 0;
        follow(c);
        printf("Follow(%c) = {", c);

        for (i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n");
        printf("\nWant to continue or not(1/0) ? ");
        scanf("%d%c", & z, & ch);
    }
    while (z == 1);
    return (0);
}

void first(char c) {
    int k, l;
    if (!isupper(c))
        f[m++] = c;
    for (k=0; k < n; k++)
    {
        l=3;
        if (a[k][0] == c)
        {
            if (a[k][2] == '$')
                follow(a[k][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else if (a[k][2]=='#' && loopflag==0)
                f[m++] = a[k][2];
            else if (a[k][2]=='#' && loopflag==1)
                first_epsilon=1;
            else if (a[k][2]=='+' || a[k][2]=='-' || a[k][2]=='*' || a[k][2]=='/' || a[k][2]=='(' || a[k][2]==')')
                f[m++] = a[k][2];
            else
            {
                loopflag=1;
                first(a[k][2]);
                while(first_epsilon==1)
                {
                    first_epsilon=0;
                    first(a[k][l]);
                    l++;
                }
            }
        }
    }
}

void follow(char c) {
    int l, k, z;
    if (a[0][0] == c)
        f[m++] = '$';
    for (i = 0; i < n; i++)
    {
        for (j = 2; j < strlen(a[i]); j++)
        {
            z=j;
            if (a[i][z] == c)
            {

                if(a[i][z+1]=='\0' && c!=a[i][0])
                {
                    follow(a[i][0]);
                }

                while (a[i][z+1] != '\0')
                {
                    loopflag=0;
                    first(a[i][z+1]);
                    follow_epsilon=0;
                    for(l=0;l<m;l++)
                    {
                        if(f[l]=='#')
                        {
                            for(k=l;k<m-1;k++)
                            {
                                f[k]=f[k+1];
                            }
                            follow_epsilon=1;
                            m--;
                            z++;
                            break;
                        }
                    }
                    if(follow_epsilon==0)
                        break;
                }

                if (a[i][z+1] == '\0' && follow_epsilon==1)
                {
                    follow(a[i][0]);
                    follow_epsilon=0;
                }
            }
        }
    }
}