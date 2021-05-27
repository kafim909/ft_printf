/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_HEX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:20:06 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_x(t_var *var)
{
	if (var->type->HEX || var->type->X_bol)
	{
		var->utils->str = ft_itoa_base(var->type->HEX, "0123456789ABCDEF");
		if (!var->utils->str)
			return (0);
	}
	if (var->type->hex || var->type->x_bol)
	{
		var->utils->str = ft_itoa_base(var->type->hex, "0123456789abcdef");
		if (!var->utils->str)
			return (0);
	}
	return (1);
}
