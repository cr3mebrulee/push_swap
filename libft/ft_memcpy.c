/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:47:55 by taretiuk          #+#    #+#             */
/*   Updated: 2023/12/04 10:52:28 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n-- > 0)
	{
		*(d++) = *(s++);
	}
	return (dest);
}
/*
int	main(void)
{
	char	mem[30];
	
	 if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
        write(1, "dest's adress was not returned\n", 31);
    write(1, mem, 30);
	return (0);
}
*/
