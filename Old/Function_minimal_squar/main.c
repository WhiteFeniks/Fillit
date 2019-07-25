#include <stdio.h>
#include <stdlib.h>

int minimal_square(int num_of_blocks)
{
    int i;
    int res_i;

    i = 1;
    while (num_of_blocks * 4 > i * i)
        i++;
    res_i = i;
    return (res_i);
}

char	***create_place(int res_i)
{
    int		i;
    int		j;
    char	***place;

    i = 0;
    if (!(place  = (char ***)malloc(sizeof(char **) * (2))))
        return (NULL);
    while (i < res_i)
    {
        j = 0;
        if (!(place[i] = (char **)malloc(sizeof(char *) * (res_i + 1))))
            return (NULL);
        while (j < res_i + 1)
        {
            if (!(place[i][j] = (char *)malloc(sizeof(char) * (res_i + 1))))
                return (NULL);
            j++;
        }
        i++;
    }
    place[res_i] = NULL;
    return (place);
}

char	**filling_place(char **place, int res_i)
{
    int		i;
    int		j;

    i = 0;
    while (i < res_i)
    {
        j = 0;
        while (j < res_i)
        {
            place[i][j] = '.';
            j++;
        }
        place[i][j] = '\0';
        i++;
    }
    place[i] = NULL;
    return (place);
}


int main()
{

    int	num_of_blocks = 13;
    int res_i;
    char **place;

    res_i = minimal_square(num_of_blocks);
    place = filling_place(create_place(res_i), res_i);
    return (place);
}