/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:22:30 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	if_null(t_var *var)
{
	char	*s1;
	int		i;

	i = -1;
	s1 = "(null)";
	var->utils->str = malloc(sizeof(char) * 20);
	while (s1[++i])
		(var->utils->str)[i] = s1[i];
	(var->utils->str)[i] = '\0';
	return (1);
}

int	convert_str(t_var *var)
{
	int		i;

	i = 0;
	if (var->type->s_bol)
		return (if_null(var));
	var->utils->str = malloc(sizeof(char) * ft_strlen(var->type->s) + 1);
	if (!var->utils->str)
		return (0);
	while ((var->type->s)[i])
	{
		(var->utils->str)[i] = (var->type->s)[i];
		i++;
	}
	(var->utils->str)[i] = '\0';
	return (1);
}
