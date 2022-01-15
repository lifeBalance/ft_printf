/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converting.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:19:30 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/15 18:17:52 by rodrodri         ###   ########.fr       */
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
**	Function prototypes:
*/
void	set_width(t_spec *spec, va_list data_args, int *width);
void	set_precision(t_spec *spec, va_list data_args, int *prec);
void	set_num(t_spec *spec, va_list data_args, long long *num);
void	set_base(unsigned long long *base, char *digits);
int		putstr_repeat(char *s, int n);
void	cancel_flags(t_spec *spec);
int		put_ull_base(unsigned long long n, char *digits);
int		amount_of_digits(unsigned long long n, unsigned long long base);
int		to_numeric(va_list data_args, t_spec *spec, char *digits);

#endif