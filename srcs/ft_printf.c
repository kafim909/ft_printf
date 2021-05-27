/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:36:21 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:27:02 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_1(t_var *var, const char *s, int start)
{
	var->utils->temp = ft_substr((char *)s, start, var->i - start);
	if (!var->utils->temp)
		return (-1);
	ft_putstr(var->utils->temp);
	var->utils->len += ft_strlen(var->utils->temp);
	free(var->utils->temp);
	var->utils->temp = NULL;
	return (1);
}

static int	process_2(va_list args, const char *s, t_var *var)
{
	var = parse_type(s[var->i], args, var);
	if (var->flags->width_size && var->type->c_bol)
	{
		var->flags->width_size--;
		if (!var->flags->width_size)
			ft_putchar('\0');
	}
	if (var->flags->wd_prec && var->flags->prec < 0)
	{
		var->flags->prec = 0;
		var->flags->period = 0;
		var->flags->wd_prec = 0;
	}
	if (!type_convert(var))
		return (-1);
	if (!data_flag_convert(var))
		return (-1);
	return (1);
}

static int	process_4(const char *s, va_list args, t_var *var)
{
	while (s[var->i] && !is_type(s[var->i]))
		var->i++;
	if (is_type(s[var->i]))
		if (!process_2(args, s, var))
			return (-1);
	if (var->utils->str || bolcheck(var))
	{
		ft_putstr(var->utils->str);
		if (var->type->c_bol && !var->flags->minus)
			ft_putchar('\0');
		var->utils->len += ft_strlen(var->utils->str);
		free(var->utils->str);
		var->utils->str = NULL;
	}
	if (s[var->i])
		var->i++;
	var->utils->len += var->type->c_bol;
	return (1);
}

static int	process_3(t_var *var, const char *s, va_list args, int start)
{
	while (s[var->i])
	{	
		init_flags(var);
		init_type(var);
		start = var->i;
		while (s[var->i] && s[var->i] != '%')
			var->i++;
		if (start != var->i)
			if (!process_1(var, s, start))
				return (-1);
		if (s[var->i] == '%')
		{
			var = parse_flags((char *)s, var->i, args, var);
			var->i++;
		}
		if (!process_4(s, args, var))
			return (-1);
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	t_var	*var;
	va_list	args;
	int		start;
	int		ret;

	start = 0;
	ret = 0;
	var = malloc(sizeof(t_var));
	var->flags = malloc(sizeof(t_flags));
	var->utils = malloc(sizeof(t_utils));
	var->type = malloc(sizeof(t_type));
	va_start(args, s);
	init_utils(var);
	if (!process_3(var, s, args, start))
		return (-1);
	va_end(args);
	ret = var->utils->len;
	free(var->flags);
	free(var->utils);
	free(var->type);
	free(var);
	return (ret);
}
