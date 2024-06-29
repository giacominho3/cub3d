/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:18:54 by ntamiano          #+#    #+#             */
/*   Updated: 2023/01/31 16:02:17 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_int(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else
		return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	longnb;

	if (check_int(n, fd) == (1))
		return ;
	longnb = n;
	if (longnb < 0)
	{
		write (fd, "-", 1);
		longnb *= -1;
	}
	if (longnb < 10)
	{
		c = longnb + '0';
		write (fd, &c, 1);
	}
	else
	{
		c = longnb % 10 + '0';
		ft_putnbr_fd (longnb / 10, fd);
		write (fd, &c, 1);
	}
	return ;
}
