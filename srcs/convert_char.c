/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:10:51 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:18:39 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_char(t_var *var)
{
	var->utils->str = malloc(sizeof(char) * 2);
	if (!var->utils->str)
		return (-1);
	var->utils->str[0] = var->type->c;
	var->utils->str[1] = '\0';
	return (1);
}
