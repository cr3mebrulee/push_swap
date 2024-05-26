/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:13:24 by taretiuk          #+#    #+#             */
/*   Updated: 2023/11/30 15:22:32 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennum(long num)
{
	int	strlen;

	strlen = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		strlen++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		strlen++;
	}
	return (strlen);
}

char	*ft_itoa(int n)
{
	int		lenstr;
	long	num;
	char	*str;

	num = n;
	lenstr = ft_lennum(num);
	str = (char *)malloc(sizeof(char) * (lenstr + 1));
	if (!str)
		return (NULL);
	*(str + lenstr--) = '\0';
	if (num == 0)
	{
		*(str + 0) = '0';
	}
	else if (num < 0)
	{
		num *= -1;
		*(str + 0) = '-';
	}
	while (num > 0)
	{
		*(str + lenstr--) = (48 + (num % 10));
		num /= 10;
	}
	return (str);
}
/*
int main(void)
{
    char    *s = ft_itoa(-30457109);
    printf("%s\n", s);
    return(0);
}
*/