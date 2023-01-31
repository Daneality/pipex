/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:33:48 by dsas              #+#    #+#             */
/*   Updated: 2023/01/31 18:50:33 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];

	ft_printf("creating a child\n");
	pid = fork();
	if (pid == 0)
	{
		ft_printf("I am a child, sleeping\n");
		sleep (20);
		ft_printf("I had enough sleep\n");
	}
	else
	{
		wait(0);
		ft_printf("child should have finished\n");
	}
}