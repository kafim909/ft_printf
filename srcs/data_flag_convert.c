/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_flag_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:35:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:32:29 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	string_check(t_var *var)
{
	if ((var->type->s || var->type->s_bol) && var->flags->prec < 0)
	{
		var->flags->prec = 0;
		var->flags->period = 0;
	}
}

static int	data_flag_convert_3(t_var *var)
{
	if (var->flags->width_size >= var->flags->prec
		&& var->flags->period && !var->flags->zero
		&& !var->flags->minus && !var->type->s && !var->type->s_bol)
		if (!width_noflags_prec(var))
			return (0);
	if (var->flags->width_size >= var->flags->prec && var->flags->period
		&& var->flags->zero && !var->type->s && !var->type->s_bol)
		if (!width_zero_prec(var))
			return (0);
	if (var->flags->width_size >= var->flags->prec
		&& var->flags->period && !var->flags->zero
		&& !var->flags->minus && (var->type->s || var->type->s_bol))
		if (!width_prec_str(var))
			return (0);
	return (1);
}

static int	data_flag_convert_2(t_var *var)
{
	if (var->flags->width_size && !var->flags->period
		&& !var->flags->minus && !var->flags->zero)
		if (!width_noflags_noprec(var))
			return (0);
	if (var->flags->width_size && var->flags->period
		&& var->flags->minus && (var->type->s || var->type->s_bol))
		if (!width_minus_prec_str(var))
			return (0);
	if (var->flags->width_size >= var->flags->prec && var->flags->period
		&& var->flags->minus && !var->type->s && !var->type->s_bol)
		if (!width_minus_prec(var))
			return (0);
	if (var->flags->prec > var->flags->width_size
		&& !var->type->s && !var->type->s_bol)
		if (!prec_width(var))
			return (0);
	if (var->flags->prec > var->flags->width_size
		&& (var->type->s || var->type->s_bol))
		if (!prec_width_str(var))
			return (0);
	return (data_flag_convert_3(var));
}

int	data_flag_convert(t_var *var)
{
	string_check(var);
	if (!var->flags->minus && !var->flags->period
		&& !var->flags->prec && !var->flags->wd_prec
		&& !var->flags->wd_width && !var->flags->width_size
		&& !var->flags->zero)
		return (1);
	if (var->flags->width_size == 0 && !var->utils->str)
		return (1);
	if (!var->flags->width_size && !var->flags->period)
		return (1);
	if (var->flags->width_size && var->flags->zero
		&& var->flags->minus && !var->flags->period)
		if (!width_minus_noprec(var))
			return (0);
	if (var->flags->width_size && var->flags->minus
		&& !var->flags->zero && !var->flags->period)
		if (!width_minus_noprec(var))
			return (0);
	if (var->flags->width_size && var->flags->zero
		&& !var->flags->period && !var->type->s && !var->type->s_bol)
		if (!width_zero_noprec(var))
			return (0);
	return (data_flag_convert_2(var));
}
