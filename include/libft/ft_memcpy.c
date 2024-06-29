/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:49:37 by ntamiano          #+#    #+#             */
/*   Updated: 2023/08/01 12:15:12 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*dest_p;
	const char		*src_p;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	i = 0;
	dest_p = dest;
	src_p = src;
	while (n > 0)
	{
		dest_p[i] = src_p[i];
		i++;
		n--;
	}
	dest_p[i] = '\0';
	return (dest);
}
