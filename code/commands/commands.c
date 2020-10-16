#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void help(char* name_function)
{
    char* _command = {"man"};

    strncat(_command, name_function, strlen(name_function));
    
    system(_command);
}

void quit()
{
    exit(EXIT_SUCCESS);
}

void source(char* __file_code)
{
    char* compile = (char*)calloc(100,sizeof(char));
    const char* flags = {"-o program"};
    const char* _gcc = {"gcc -Wall -std=c99"};

    sprintf(compile, "%s %s %s",_gcc, __file_code, flags);

    system(compile);
    system("./program");
    system("rm program");
}
