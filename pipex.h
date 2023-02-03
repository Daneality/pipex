/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:30:15 by dsas              #+#    #+#             */
/*   Updated: 2023/02/03 17:58:16 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef	struct s_pipex
{
	int		infile;
	int		outfile;
	int		here_doc;
	int		in_status;
	int 	first;
	
} t_pipex;

# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

char	*get_working_path(char *cmd, char **env);
void	msg_error(char *err);
int		get_infile(char **argv, t_pipex *pipex);
int		get_outfile(char *argv, t_pipex *pipex);

#endif