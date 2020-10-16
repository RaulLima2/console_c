#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void help()
{
    const char* command_help[] =
    {
        "\nq - command with exit the repl\n",
        "source - command with execute the file.c  - source <arquivos>\n",
        "manual - command with verified manual of function - manual <função>\n",
        "write - command with change or create files in c - write <file>\n"
    };

    for(int i = 0; i < 4; i++)
    {
        printf("%s", command_help[i]);
    }
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

void manual(char* name_function)
{
    char* _command = (char*)calloc(strlen(name_function) * 3, sizeof(name_function));

    strcpy(_command,"man ");
    strcat(_command, name_function);

    system(_command);
}

void __write(char* __path_to_the_source)
{
    char* edit = (char*)calloc(strlen(__path_to_the_source) * 2,sizeof(char));
    const char* __write = {"nano "};

    strncpy(edit,__write, strlen(__write));
    strcat(edit, __path_to_the_source);
    printf("%s\n", edit);
    system(edit);
}