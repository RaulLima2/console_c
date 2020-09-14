#include <stdio.h>
#include <stdlib.h>



#include "repl.h"

void shell_start()
{
    string print_shell[] = {
        "Console C 2020-0.0.1 version",
        "lisence MIT"};

    for(i = 0; i < 2; i++)
    {
        printf("%s\n",print_shell[i]);
    }
}


void repl()
{
    bool check = true;
    char* body_main = (char*)calloc(500, sizeof(char));
    FILE* file;
    const char* _command = {"make code/result"};

    while(check)
    {
        file = fopen("result/01.c", "w+");

        if(file == NULL)
        {
            printf("Erro: Not Allocated \n");
            printf("IN FUNCTION: repl() \n");
        }

        while(getchar() != "\n" && getchar() != EOF)
        {
            printf(">> ");
            fgets(body_main,500,stdin);
            fprintf(file,"%s",body_main);
        }

        fprintf(file,"%s","}");

        fclose(file);


        system(_command);
        system("./1");
        system("rm 1");
        system("rm 01.c");

    }

}

bool input_take(char* str)
{
    
}


void help(char* name_function)
{
    
}
