#include "push_swap.h"

int sort_complete(int *my_array, int *compare_array, int total)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while(i != total)
    {
        if(my_array[i] != compare_array[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 1)
        return (1);
    return (0);
}