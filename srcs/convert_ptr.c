/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:19:07 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:30:23 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_ptr(t_var *var)
{
	char	*temp;
	int		i;
	int		j;

	temp = NULL;
	i = 2;
	j = 0;
	temp = ft_itoa_base((unsigned long long int)var->type->p,
			"0123456789abcdef");
	if (!temp)
		return (0);
	var->utils->str = malloc(sizeof(char) * (ft_strlen(temp) + 10));
	if (!var->utils->str)
		return (0);
	var->utils->str[0] = '0';
	var->utils->str[1] = 'x';
	while (temp[j])
		var->utils->str[i++] = temp[j++];
	free(temp);
	var->utils->str[i] = '\0';
	return (1);
}
