/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:15:28 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:27:40 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_utils(t_var *var)
{
	var->utils->len = 0;
	var->i = 0;
	var->utils->temp = NULL;
	var->utils->str = NULL;
}

void	init_type(t_var *var)
{
	var->type->c = 0;
	var->type->d = 0;
	var->type->hex = 0;
	var->type->HEX = 0;
	var->type->i = 0;
	var->type->p = 0;
	var->type->s = 0;
	var->type->u = 0;
	var->type->modulo = 0;
	var->type->s_bol = 0;
	var->type->c_bol = 0;
	var->type->d_bol = 0;
	var->type->u_bol = 0;
	var->type->p_bol = 0;
	var->type->x_bol = 0;
	var->type->X_bol = 0;
	var->type->minus_d = 0;
}

void	init_flags(t_var *var)
{
	var->flags->minus = 0;
	var->flags->period = 0;
	var->flags->prec = 0;
	var->flags->wd_prec = 0;
	var->flags->wd_width = 0;
	var->flags->width_size = 0;
	var->flags->zero = 0;
}
