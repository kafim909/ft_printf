/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:51:24 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prec_width(t_var *var)
{
	int		i;
	int		j;
	size_t	len;
	char	*temp;

	i = 0;
	j = 0;
	len = ft_strlen(var->utils->str);
	if (var->type->minus_d && len <= (size_t)var->flags->prec)
		var->type->minus_d++;
	if (len > (size_t)var->flags->prec)
		var->flags->prec = (int)len;
	temp = malloc(sizeof(char) * (var->flags->prec + 1 + var->type->minus_d));
	if (!temp)
		return (0);
	if (var->type->minus_d)
		temp[i++] = (var->utils->str)[j++];
	while (i < (var->flags->prec - (int)len) + var->type->minus_d)
		temp[i++] = '0';
	while ((var->utils->str)[j])
		temp[i++] = (var->utils->str)[j++];
	temp[i] = '\0';
	free(var->utils->str);
	var->utils->str = temp;
	return (1);
}
