/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/15 16:38:35 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

static void
put_n(unsigned long long n, char *digits, unsigned long long base, int *ret);

/*
**	It prints it unsigned long long integer argument in the base given by
**	its 'digits' string argument. It returns the number of characters written.
*/
int	put_ull_base(unsigned long long n, char *digits)
{
	unsigned long	base;
	int				ret;

	base = 0;
	ret = 0;
	while (digits[base])
		base++;
	put_n(n, digits, base, &ret);
	return (ret);
}

/*
**	Recursively prints it unsigned long long integer argument in the base
**	given by its 'digits' string argument. It returns the number of characters
**	written.
*/
void
	put_n(unsigned long long n, char *digits, unsigned long long base, int *ret)
{
	if (n >= base)
		put_n(n / base, digits, base, ret);
	*ret += ft_putchar(*(digits + (n % base)));
}

/*
**	Returns the amount of digits of the 'unsigned long long int' argument,
**	in the given 'unsigned long long' base.
*/
int	amount_of_digits(unsigned long long n, unsigned long long base)
{
	int	ret;

	ret = 1;
	while (n >= base)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

/*
**	Receives a string argument with the set of allowed digits in a given
**	numeric base. Returns the base or radix of that numeric base.
*/
void	set_base(unsigned long long *base, char *digits)
{
	*base = 0;
	while (digits[*base])
		(*base)++;
}
