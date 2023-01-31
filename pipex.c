/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:48 by dsas              #+#    #+#             */
/*   Updated: 2023/01/31 20:58:10 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_commands(int argc, char **argv, char **env)
{
	int	i;
	char	**split_command;
	char	*command_path;

	i = 1;
	while (++i <= argc - 1)
	{
		split_command = ft_split(argv[i], ' ');
		command_path = get_working_path(split_command[i], env);
		if (!command_path)
		{
			ft_free_strings(split_command);
			write(2, "Invalid command!", 17);
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

int	main(int argc, char **argv, char **env)
{


	check_commands(argc, argv, env);
}
