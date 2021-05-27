/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_minus_prec_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:07:33 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_minus_prec_str(t_var *var)
{
	int		i;
	int		j;
	size_t	len;
	char	*temp;

	i = 0;
	j = 0;
	len = ft_strlen(var->utils->str);
	if (len < (size_t)var->flags->prec)
		return (width_minus_noprec(var));
	temp = malloc(sizeof(char) * (var->flags->width_size + 10));
	if (!temp)
		return (0);
	while ((var->utils->str)[j] && i < var->flags->prec)
		temp[i++] = (var->utils->str)[j++];
	while (i < var->flags->width_size)
		temp[i++] = ' ';
	free(var->utils->str);
	temp[i] = '\0';
	var->utils->str = temp;
	return (1);
}
