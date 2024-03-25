/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:48 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/20 15:32:55 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_mem(char **tab_to_free)
{
	int	i;

	i = 0;
	while (tab_to_free[i])
	{
		free(tab_to_free[i]);
		i++;
	}
	free(tab_to_free);
}

char	*ft_strduplicate(const char *s, char c)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		len++;
	}
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static int	to_complete(char **dest, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			dest[j] = ft_strduplicate(&s[i], c);
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	dest[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	if (!to_complete(split, s, c))
		return (free_mem(split), NULL);
	return (split);
}

// #include <stdio.h>

// void	ft_show_split(char **dest)
// {
// 	int	i;

// 	i = 0;
// 	while (dest[i])
// 	{
// 		printf("%s\n", dest[i]);
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	char	*text;
// 	char	**result;
// 	int		i;

// 	text = "test-1-tesqdqd-david22";
// 	result = ft_split(text, '-');
// 	ft_show_split(result);
// 	// Libérer la mémoire allouée
// 	i = 0;
// 	while (result[i])
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
