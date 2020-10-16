#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../interface/interface.h"
#include "../get_commands/get_commands.h"
#include "repl.h"


void shell_start()
{
    int i = 0;
    const int rgb[] = {1, 39, 49};
    string print_shell[] = {
        "Console C 2020-0.2 version\n",
        "lisence GNU\n",
        "q | help | write <file.c> | source <files.c>\n"
        };

    for(i = 0; i < 3; i++)
    {
        mix_color(rgb);
        printf(print_shell[i], i);
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