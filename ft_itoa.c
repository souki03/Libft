/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/13 14:34:40 by marvin            #+#    #+#             */
/*   Updated: 2023/11/13 14:34:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
	}
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_itoa(long n, char *res, int *index)
{
	if (n > 9)
	{
		ft_putnbr_itoa(n / 10, res, index);
		ft_putnbr_itoa(n % 10, res, index);
	}
	else
	{
		res[(*index)++] = '0' + n;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		taille;
	long	nbr;

	nbr = n;
	taille = count_size(nbr);
	res = malloc(sizeof(char) * (taille + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		res[i] = '-';
		nbr = -nbr;
		i++;
	}
	ft_putnbr_itoa(nbr, res, &i);
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("%s\n", ft_itoa(-4));
//     return (0);
// }