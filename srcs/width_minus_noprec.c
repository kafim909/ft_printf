/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_noprec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:49:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(t_var *var, char **temp)
{
	int	i;

	i = 0;
	if (var->type->c_bol)
		ft_putchar('\0');
	if (var->utils->str && !var->type->c_bol)
	{
		while ((var->utils->str[i]))
		{
			(*temp)[i] = (var->utils->str)[i];
			i++;
		}
	}
	if (var->flags->width_size)
		while (i < var->flags->width_size)
			(*temp)[i++] = ' ';
	free(var->utils->str);
	(*temp)[i] = '\0';
	var->utils->str = *temp;
	return (1);
}

int	width_minus_noprec(t_var *var)
{
	int		len;
	char	*temp;

	temp = NULL;
	len = ft_strlen(var->utils->str);
	if ((var->flags->width_size - len) < 0)
		var->flags->width_size = 0;
	temp = malloc(sizeof(char) * (len + var->flags->width_size + 2));
	if (!temp)
		return (0);
	return (process(var, &temp));
}
