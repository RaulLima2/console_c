#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../interface/interface.h"
#include "../commands_repl_c/commands_repl.h"
#include "get_commands.h"


void  push_includes()
{
    FILE *file_main;
    char* includes = (char*)calloc(500, sizeof(char));
    const char* __restrict__ __format[] = {   
                                            "void main()\n",
                                            "{\n"
                                        };


    file_main = fopen("01.c","w+");

    if(file_main == NULL)
    {
        printf("Error in open the file\n");
        exit(EXIT_FAILURE);
    }

    while(strncmp(includes, "\n", strlen("\n")) != 0)
    {
        bold_red();
        printf(">>");
        reset();
        fgets(includes, 500, stdin);
        //check_syntax(includes);
        fprintf(file_main,"%s",includes);
    }

    fprintf(file_main,"%s", __format[0]);
    fprintf(file_main,"%s", __format[1]);

    fclose(file_main);
}

void push_main()
{
    FILE* file_body;
    char* body_main = (char*)calloc(500, sizeof(char));

    file_body = fopen("01.c", "a+");

    if(file_body == NULL)
    {
        printf("Erro: Not Allocated \n");
        printf("IN FUNCTION: repl() \n");
    }

    while(strncmp(body_main, "\n", strlen("\n")) != 0)
    {   
        bold_cyan();
        printf(">>");
        bold_red();
        fgets(body_main,500,stdin);
        //check_syntax(body_main);
        fprintf(file_body,"%s",body_main);
        reset();
    }

    fprintf(file_body,"%s","}\n");

    fclose(file_body);
}

void get_makefile(int number_argument, char** components_in_main)
{
    int i = 0;
    FILE *file_main;
    
    file_main = fopen("/result/Makefile","w+");

    if(file_main == NULL)
    {
        printf("Error in open the file");
        exit(EXIT_FAILURE);
    }


    for( i = 0; i < number_argument; i++)
    {
        fprintf(file_main,"%s", components_in_main[i]);
    }

    fclose(file_main);
}

void compile()
{

    char* __command = {"gcc -Wall -std=c99 01.c -o 01"};
    
    system(__command);
    system("./01");
    system("rm 01");
    system("rm -f 01.c");
}

