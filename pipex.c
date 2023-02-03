/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:48 by dsas              #+#    #+#             */
/*   Updated: 2023/02/03 16:05:41 by dsas             ###   ########.fr       */
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


int	main(int argc, char **argv, char **env)
{
	t_pipex ppx;

	if (env)
		printf("kaif");
	// if (!get_infile(argv, &ppx))
	// {
	// 	msg_error("Error with input file");
	// 	ppx.in_status = 0;	
	// }
	get_infile(argv, &ppx);
	get_outfile(argv[argc - 1], &ppx);

}
