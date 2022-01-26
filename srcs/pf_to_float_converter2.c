/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_float_converter2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:56:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/26 18:43:24 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"

/*
**	Splits a double argument into two parts:
**	- An integer part.
**	- A decimal part.
**	Returns both parts as a 't_float' (a struct with two members).
*/
t_float	split_float(long double num, int pos)
{
	unsigned long long	amount;
	unsigned long long	trunc;
	int					sign;
	long double			one_point;

	sign = 1;
	if (num < 0)
		sign = -1;
	num *= sign;
	amount = 10;
	while (--pos > 0)
		amount *= 10;
	trunc = (unsigned long long)num;
	if (num >= 2)
	{
		one_point = num - (trunc - 1);
		one_point *= amount;
		return ((t_float){sign, trunc, one_point - amount});
	}
	else if (num > 0)
		return ((t_float){sign, trunc, \
			(unsigned int)((double)num * amount) - amount});
	else
		return ((t_float){sign, 0, 0});
}
