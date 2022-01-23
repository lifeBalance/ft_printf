/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_string_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/23 16:09:58 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"

static int	putstr_upto_n(char *s, int n);
static int	putstr_aligned(char *str, t_spec *spec);

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the 'spec' structure.
*/
int	to_string(va_list data_args, t_spec *spec)
{
	char	*str;
	int		ret;

	str = va_arg(data_args, char *);
	ret = 0;
	if (test_bit(DOT, spec->flags) && !test_bit(PREC, spec->flags))
	{
		ret += putstr_repeat(" ", spec->width);
		return (ret);
	}
	if (str == NULL)
		ret += putstr_aligned("(null)", spec);
	else
		ret += putstr_aligned(str, spec);
	return (ret);
}

static int	putstr_aligned(char *str, t_spec *spec)
{
	int		ret;

	ret = 0;
	if (spec->prec < 0 || spec->prec > (int)ft_strlen(str))
		spec->prec = ft_strlen(str);
	if (spec->width > 0 && spec->prec < spec->width && \
		!test_bit(MINUS, spec->flags))
		ret += putstr_repeat(" ", spec->width - spec->prec);
	ret += putstr_upto_n(str, spec->prec);
	if (spec->width > 0 && spec->prec < spec->width && \
		test_bit(MINUS, spec->flags))
		ret += putstr_repeat(" ", spec->width - spec->prec);
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
	if (n < 0)
		ret += ft_putstr(s);
	i = 0;
	while (i < n)
	{
		ret += ft_putchar(s[i]);
		i++;
	}
	return (ret);
}
