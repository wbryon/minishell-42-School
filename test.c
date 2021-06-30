#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char **argv, char **env)
{
    char    *command_buf;

    (void)argc;
    (void)argv;
    while(1)
    {
        command_buf = readline("minishell> ");
        if (strlen(command_buf) > 0)
            add_history(command_buf);
        if (!strcmp(command_buf, "exit"))
            return (1);
    }
}