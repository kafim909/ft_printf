/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:32:23 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/24 18:12:08 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	n_len(unsigned int n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		i++;
	return (i);
}

char	*unsigned_itoa(unsigned int n)
{
	size_t	i;
	char	*str;

	i = n_len(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[i--] = '\0';
	while (n)
	{
		str[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (str);
}
