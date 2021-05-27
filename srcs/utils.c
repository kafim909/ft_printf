/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:51:27 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:17:52 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	one_to_nine(char c)
{
	if (c >= 49 && c <= 57)
		return (1);
	else
		return (0);
}

int	bolcheck(t_var *var)
{
	if (var->type->c_bol)
		return (1);
	if (var->type->d_bol)
		return (1);
	if (var->type->p_bol)
		return (1);
	if (var->type->s_bol)
		return (1);
	if (var->type->u_bol)
		return (1);
	if (var->type->X_bol)
		return (1);
	if (var->type->x_bol)
		return (1);
	return (0);
}
