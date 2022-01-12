/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_string_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/12 17:55:40 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

static void	set_width(t_spec *spec, va_list data_args, int *width);
static void	set_precision(t_spec *spec, va_list data_args, int *prec);
static int	putstr_repeat(char *s, int n);
static int	putstr_upto_n(char *s, int n);

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the 'spec' structure.
*/
int	to_string(va_list data_args, t_spec *spec)
{
	char	*str;
	int		prec;
	int		width;
	int		len;

	set_width(spec, data_args, &width);
	set_precision(spec, data_args, &prec);
	str = va_arg(data_args, char *);
	if (prec < 0)
		prec = ft_strlen(str);
	if (prec > (int)ft_strlen(str))
		prec = ft_strlen(str);
	len = 0;
	if (width > 0 && prec < width && !test_bit(MINUS, spec->flags))
		len += putstr_repeat(" ", width - prec);
	len += putstr_upto_n(str, prec);
	if (width > 0 && prec < width && test_bit(MINUS, spec->flags))
		len += putstr_repeat(" ", width - prec);
	return (len);
}

/*
**	Prints a string argument 'n' times.
**	Returns the amount of characters (bytes) written.
*/
static int	putstr_repeat(char *s, int n)
{
	int	ret;

	ret = 0;
	while (n--)
		ret += ft_putstr(s);
	return (ret);
}

/*
**	It prints up to 'n' characters from a string argument. It returns the
**	amount of written characters (bytes). 
*/
static int	putstr_upto_n(char *s, int n)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (i < n)
	{
		ret += ft_putchar(s[i]);
		i++;
	}
	return (ret);
}

/*
**	It returns the value of the width directive extracted from the 'spec'; if
**	it's not set, it returns '0'.
*/
static void	set_width(t_spec *spec, va_list data_args, int *width)
{
	if (test_bit(WIDTH_ARG, spec->digits))
		*width = va_arg(data_args, int);
	else if (test_bit(WIDTH, spec->digits))
		*width = spec->width;
	else
		*width = -1;
}

/*
**	If the precision directive is equal or greater than the string length,
**	it returns the length of the string. Otherwise returns the value of the
**	precision, which is stored in the 'spec' structure.
*/
static void	set_precision(t_spec *spec, va_list data_args, int *prec)
{
	if (test_bit(PREC_ARG, spec->digits))
		*prec = va_arg(data_args, int);
	else if (test_bit(PREC, spec->digits))
		*prec = spec->precision;
	else
		*prec = -1;
}
