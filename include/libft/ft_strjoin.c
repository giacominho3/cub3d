/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <vpescete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:13:25 by ntamiano          #+#    #+#             */
/*   Updated: 2023/08/01 12:15:12 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	size_t	k;
	char	*str;

	k = 0;
	if (!s1 || !s2)
		return (0);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	str = malloc((i1 + i2 + 1) * sizeof(char));
	if (!str)
		return (0);
	while (*s1)
		str[k++] = *s1++;
	while (*s2)
		str[k++] = *s2++;
	str[k] = 0;
	return (str);
}
