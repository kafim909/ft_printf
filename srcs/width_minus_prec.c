/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 09:46:53 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:34:51 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(t_var *var, int i, int j, size_t len)
{
	char	*temp;

	temp = malloc(sizeof(char) * (var->flags->width_size
				+ 2 + var->type->minus_d));
	if (!temp)
		return (0);
	if (var->type->minus_d)
	{
		temp[i++] = (var->utils->str)[j++];
		var->type->minus_d++;
	}
	while (i < (var->flags->prec - (int)len + var->type->minus_d))
		temp[i++] = '0';
	if (var->utils->str)
		while ((var->utils->str)[j])
			temp[i++] = (var->utils->str)[j++];
	while (i < var->flags->width_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	free(var->utils->str);
	var->utils->str = temp;
	return (1);
}

int	width_minus_prec(t_var *var)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(var->utils->str);
	if (len > (size_t)var->flags->prec)
		return (width_minus_noprec(var));
	if (len > (size_t)var->flags->width_size)
		var->flags->width_size = (int)len;
	return (process(var, i, j, len));
}
