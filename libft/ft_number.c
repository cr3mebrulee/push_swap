/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:55:39 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/16 20:53:29 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_number(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		(*len) += 1;
	}
	if (nbr > 9)
	{
		ft_number(nbr / 10, len);
		ft_number(nbr % 10, len);
	}
	else
		ft_char_length((nbr % 10 + '0'), len);
}
