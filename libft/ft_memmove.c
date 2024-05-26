/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:27:20 by taretiuk          #+#    #+#             */
/*   Updated: 2023/12/03 11:52:54 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (!dest && !src)
		return (NULL);
	tmp = (unsigned char *)src;
	if ((unsigned char *)dest > tmp)
	{
		i = n;
		while (n-- > 0)
		{
			((unsigned char *)dest)[n] = tmp[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = tmp[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[30];
	char *src = "lorem ipum dolor sit a cat";
	 if (dest != ft_memmove(dest, src, 8))
        write(1, "dest's adress was not returned\n", 31);
    write(1, dest, 22);;
	return (0);
}
*/
