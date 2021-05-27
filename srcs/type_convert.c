/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:02:13 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:33:45 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_convert_2(t_var *var)
{
	if (var->type->modulo)
		if (!convert_modulo(var))
			return (0);
	if (var->type->p || var->type->p_bol)
		if (!convert_ptr(var))
			return (0);
	if (var->type->s || var->type->s_bol)
		if (!convert_str(var))
			return (0);
	if (var->type->u || var->type->u_bol)
	{
		if (var->flags->period && !var->flags->prec && var->type->u_bol)
			return (1);
		if (!convert_unsigned(var))
			return (0);
	}
	return (1);
}

int	type_convert(t_var *var)
{
	if ((var->type->s && var->flags->zero && var->flags->period)
		|| (var->type->s && var->flags->period
			&& !var->flags->prec && !var->flags->width_size)
		|| (var->flags->period && !var->flags->prec
			&& (var->type->x_bol || var->type->X_bol
				|| var->type->d_bol)))
		return (1);
	if (var->type->c || var->type->c_bol)
		if (!convert_char(var))
			return (0);
	if (var->type->d || var->type->i || var->type->d_bol)
		if (!convert_int(var))
			return (0);
	if (var->type->HEX || var->type->X_bol)
		if (!convert_x(var))
			return (0);
	if (var->type->hex || var->type-> x_bol)
		if (!convert_x(var))
			return (0);
	return (type_convert_2(var));
}
