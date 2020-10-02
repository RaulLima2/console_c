#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../commands_repl_c/commands_repl.h"
#include "get_commands.h"
#include "interface.h"


int  push_includes()
{
    int i = 0;
    int number_includes = 0;
    FILE *file_main;
    char* includes = (char*)calloc(500, sizeof(char));
    const char* __restrict__ __format = {   
                                            "void main()\n",
                                            "{\n"
                                        };


    file_main = fopen("/result/main.c","w+");

    if(file_main == NULL)
    {
        printf("Error in open the file")
        exit(EXIT_FAILURE);
    }

    while(strncmp(includes, "\n", strlen("\n")) != 0)
    {
        bold_cyan();
        printf(">> ");
        bold_red();
        fgets(includes, 500, stdin);
        check_syntax(includes);
        fprintf(file_main,"%s",includes);
        reset();
    }

    fprintf(file_main,"%s", __format);

    fclose(file_main);

    return number_includes + 1;
}

void push_main(int number_spaces_includes_fseek)
{
    char* body_main = (char*)calloc(500, sizeof(char));

    file = fopen("result/01.c", "a");

    if(file == NULL)
    {
        printf("Erro: Not Allocated \n");
        printf("IN FUNCTION: repl() \n");
    }

    while(strcmp(body_main, "\n", strlen("\n")) != 0)
    {   
        bold_cyan();
        printf(">> ");
        bold_red();
        fgets(body_main,500,stdin);
        check_syntax(body_main);
        fprintf(file,"%s",body_main);
        reset();
    }

    fprintf(file,"%s","}\n");

    fclose(file);
}

void get_makefile(int number_argument, char* components_in_main)
{
    int i = 0;
    FILE *file_main;
    
    
    const char* __restrict__ __format = "%s ";
    
    file_main = fopen("/result/Makefile","w+");

    if(file_main == NULL)
    {
        printf("Error in open the file")
        exit(EXIT_FAILURE);
    }


    for( i = 0; i < number_includes; i++)
    {
        fprintf( file_main,"%s", components_in_main[i]);
    }

    fclose(file_main)
}

void compile()
{

    char* _gcc[] = {"gcc -Wall -std=c99 01.c -o 01"};
    
    system(_gcc);
    system("./01");
    system("rm 01");
    system("rm -f 01.c");
}

