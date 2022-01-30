/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_float_converter2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:56:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/30 19:30:50 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"

static unsigned long long	set_amount(int pos);

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
	unsigned long long	decimal;
	int					sign;
	long double			one_point;

	sign = 1;
	if (num < 0)
		sign = -1;
	num *= sign;
	amount = set_amount(pos);
	trunc = (unsigned long long)num;
	if (num >= 2)
	{
		one_point = num - (trunc - 1);
		decimal = one_point * amount;
		if ((decimal % 10) > 0 && (pos < 6))
			decimal++;
		return ((t_float){sign, trunc, decimal - amount});
	}
	else if (num > 0)
		return ((t_float){sign, trunc, \
			(unsigned long long)((double)num * amount) - amount});
	else
		return ((t_float){sign, 0, 0});
}

static unsigned long long	set_amount(int pos)
{
	unsigned long long	amount;

	amount = 10;
	while (--pos > 0)
		amount *= 10;
	return (amount);
}
