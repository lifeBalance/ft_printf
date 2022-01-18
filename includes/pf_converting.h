/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converting.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/18 15:46:49 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_CONVERTING_H
# define PF_CONVERTING_H

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
	long long			integer;
	unsigned long long	decimal;
}	t_float;

/*
**	Function prototypes:
*/
void	set_width_arg(t_spec *spec, va_list data_args);
void	set_prec_arg(t_spec *spec, va_list data_args);
void	set_num(t_spec *spec, va_list data_args, long long *num);
void	set_base(long long *base, char *digits);
int		putstr_repeat(char *s, int n);
void	cancel_flags(t_spec *spec);
int		put_ull_base(unsigned long long n, char *digits);
int		amount_digits(long long n, long long base);
int		to_numeric(va_list data_args, t_spec *spec, char *digits);

int		handle_prec(long long n, long long base, t_spec *spec, char *digits);
int		align_left(long long n, long long base, t_spec *spec, char *digits);
int		align_right(long long n, long long base, t_spec *spec, char *digits);
int		print_split_sign(long long n, char *digits);

t_float	split_float(double num, int pos);

#endif