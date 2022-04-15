/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:16:52 by mouizar           #+#    #+#             */
/*   Updated: 2022/04/15 03:19:29 by mouizar          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include <signal.h>

void	print_bin(char *bmsg, int ib, int ascii)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if ((ascii % 2) == 0)
			bmsg[ib] = '0';
		else
			bmsg[ib] = '1';
		ascii /= 2;
		ib--;
		j++;
	}
}

char	*ft_str_bits(char *str)
{
	int		i;
	int		lenth;
	int		ascii;
	char	*binary_message;
	int		ibits;

	if (!str)
		return (NULL);
	i = 0;
	ibits = (i + 1) * 8;
	lenth = ft_strlen(str);
	binary_message = ft_calloc(lenth * 8, sizeof(char));
	while (i < lenth)
	{
		ibits = (i + 1) * 8;
		ibits--;
		ascii = (int)str[i];
		print_bin(binary_message, ibits, ascii);
		i++;
	}
	return (binary_message);
}

int	main(int ac, char**av)
{
	char	*message;
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid > 0)
		{
			message = ft_str_bits(av[2]);
			while (*message)
			{
				usleep(100);
				if (*message == '0')
					kill(pid, SIGUSR1);
				if (*message == '1')
					kill(pid, SIGUSR2);
				message++;
			}
		}
	}
	else
		write(1, "syntax error.enter pid + string\n", 32);
}
