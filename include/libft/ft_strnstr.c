/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:10:34 by ntamiano          #+#    #+#             */
/*   Updated: 2023/08/01 12:15:12 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && len == 0)
		return (0);
	i = 0;
	if (!*little)
		return ((char *)big);
	else
	{
		while (big[i])
		{
			j = 0;
			while (big[i + j] == little[j] && ((i + j) < len))
			{
				if (little[j + 1] == '\0')
					return ((char *)big + i);
				j++;
			}
			i++;
		}
	}
	return (0);
}
