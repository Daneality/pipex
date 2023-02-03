/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:48 by dsas              #+#    #+#             */
/*   Updated: 2023/02/03 18:32:59 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_commands(int argc, char **argv, char **env)
{
	int	i;
	char	**split_command;
	char	*command_path;

	i = 1;
	while (++i < argc - 1)
	{
		split_command = ft_split(argv[i], ' ');
		command_path = get_working_path(split_command[0], env);
		if (!command_path)
		{
			ft_free_strings(split_command);
			write(2, "Invalid command!\n", 18);
			exit(0);
		}
		else
		{
			ft_free_strings(split_command);
			free(command_path);
		}
	}
	return (1);
}

void	child(char *cmd, char **env)
{
	char	**cmd_split;
	char	*path_to_cmd;

	cmd_split = ft_split(cmd, ' ');
	path_to_cmd = get_working_path(cmd, env);
	if (execve(path_to_cmd, cmd_split, env) == -1)
	{
		msg_error("Error executing command");
		free(path_to_cmd);
		ft_free_strings(cmd_split);
		exit(0);
	}
}

void	pipex(char *cmd, char **env, t_pipex *ppx)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		msg_error("Error creating pipes");
	if (pid < 0)
		msg_error("Error creating process");
	else if(pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		child(cmd, env);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_pipex ppx;

	if (env)
		printf("kaif");
	get_infile(argv, &ppx);
	get_outfile(argv[argc - 1], &ppx);

}
