#include <stdio.h>
#include "interface.h"

void red()
{
    printf("\033[0;31m");
}

void bold_red()
{
    printf("\033[1;31m");
}

void green()
{
    printf("\033[1;32m");
}

void green_bold()
{
    printf("\033[1;32m");
}

void yellow()
{
    printf("\033[0;33m");
}

void yellow_bold()
{
    printf("\033[1;33m");
}

void blue()
{
    printf("\033[0;34m");
}

void bold_blue()
{
    printf("\033[1;34m");
}

void magenta()
{
    printf("\033[0;35m");
}

void bold_magenta()
{
    printf("\033[1;35m");
}

void cyan()
{
    printf("\033[0;36m");
}

void bold_cyan()
{
    printf("\033[1;36m");
}

void reset()
{
    printf("\033[0m");
}
