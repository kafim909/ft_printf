/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 09:02:32 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prec_width_str(t_var *var)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if ((int)ft_strlen(var->utils->str) <= var->flags->prec)
		return (width_noflags_noprec(var));
	temp = malloc(sizeof(char) * (var->flags->prec + 1));
	if (!temp)
		return (0);
	while (i < var->flags->width_size - var->flags->prec)
		temp[i++] = ' ';
	while (i < var->flags->prec)
		temp[i++] = (var->utils->str)[j++];
	temp[i] = '\0';
	free(var->utils->str);
	var->utils->str = temp;
	return (1);
}
