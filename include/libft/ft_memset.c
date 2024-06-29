/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:08:57 by ntamiano          #+#    #+#             */
/*   Updated: 2023/08/01 12:15:12 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Void *str = pointer in input
// Int c = value inserted
// size_t = per n bytes

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (str);
}
