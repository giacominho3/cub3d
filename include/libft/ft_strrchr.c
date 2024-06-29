/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:46:39 by ntamiano          #+#    #+#             */
/*   Updated: 2023/08/01 12:15:12 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	p;
	size_t	len;

	p = c;
	len = ft_strlen(s);
	while (len --)
	{
		if (s[len] == p)
			return ((char *)s + len);
	}
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	return (0);
}
