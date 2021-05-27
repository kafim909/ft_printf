/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_noflags_noprec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:13:54 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process(t_var *var, int len, int i, int j)
{
	char	*temp;

	temp = malloc(sizeof(char) * (len + var->flags->width_size + 2));
	if (!temp)
		return (0);
	if (var->flags->width_size)
		while (i < var->flags->width_size)
			temp[i++] = ' ';
	if (var->utils->str)
		while ((var->utils->str)[j])
			temp[i++] = (var->utils->str)[j++];
	else
		temp[i++] = '\0';
	free(var->utils->str);
	temp[i] = '\0';
	var->utils->str = temp;
	return (1);
}

int	width_noflags_noprec(t_var *var)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(var->utils->str);
	var->flags->width_size -= len;
	if (var->flags->width_size < 0)
		var->flags->width_size = 0;
	return (process(var, len, i, j));
}
