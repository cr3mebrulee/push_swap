/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:48:22 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/16 20:50:32 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_hexadecimal(unsigned int decimal, int *length, char format)
{
	char	string[25];
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
