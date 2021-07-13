#include "minishell.h"

void    exec_pwd(void)
{
    char    *pwd;

    pwd = NULL;
    pwd = getcwd(pwd, 0);
    printf("%s\n", pwd);
    free(pwd);
}

int main(void)
{
    exec_pwd();
    return (0);
}