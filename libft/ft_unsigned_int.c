/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:18:04 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/16 20:54:26 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unsigned_int(unsigned int number, int *length)
{
	if (number > 9)
	{
		ft_unsigned_int(number / 10, length);
		ft_unsigned_int(number % 10, length);
	}
	else
		ft_char_length((number + 48), length);
}
