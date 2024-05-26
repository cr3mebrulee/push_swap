/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:31:25 by taretiuk          #+#    #+#             */
/*   Updated: 2023/11/23 16:06:04 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*con;
	size_t	length;
	char	*start;

	length = ft_strlen(s1) + ft_strlen(s2);
	con = (char *) malloc(length + 1);
	start = con;
	if (!con)
		return (0);
	while (*s1)
	{
		*con = *s1;
		con++;
		s1++;
	}
	while (*s2)
	{
		*con = *s2;
		con++;
		s2++;
	}
	*con = '\0';
	return (start);
}
