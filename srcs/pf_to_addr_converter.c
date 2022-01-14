/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_addr_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/14 22:20:55 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"

static int	put_uint_base(unsigned long n, char *digits);
static void	put_n(unsigned long n, char *digits, unsigned long base, int *ret);

/*
**	Prints the address of a variable. Returns the amount of bytes written.
*/
int	to_address(va_list data_args, t_spec *spec)
{
	unsigned long	n;
	int				ret;
	int				width;

	set_width(spec, data_args, &width);
	ret = 0;
	ret += ft_putstr("0x");
	n = va_arg(data_args, unsigned long int);
	ret += put_uint_base(n, HEXDIGITSLOW);
	return (ret);
}

/*
**	It prints it unsigned integer argument in the base given by its 'digits'
**	string argument. It returns the number of characters written.
*/
int	put_uint_base(unsigned long n, char *digits)
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
**	Recursively prints it unsigned long integer argument in the base given by
**	its 'digits' string argument. It returns the number of characters written.
*/
void	put_n(unsigned long n, char *digits, unsigned long base, int *ret)
{
	if (n >= base)
		put_n(n / base, digits, base, ret);
	*ret += ft_putchar(*(digits + (n % base)));
}
