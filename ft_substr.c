/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:58:32 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/19 16:59:27 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dif(size_t len, size_t strsize, size_t start, char const *s)
{
	if (start > ft_strlen(s))
	{
		return (0 + 1);
	}
	if (start > len)
	{
		return (0 + 1);
	}
	if (len > strsize)
	{
		return (strsize + 1);
	}
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(*s) * (ft_dif(len, ft_strlen(s) - start, start, s)));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			tab[j] = s[i];
			j++;
		}
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char src[] = "1";

// 	int m = 42;
// 	int n = 42000000;

// 	char *dest = ft_substr(src, m, n);

// 	printf("%s\n", dest);
// 	free(dest);
// 	return (0);
// }