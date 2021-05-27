/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_noflags_prec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:33:30 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:35:41 by mtournay         ###   ########.fr       */
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
	while (i < (var->flags->width_size - var->flags->prec
			- var->type->minus_d))
		temp[i++] = ' ';
	if (var->type->minus_d)
		temp[i++] = (var->utils->str)[j++];
	while (i < (var->flags->width_size - (int)len + var->type->minus_d))
		temp[i++] = '0';
	if (var->utils->str)
		while ((var->utils->str)[j])
			temp[i++] = (var->utils->str)[j++];
	free(var->utils->str);
	temp[i] = '\0';
	var->utils->str = temp;
	return (1);
}

int	width_noflags_prec(t_var *var)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(var->utils->str);
	if ((len > (size_t)var->flags->prec)
		|| (!var->flags->prec && var->type->minus_d))
		return (width_noflags_noprec(var));
	if (len > (size_t)var->flags->width_size)
		var->flags->width_size = len;
	if (var->flags->prec == var->flags->width_size)
	{
		if (var->type->minus_d)
		{
			var->flags->prec++;
			var->type->minus_d++;
		}
		else
			var->flags->prec++;
	}
	if (len > (size_t)var->flags->prec)
		var->flags->width_size--;
	return (process(var, i, j, len));
}
