#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_commands.h"

//function with get the arguments in main and create file
int  push_includes(int number_includes, char* arguments_includes)
{
    FILE *file_main;
    int i = 0;

    file_main = fopen("/result/main.c","a");

    if(file_main == NULL)
    {
        printf("Error in open the file")
        exit(EXIT_FAILURE);
    }

    for( i = 0; i < number_includes; i++)
    {
        fprintf(file_main,'%s', arguments_includes[i]);
    }

    fclose(file_main);
}

void create_makefile(int number_argument, char* components_in_main)
{
    FILE *file_main;
    int i = 0;
    
    file_main = fopen("/result/Makefile","a");

    if(file_main == NULL)
    {
        printf("Error in open the file")
        exit(EXIT_FAILURE);
    }


    for( i = 0; i < number_includes; i++)
    {
        fprintf( file_main,'%s', components_in_main[i]);
    }

    fclose(file_main)
}

void compile(string name_make)
{
    system("/result make ");
}

string get_answer()
{
    string answer;
    FILE file_result = ('/result/resultado.txt');

    file_result = fopen('/result/resultado.txt',"r");

    if(file_result == NULL)
    {
        printf("Error in reading the file");
    }

    fgets(answer, 255,(FILE)*file_result);

    return answer;
}
