/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouizar <mouizar@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:20:32 by mouizar           #+#    #+#             */
/*   Updated: 2022/04/15 03:24:51 by mouizar          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

int	ft_power(int x, int y)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < y)
	{
		res *= x;
		i++;
	}
	return (res);
}

void	handler(int sig)
{
	static int	base10 = 0 ;
	static int	i;

	i = 7;
	if (sig == SIGUSR2)
		base10 += 1 * ft_power(2, i);
	i--;
	if (i == -1)
	{
		write(1, &base10, 1);
		i = 7;
		base10 = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
