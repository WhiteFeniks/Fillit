#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>



int		clean_one_column(char **matrix, int i, int j)
{
    int j2;

    j2 = 0;
    while (matrix[i] != 0)
    {
        if (matrix[i][j] == '.')
            j2++;
        i++;
    }
    if (j2 == i)
    {
        i = 0;
        while (matrix[i] != 0)
        {
            j2 = j;
            while (matrix[i][j2] != '\0')
            {
                matrix[i][j2] = matrix[i][j2 + 1];
                j2++;
            }
            i++;
        }
        j--;
    }
    return (j);
}

/*

Функция очистки сразу всех колонн заполненных только точками

*/

int		clean_all_column(char ***matrix)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (matrix[i][j] != 0)
    {
        j = clean_one_column(*matrix, i, j);
        j++;
    }
    return (0);
}

int main()
{
    char **s;
    s =(char**)malloc(sizeof(char*) * 5);
    s[0] = strdup("...A");
    s[1] = strdup(".AAA");
    s[2] = strdup("....");
    s[3] = strdup("....");
    s[4] = NULL;
    while (*s)
    {
        clean_all_column(&s);
        printf("%s\n", *s);
        s++;
    }
    return (0);
}