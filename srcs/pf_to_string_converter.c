/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_string_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/17 12:14:36 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

static int	putstr_upto_n(char *s, int n);

/*
**	Prints a string. Returns its length.
**	Extracts conversion parameters directly from the 'spec' structure.
*/
int	to_string(va_list data_args, t_spec *spec)
{
	char	*str;
	int		len;

	set_width_arg(spec, data_args);
	set_prec_arg(spec, data_args);
	str = va_arg(data_args, char *);
	if (spec->prec == NOT_SET || spec->prec > (int)ft_strlen(str))
		spec->prec = ft_strlen(str);
	len = 0;
	if (spec->width > 0 && spec->prec < spec->width && \
		!test_bit(MINUS, spec->flags))
		len += putstr_repeat(" ", spec->width - spec->prec);
	len += putstr_upto_n(str, spec->prec);
	if (spec->width > 0 && spec->prec < spec->width && \
		test_bit(MINUS, spec->flags))
		len += putstr_repeat(" ", spec->width - spec->prec);
	return (len);
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
