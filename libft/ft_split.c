/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:45:58 by taretiuk          #+#    #+#             */
/*   Updated: 2023/12/04 15:54:37 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*put_word(char const *s, char c)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_cpy_str(int i, char const *s, char c, char **res)
{
	if (!s)
		return (NULL);
	res[i] = put_word(s, c);
	if (!res[i])
	{
		while (i > 0)
		{
			i--;
			free(res[i]);
		}
		free(res);
		return (NULL);
	}
	return (res[i]);
}

char	**ft_split(char const *s, char c)
{
	int		nb_words;
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	i = -1;
	nb_words = word_cnt(s, c);
	res = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	while (++i < nb_words)
	{
		while (*s == c && *s != '\0')
			s++;
		res[i] = ft_cpy_str(i, s, c, res);
		if (res[i] == NULL)
			return (NULL);
		while (*s && *s != c)
			s++;
	}
	res[i] = 0;
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	char **result = ft_split("xxxxxxxxhello!", 'x');
	int i = 0;
	int n = 0;
	
	if (result == NULL)
		printf("Memory allocation failed");
	else
	{
		while (result[n] != NULL)
		{
			printf("%s", result[n]);
			n++;
		}
	}
	i = 0;
	while (i < n)
	{
		free(result[i]);
		i++;
	}
	free(result);
	result = NULL;
	return (0);
}
*/