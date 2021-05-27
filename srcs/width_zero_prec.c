/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_zero_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:25:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:38:15 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(t_var *var, int i, int j, size_t len)
{
	char	*temp;

	temp = malloc(sizeof(char) * (var->flags->width_size
				+ 1 + var->type->minus_d));
	if (!temp)
		return (0);
	while (i < (var->flags->width_size - var->flags->prec - var->type->minus_d)
		&& !(len == (size_t)var->flags->width_size))
		temp[i++] = ' ';
	if (var->type->minus_d)
		temp[i++] = (var->utils->str)[j++];
	while (i < (var->flags->width_size - (int)len + var->type->minus_d)
		&& !(len == (size_t)var->flags->width_size))
		temp[i++] = '0';
	while ((var->utils->str)[j])
		temp[i++] = (var->utils->str)[j++];
	temp[i] = '\0';
	free(var->utils->str);
	var->utils->str = temp;
	return (1);
}

int	width_zero_prec(t_var *var)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(var->utils->str);
	if ((len > (size_t)var->flags->prec)
		|| (!var->flags->prec && var->type->minus_d)
		|| (len >= (size_t)var->flags->prec && !var->utils->str))
		return (width_noflags_noprec(var));
	if (len > (size_t)var->flags->width_size)
		var->flags->width_size = (int)len;
	if (var->flags->prec == var->flags->width_size && var->type->minus_d)
		var->flags->width_size++;
	if (len > (size_t)var->flags->prec)
		var->flags->width_size--;
	return (process(var, i, j, len));
}
