#include <stdio.h>
#include "interface.h"

void tip_colors_and_formatting(int id_color);


void mix_color(const int* rgb)
{
    int i = 0;

    for(i = 0; i < 3; i++)
    {
        tip_colors_and_formatting(rgb[i]);
    }
}

void tip_colors_and_formatting(int id_color)
{
    printf("\e[%dm", id_color);
}