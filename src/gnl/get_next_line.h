/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbasile <mbasile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:17:00 by mbasile           #+#    #+#             */
/*   Updated: 2023/05/05 18:34:36 by mbasile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

//get_next_line_utils.c
int		ft_strlen_2(char *str);
char	*ft_strdup_2(char *str);

//get_next_line.c
char	*get_next_line(int fd);

#endif
