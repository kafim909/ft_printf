/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:20:52 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:17:52 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_var	*parse_type_3(char c, va_list args, t_var *var)
{
	if (c == 'X')
	{
		var->type->HEX = va_arg(args, unsigned int);
		if (var->type->HEX == 0)
			var->type->X_bol = 1;
	}
	if (c == '%')
		var->type->modulo = '%';
	return (var);
}

static t_var	*parse_type_2(char c, va_list args, t_var *var)
{
	if (c == 'i' || c == 'd')
	{
		var->type->d = va_arg(args, int);
		if (var->type->d == 0)
			var->type->d_bol = 1;
		if (var->type->d < 0)
			var->type->minus_d = 1;
	}
	if (c == 'u')
	{
		var->type->u = va_arg(args, unsigned int);
		if (var->type->u == 0)
			var->type->u_bol = 1;
	}
	if (c == 'x')
	{
		var->type->hex = va_arg(args, unsigned int);
		if (var->type->hex == 0)
			var->type->x_bol = 1;
	}
	return (parse_type_3(c, args, var));
}

t_var	*parse_type(char c, va_list args, t_var *var)
{
	if (c == 'c')
	{
		var->type->c = va_arg(args, int);
		if (var->type->c == 0)
			var->type->c_bol = 1;
	}
	if (c == 's')
	{
		var->type->s = va_arg(args, char *);
		if (!var->type->s)
			var->type->s_bol = 1;
	}
	if (c == 'p')
	{
		var->type->p = va_arg(args, void *);
		if (var->type->p == 0)
			var->type->p_bol = 1;
	}
	return (parse_type_2(c, args, var));
}
