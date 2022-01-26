/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numeric.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/26 13:12:07 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_NUMERIC_H
# define PF_NUMERIC_H

/*
**	Macros for numeric bases:
*/
# define DECDIGITS		"0123456789"
# define OCTALDIGITS	"01234567"
# define HEXDIGITSLOW	"0123456789abcdef"
# define HEXDIGITSUPP	"0123456789ABCDEF"

/*
**	Macro for floating-point default precision:
*/
# define DEFAULT_PREC 6

/*
**	Type definition for floating-point numbers:
*/
typedef struct s_part {
	int					sign;
	unsigned long long	integer;
	unsigned long long	decimal;
}	t_float;

/*
**	Prototypes in pf_numeric_utils.c:
*/
int		put_ull_base(unsigned long long n, char *digits);
int		amount_digits(long long n, t_spec *spec);
int		putstr_repeat(char *s, int n);
void	cancel_flags(t_spec *spec);

/*
**	Prototypes in pf_numeric_utils2.c:
*/
void	set_num(t_spec *spec, va_list data_args, long long *num);
void	set_pad_char(t_spec *spec, char *pad_char);
t_float	split_float(long double num, int pos);

#endif