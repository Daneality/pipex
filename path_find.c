/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:07:04 by dsas              #+#    #+#             */
/*   Updated: 2023/01/31 19:52:09 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_path_env(char **env)
{
	int	i;

	i = 0;
	while (1)
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			break ;
		i++;
	}
	return (i);
}

char	*get_working_path(char *cmd, char **env)
{
	int		i;
	char	**binary_paths;
	char	*one_path;
	char	*one_command_path;

	i = find_path_env(env);
	binary_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (binary_paths[++i])
	{
		one_path = ft_strjoin(binary_paths[i], "/");
		one_command_path = ft_strjoin(one_path, cmd);
		free(one_path);
		if (access(one_command_path, F_OK))
		{
			ft_free_strings(binary_paths);
			return (one_command_path);
		}
		free(one_command_path);
	}
	ft_free_strings(binary_paths);
	return (NULL);
}
