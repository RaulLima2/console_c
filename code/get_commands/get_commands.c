#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "../interface/interface.h"
#include "../commands_repl_c/commands_repl.h"
#include "get_commands.h"

const int rgb[3] = {1, 91, 107};
const int  reset[3] = {0, 39, 49};
const char* __restrict__ _file_name = {"01.c"};
const char* menu = {"console c >>>"};

void  push_includes()
{
    FILE *file_main;
    char* includes = (char*)calloc(500, sizeof(char));
    const char* __restrict__ __format[] = {
                                            "#include <stdio.h>\n",
                                            "int main(int argc, char* argv[])\n",
                                            "{\n"
                                        };


    file_main = fopen(_file_name,"w+");

    if(file_main == NULL)
    {
        fprintf(stderr, "Error: in function push_includes()\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file_main,"%s", __format[0]);

    while(strncmp(includes, "\n", strlen("\n")) != 0)
    {
        mix_color(rgb);
        printf(menu);
        mix_color(reset);

        fgets(includes, 500, stdin);

        strcpy(includes, check_syntax(includes));
        fprintf(file_main,"%s",includes);
    }

    fprintf(file_main,"%s", __format[1]);
    fprintf(file_main,"%s", __format[2]);

    fclose(file_main);
}

void push_main()
{
    FILE* file_body;
    char* body_main = (char*)calloc(500, sizeof(char));

    file_body = fopen(_file_name, "a+");

    if(file_body == NULL)
    {
        printf("Erro: Not Allocated \n");
        printf("IN FUNCTION: push_main() \n");
    }

    while(strncmp(body_main, "\n", strlen("\n")) != 0)
    {
        mix_color(rgb);
        printf(menu);
        mix_color(reset);

        fgets(body_main,500,stdin);
        strcpy(body_main, check_syntax(body_main));
        fprintf(file_body,"%s",body_main);
    }

    fprintf(file_body,"%s","}\n");

    fclose(file_body);
}

void compile()
{

    char* __command = {"gcc -Wall -std=c99 01.c -o 01"};
    
    system(__command);
    system("./01");
    system("rm 01");
    system("rm -f 01.c");
}

