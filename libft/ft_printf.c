/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:32:13 by taretiuk          #+#    #+#             */
/*   Updated: 2024/01/26 11:20:04 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_type(char str, va_list *args, int *length, int *i)
{
	if (str == 's')
		ft_string(va_arg(*args, char *), length);
	else if (str == 'd' || str == 'i')
		ft_number(va_arg(*args, int), length);
	else if (str == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), length);
	else if (str == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), length, 'x');
	else if (str == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), length, 'X');
	else if (str == 'p')
		ft_pointer(va_arg(*args, void *), length);
	else if (str == 'c')
		ft_character(va_arg(*args, int), length);
	else if (str == '%')
		ft_character('%', length);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		i;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_type(str[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_char_length((char)str[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
