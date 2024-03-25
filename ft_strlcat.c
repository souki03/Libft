/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:39:33 by souki             #+#    #+#             */
/*   Updated: 2023/11/19 18:54:54 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	dest_lenght;
	size_t	src_length;

	if (dest == NULL && !size)
		return (0);
	dest_lenght = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (size <= dest_lenght)
		return (size + src_length);
	i = 0;
	while (src[i] && (dest_lenght + i) < (size - 1))
	{
		dest[dest_lenght + i] = src[i];
		i++;
	}
	dest[dest_lenght + i] = '\0';
	return (dest_lenght + src_length);
}
