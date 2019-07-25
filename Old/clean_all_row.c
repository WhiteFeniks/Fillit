#include <string.h>

char clean_row(char **matrix)
{
    int i;
    int i2;

    i = 0;
    while(matrix[i])
    {
        if (!strcmp(matrix[i], "...."))
        {
            i2 = i--;
            while(matrix[i2] != 0)
            {
                matrix[i2] = matrix[i2 + 1];
                i2++;
            }
        }
        i++;
    }
}
int main()
{
    char *matrix[5] = {"....", "BBBB", "....", "....", NULL};
    clean_row(&matrix);
    return (0);
}