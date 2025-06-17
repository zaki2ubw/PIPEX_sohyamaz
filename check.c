/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 21:28:27 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/17 22:06:44 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	format_check(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("usage:./pipex infile \"cmd1 -op\" \"cmd2 -op\" outfile", 2);
		exit(ERR_BAD_FORMAT);
	}
	return ;
}

void	file_check(int *input, int *output, char *infile, char *outfile)
{
	*input = open(infile, O_RDONLY);
	if (*input < 0)
		exit(ERR_FILE_OPEN_FAILED);
	*output = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*input < 0)
		exit(ERR_FILE_OPEN_FAILED);
	return ;
}
