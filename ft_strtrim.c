/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:49:08 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/15 16:13:00 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tab;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j - 1]) != 0)
		j--;
	tab = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!tab)
		return (NULL);
	k = 0;
	while (i < j)
	{
		tab[k] = s1[i];
		k++;
		i++;
	}
	tab[k] = '\0';
	return (tab);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char test1[] = "-- dad -- d---";
// 	char test2[] = "-";
// 	printf("%s\n", ft_strtrim(test1, test2));
// 	return (0);
// }