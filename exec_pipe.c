#include "minishell.h"

int exec_pipe(t_all *all)
{
	(void)all;
    // int     i;
    // int     fd[all->cmd_total - 1][2];
    // int     pids[all->cmd_total];
    // t_cmd   *temp;
    // char    *path;

    // i = 0;
    // while (i < all->cmd_total - 1)
    // {
    //     if (pipe(fd[i]) == -1)
    //         exit(1);
    //     i++;
    // }

    // i = 0;
    // temp = all->cmd;
    // while (i < all->cmd_total)
    // {
    //     pids[i] = fork();
    //     if (pids[i] < 0)
    //         exit(1);
    //     if (pids[i] == 0)
    //     {
    //         if (i != 0)
    //             dup2(fd[i][0], STDIN_FILENO);
    //         if (i != all->cmd_total - 1)
    //         {
    //             dup2(fd[i][1], STDOUT_FILENO);
    //         }
    //         close(fd[i][0]);
    //         close(fd[i][1]);
    //         path = try_path(temp->args[0]);
    //         execve(path, temp->args, all->env);
    //     }
    //     close(fd[i][0]);
    //     close(fd[i][1]);
    //     temp = temp->next;
    // }

    // int fd[2][2];
	// int pid1;
	// int pid2;
	// int pid3;

	// if (pipe(fd[0]) == -1)
	// 	return (1);
	// if (pipe(fd[1]) == -1)
	// 	return (1);

	// pid1 = fork();
	// if (pid1 < 0)
	// 	return (2);
	// if (pid1 == 0)
	// {
	// 	// Child process 1 (ls)
    //     path = try_path(temp->args[0]);
	// 	dup2(fd[0][1], STDOUT_FILENO);
	// 	close(fd[0][0]);
	// 	close(fd[0][1]);
	// 	close(fd[1][0]);
	// 	close(fd[1][1]);
    //     execve(path, temp->args, all->env);
	// }

	// pid2 = fork();
	// if (pid2 < 0)
	// 	return (3);
	// if (pid2 == 0)
	// {
	// 	// Child process 2 (grep)
    //     temp = temp->next;
    //     path = try_path(temp->args[0]);
	// 	dup2(fd[0][0], STDIN_FILENO);
	// 	dup2(fd[1][1], STDOUT_FILENO);
	// 	close(fd[0][0]);
	// 	close(fd[0][1]);
	// 	close(fd[1][0]);
	// 	close(fd[1][1]);
    //     execve(path, temp->args, all->env);
	// }

    
	// pid3 = fork();
	// if (pid3 < 0)
	// 	return (4);
	// if (pid3 == 0)
	// {
	// 	// Child process 3 (cat)
    //     temp = temp->next;
	// 	dup2(fd[1][0], STDIN_FILENO);
	// 	close(fd[0][0]);
	// 	close(fd[0][1]);
	// 	close(fd[1][0]);
	// 	close(fd[1][1]);
    //     path = try_path(temp->args[0]);
    //     execve(path, temp->args, all->env);
	// }

	// close(fd[0][0]);
	// close(fd[0][1]);
	// close(fd[1][0]);
	// close(fd[1][1]);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
	// waitpid(pid3, NULL, 0);
    return (0);
}