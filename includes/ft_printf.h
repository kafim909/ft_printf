/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:33:32 by mtournay          #+#    #+#             */
/*   Updated: 2021/05/27 14:28:03 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_utils
{
	int				len;
	char			*str;
	char			*temp;
}					t_utils;

typedef struct s_type
{
	unsigned char	c;
	void			*p;
	int				d;
	int				i;
	char			*s;
	unsigned int	u;
	unsigned int	hex;
	unsigned int	HEX;
	char			modulo;
	int				s_bol;
	int				c_bol;
	int				p_bol;
	int				d_bol;
	int				u_bol;
	int				x_bol;
	int				X_bol;
	int				minus_d;
}					t_type;

typedef struct s_flags
{
	int			zero;
	int			minus;
	int			wd_width;
	int			width_size;
	int			period;
	int			prec;
	int			wd_prec;
}				t_flags;

typedef struct s_var
{
	int				i;
	t_utils			*utils;
	t_type			*type;
	t_flags			*flags;
}					t_var;

int		bolcheck(t_var *var);
int		ft_printf(const char *s, ...);
int		is_type(char c);
void	init_utils(t_var *var);
void	init_type(t_var *var);
void	init_flags(t_var *var);
t_var	*parse_flags(char *input, int i, va_list args, t_var *var);
t_var	*parse_type(char c, va_list args, t_var *var);
int		type_convert(t_var *var);
char	*ft_itoa_base(unsigned long long nbr, char *base);
char	*unsigned_itoa(unsigned int n);
int		one_to_nine(char c);

int		convert_int(t_var *var);
int		convert_char(t_var *var);
int		convert_x(t_var *var);
int		convert_modulo(t_var *var);
int		convert_ptr(t_var *var);
int		convert_str(t_var *var);
int		convert_unsigned(t_var *var);

int		data_flag_convert(t_var *var);
int		width_noflags_noprec(t_var *var);
int		width_minus_noprec(t_var *var);
int		width_zero_noprec(t_var *var);
int		width_prec_str(t_var *var);
int		width_noflags_prec(t_var *var);
int		width_minus_prec(t_var *var);
int		width_zero_prec(t_var *var);
int		width_minus_prec_str(t_var *var);
int		prec_width(t_var *var);
int		prec_width_str(t_var *var);
char	*join(char **s1, char **s2);

#endif 