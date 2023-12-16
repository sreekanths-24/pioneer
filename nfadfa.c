#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *sortcheck(char a[], int n)
{
    int tempa, tempb, i, j;
    char tempx[15], tempz[15], temp;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            tempz[0] = a[j];
            sscanf(tempz, "%d", &tempa);
            tempx[0] = a[j + 1];
            sscanf(tempx, "%d", &tempb);
            if (tempa > tempb)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    return a;
}

int main()
{
    int no_states, no_symbols, no_final, initial, final_states[50], i, j, k, l, m, h, z, found, selected_state = 0, temp = 0, str_len;
    char trans_table[50][50][50], dfa_table[50][50][50], tempz[20], tempx[20];

    printf("\n\t--- NFA TO DFA CONVERTOR ---\n");
    printf("\nEnter the total number of states : ");
    scanf("%d", &no_states);

    printf("\nEnter the total number of input symbols : ");
    scanf("%d", &no_symbols);

    printf("\n(NOTE: Numbers from 1 will be used for states)");
    printf("\n(NOTE: Letters from 'a' will be used for input symbols)");
    printf("\n(NOTE: Use '-' if no transition for a symbol in a state)");
    printf("\n(NOTE: Enter the states in increasing order of numbers (ascending))");
    printf("\nEnter the transition table below\n");
    for (i = 0; i <= no_states; i++)
    {
        if (i != 0)
        {
            sprintf(trans_table[i][0], "%d", i);
            printf("\n ---> State %d\n", i);
        }

        for (j = 1; j <= no_symbols; j++)
        {
            if (i == 0)
            {
                trans_table[0][j][0] = (char)96 + j;
                continue;
            }
            printf("input %c: ", (char)96 + j);
            scanf("%s", trans_table[i][j]);
        }
    }

    printf("\nEnter the initial state number : ");
    scanf("%d", &initial);

    printf("\nEnter the number of final state : ");
    scanf("%d", &no_final);

    printf("\nEnter the final states below\n");
    for (i = 0; i < no_final; i++)
    {
        scanf("%d", &final_states[i]);
    }

    printf("\n-- INPUT --\n\n");
    for (i = 0; i <= no_states; i++)
    {
        printf("\n");
        for (j = 0; j <= no_symbols; j++)
        {
            printf("%s\t\t", trans_table[i][j]);
        }
    }

    for (i = 0; i <= no_states; i++)
    {
        if (i == 0)
        {
            for (j = 1; j <= no_symbols; j++)
            {
                dfa_table[0][j][0] = (char)(96 + j);
            }
        }

        if (i == initial)
        {
            for (j = 0; j <= no_symbols; j++)
            {
                strcpy(dfa_table[i][j], trans_table[i][j]); // Move outputs
            }
        }
    }

    i = 1;
    z = 2;
    while (i != z)
    {
        for (j = 1; j <= no_symbols; j++)
        {
            if (strcmp(dfa_table[i][j], "-") == 0)
            {
                continue;
            }

            found = 0;
            for (k = 1; k < z; k++)
            {
                tempz[0] = '\0';
                tempx[0] = '\0';
                strcpy(tempz, dfa_table[i][j]);
                strcpy(tempx, dfa_table[k][0]);
                if (strcmp(sortcheck(tempz, strlen(tempz)), sortcheck(tempx, strlen(tempx))) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found != 1)
            {
                strcpy(dfa_table[z][0], dfa_table[i][j]);
                for (k = 0; k <= strlen(dfa_table[z][0]); k++)
                {
                    tempz[0] = dfa_table[z][0][k];
                    sscanf(tempz, "%d", &temp);

                    if (dfa_table[z][0][k] != ',' && dfa_table[z][0][k] != '\0')
                    {
                        selected_state = (selected_state * 10) + temp;
                    }
                    else
                    {
                        for (l = 1; l <= no_states; l++)
                        {
                            if (strcmp(trans_table[selected_state][l], "-") != 0)
                            {
                                strcat(dfa_table[z][l], trans_table[selected_state][l]);
                                strcat(dfa_table[z][l], ",");
                            }
                        }
                        selected_state = 0;
                    }
                }

                for (k = 1; k <= no_symbols; k++)
                {
                    str_len = (strlen(dfa_table[z][k]) - 1);
                    if (dfa_table[z][k][0] == '\0')
                    {
                        dfa_table[z][k][0] = '-';
                    }

                    if (dfa_table[z][k][str_len] == ',')
                    {
                        dfa_table[z][k][str_len] = '\0';
                    }

                    for (l = 0; l < strlen(dfa_table[z][k]); l++)
                    {
                        if (dfa_table[z][k][l] == ',')
                            continue;

                        for (m = l + 1; dfa_table[z][k][m] != '\0'; m++)
                        {
                            if (dfa_table[z][k][l] == dfa_table[z][k][m])
                            {
                                for (h = m - 1; dfa_table[z][k][h] != '\0'; h++)
                                {
                                    dfa_table[z][k][h] = dfa_table[z][k][h + 2];
                                }
                            }
                        }
                    }
                }
                z++;
            }
        }
        i++;
    }

    printf("\n\n\n");
    printf("\n-- OUTPUT --\n\n");

    for (i = 0; i <= z; i++)
    {
        printf("\n");
        for (j = 0; j <= no_symbols; j++)
        {
            temp = 0;
            if (j == 0)
            {
                for (k = 0; k < no_final; k++)
                {
                    tempz[0] = '\0';
                    sprintf(tempz, "%d", final_states[k]);
                    if (strstr(dfa_table[i][j], tempz))
                    {
                        printf("*%s\t\t", dfa_table[i][j]);
                        temp = 1;
                        break;
                    }
                }
            }
            if (temp == 1)
                continue;

            printf("%s\t\t", dfa_table[i][j]);
        }
    }

    printf("\n");
}