#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../get_commands/get_commands.h"
#include "repl.h"


void shell_start()
{
    int i = 0;
    string print_shell[] = {
        "Console C 2020-0.1 version",
        "lisence GNU"};

    for(i = 0; i < 2; i++)
    {
        printf("%s\n",print_shell[i]);
    }
}


void repl()
{
    bool check = true;

    shell_start();

    while(check)
    {
        push_includes();
        push_main();

        compile();
    }
}