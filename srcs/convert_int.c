/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:14:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:29:42 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_int(t_var *var)
{
	if (var->flags->period && !var->flags->prec
		&& !var->type->d && var->type->d_bol)
	{
		var->utils->str = malloc(sizeof(char) * 1);
		if (!var->utils->str)
			return (0);
		var->utils->str[0] = '\0';
		return (1);
	}
	if (var->type->d || var->type->d_bol)
	{
		var->utils->str = ft_itoa(var->type->d);
		if (!var->utils->str)
			return (0);
	}
	if (var->type->i)
	{
		var->utils->str = ft_itoa(var->type->i);
		if (!var->utils->str)
			return (0);
	}
	return (1);
}
