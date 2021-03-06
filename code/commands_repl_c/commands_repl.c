#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../interface/interface.h"
#include "../commands/commands.h"
#include "../tree_decision/tree_decision.h"
#include "commands_repl.h"

bool __analyser_syntax(char* string, char* analyser);

char* check_syntax(char* string) 
{
    TBS* node_operation_decision;
    TBS* tree_decision = create(strlen("q"), command_exit);

    insert(tree_decision, strlen("help"), command_help);
    insert(tree_decision, strlen("write"), command_write);
    insert(tree_decision, strlen("manual"), command_manual);
    insert(tree_decision, strlen("_source"), command_source);


    if(__analyser_syntax(string, "q"))
    {
        string[strlen(string) - 1] = '\0';
        node_operation_decision = search(tree_decision, strlen("q"));
        execute_node(node_operation_decision, string);
    }
    else if(__analyser_syntax(string, "help"))
    {
        string[strlen(string) -1] = '\0';
        node_operation_decision = search(tree_decision, strlen("help"));
        execute_node(node_operation_decision, string);
        return " \n";
    }
    else if(__analyser_syntax(string, "write"))
    {
        string[strlen(string) -1] = '\0';
        node_operation_decision = search(tree_decision, strlen("write"));
        execute_node(node_operation_decision, string);
        return " \n";
    }
    else if(__analyser_syntax(string, "manual"))
    {
        string[strlen(string) - 1] = '\0';
        node_operation_decision = search(tree_decision, strlen("manual"));
        execute_node(node_operation_decision, string);
        return " \n";
    }
    else if(__analyser_syntax(string, "_source"))
    {
        string[strlen(string) -1] = '\0';
        node_operation_decision = search(tree_decision, strlen("_source"));
        execute_node(node_operation_decision, string);
        return " \n";
    }

    return string;
}

void command_help(char* name_function)
{
    __help();
}

void command_exit(char* exit_simbol)
{
    __quit();
}

void command_source(char* local_file)
{
    char* temp = (char*)calloc(strlen(local_file)*2, sizeof(char));
    strncpy(temp, local_file + 7, strlen(local_file));
    __source(temp);
}

void command_manual(char* manual_of_function)
{
    char* temp = (char*)calloc(100, sizeof(char));
    strncat(temp, manual_of_function + 6, strlen(manual_of_function));
    __manual(temp);
}

void command_write(char* path_to_the_source)
{
    char* temp = (char*)calloc(100, sizeof(char));
    strncpy(temp, path_to_the_source + 5, strlen(path_to_the_source));
    __write(temp);
}

bool __analyser_syntax(char* string, char* analyser)
{
    if(strncmp(analyser, string, strlen(analyser)) == 0)
    {
        return true;
    }

    return false;
}