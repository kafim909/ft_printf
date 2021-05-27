/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:18:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:23 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static t_var	*parse_flags_2(char *input, int i, va_list args, t_var *var)
{
	if (ft_isdigit(input[i]) && !var->flags->wd_width)
		var->flags->width_size = atoi(input + i);
	while (ft_isdigit(input[i]))
		i++;
	if (input[i] == '.' && input[i++])
	{
		var->flags->period = 1;
		if (input[i] == '*')
		{
			var->flags->prec = va_arg(args, int);
			var->flags->wd_prec = 1;
		}
		else
			var->flags->prec = atoi(input + i);
	}
	return (var);
}

t_var	*parse_flags(char *input, int i, va_list args, t_var *var)
{
	if (input[i] == '%')
		i++;
	while (!is_type(input[i]) && input[i] != '.' && input[i] != '*'
		&& !one_to_nine(input[i]) && input[i])
	{
		if (input[i] == '0')
			var->flags->zero = 1;
		if (input[i] == '-')
			var->flags->minus = 1;
		i++;
	}
	if (input[i] == '*')
	{
		var->flags->width_size = va_arg(args, int);
		var->flags->wd_width = 1;
		if (var->flags->width_size < 0)
		{
			var->flags->width_size *= -1;
			var->flags->minus = 1;
		}
		i++;
	}
	return (parse_flags_2(input, i, args, var));
}
