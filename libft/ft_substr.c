/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:12:01 by taretiuk          #+#    #+#             */
/*   Updated: 2023/12/04 12:43:56 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	size_t	s_length;

	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	if ((size_t)start > s_length)
		len = 0;
	else if (len > (s_length - start))
		len = s_length - start;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (start < s_length && s[start] != '\0' && len > 0)
	{
		dest[i] = s[start];
		i++;
		start++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
