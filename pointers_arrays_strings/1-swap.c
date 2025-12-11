#include "main.h"

void swap_int(int *a, int *b)
{
    int save = *a;

    save = *a;
    *a = *b;
    *b = save;
}
