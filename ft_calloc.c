/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:24:45 by souki             #+#    #+#             */
/*   Updated: 2023/11/15 15:02:22 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*tab;
	unsigned char	*ptr;

	if (nmemb && size > (size_t)-1 / nmemb)
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	ptr = (unsigned char *)tab;
	ft_bzero(ptr, nmemb * size);
	return (tab);
}
