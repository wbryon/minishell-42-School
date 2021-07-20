#include "minishell.h"

int exec_bin(t_all *all)
{
    int             i;
    char            *path;
    char            *tmp;
    char            **splitted;
    DIR             *dir;
    struct dirent   *entity;
    pid_t           pid;

    if (!all->cmd.args[0])
        return (5);
    path = getenv("PATH");
    if (!path)
        return (1);
    splitted = ft_split(path, ':');
    if (!splitted)
        return (2);
    i = -1;
    while (splitted[++i])
    {
        dir = opendir(splitted[i]);
        if (!dir)
            return (3);
        entity = readdir(dir);
        while (entity)
        {
            if (!ft_strcmp(entity->d_name, all->cmd.args[0]))
            {
                path = ft_strjoin(splitted[i], "/");
                tmp = path;
                path = ft_strjoin(path, all->cmd.args[0]);
                free(tmp);
            }
            entity = readdir(dir);
        }
        closedir(dir);
    }
    free_array(splitted);
    pid = fork();
    if (pid == -1)
        return (4);
    if (pid == 0)
        execve(path, all->cmd.args, all->env);
    else
        wait(NULL);
    return (0);
}