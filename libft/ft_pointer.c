/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:51:36 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/16 20:54:05 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_long_hex(unsigned long long decimal, int *length, char format)
{
	char	string[100];
	char	*base_character;
	int		i;

	if (format == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (decimal == 0)
	{
		ft_char_length('0', length);
		return ;
	}
	while (decimal != 0)
	{
		string[i] = base_character [decimal % 16];
		decimal = decimal / 16;
		i++;
	}
	while (i--)
		ft_char_length(string[i], length);
}

void	ft_pointer(void *ptr, int *length)
{
	if (0 == ptr)
	{
		write(1, "(nil)", 5);
		(*length) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*length) += 2;
	ft_long_hex((unsigned long long)ptr, length, 'x');
}
