/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:43 by ntamiano          #+#    #+#             */
/*   Updated: 2023/08/01 12:15:12 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;

	if ((!dst || !src) && size == 0)
		return (0);
	i = 0;
	d_len = ft_strlen(dst);
	if (size > d_len)
	{
		while (src[i] != 0 && i < size - d_len - 1)
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[i + d_len] = '\0';
		return (d_len + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
