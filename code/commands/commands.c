#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void __help()
{
    const char* command_help[] =
    {
        "\nq - command with exit the repl\n",
        "manual - command with verified manual of function - manual <função>\n",
        "_source - command with execute the file.c  - source <arquivos>\n",
        "write - command with change or create files in c - write <file>\n"
    };

    for(int i = 0; i < 4; i++)
    {
        printf("%s", command_help[i]);
    }
}

void __quit()
{
    exit(EXIT_SUCCESS);
}

void __source(char* __file_code)
{
    char* compile = (char*)calloc(MAX_ALLOCATE,sizeof(char));
    const char* flags = {" -o program"};
    const char* _gcc = {"gcc -Wall -std=c99 "};

    strcat(compile, _gcc);
    strcat(compile, __file_code);
    strcat(compile, flags);

    system(compile);
    system("./program");
    system("rm program");
}

void __manual(char* name_function)
{
    char* _command = (char*)calloc(MAX_ALLOCATE, sizeof(char));

    strcpy(_command,"man ");
    strcat(_command, name_function);
    
    system(_command);
}

void __write(char* __path_to_the_source)
{
    char* edit = (char*)calloc(MAX_ALLOCATE,sizeof(char));
    const char* _command_nano = {"nano "};

    strncpy(edit,_command_nano, strlen(_command_nano));
    strcat(edit, __path_to_the_source);
    
    system(edit);
}